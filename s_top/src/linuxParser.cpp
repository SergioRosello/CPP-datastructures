#include "../include/linuxParser.h"

LinuxParser::LinuxParser(){};

Time LinuxParser::uptime() {
  // Open specific file and read the data required
  std::string line;
  std::ifstream file(kProcDirectory + kUptimeFilename);
  if (file.is_open()) {
    std::getline(file, line);
    std::size_t pos = line.find(".");
    int uptime = std::stoi(line.substr(0, pos), nullptr);
    // Call time constructor
    Time time(uptime);
    return time;
  }
  return Time();
}

float LinuxParser::ram() {
  int mem_total, used_ram, mem_available;
  float percentage_used;
  bool data_read = false, mem_total_read = false, mem_available_read = false;
  std::ifstream file(kProcDirectory + kMeminfoFilename);
  if (file.is_open()) {
    std::string line;
    std::string key;
    std::string value;
    while (!data_read && std::getline(file, line)) {
      std::istringstream linestream(line);
      if (linestream >> key >> value) {
        if (key.compare("MemTotal:") == 0) {
          mem_total = std::stoi(value, nullptr);
          mem_total_read = true;

        } else if (key.compare("MemAvailable:") == 0) {
          mem_available = std::stoi(value, nullptr);
          mem_available_read = true;
        }
      }
      if (mem_available_read && mem_total_read)
        data_read = true;
    }
    used_ram = mem_total - mem_available;
    percentage_used = (used_ram * 100.f) / mem_total;
  }
  return percentage_used;
}

float LinuxParser::cpu_usage() {
  int total_jiffies[2], work_jiffies[2];
  float work_over_period, total_over_period;
  std::string key;
  for (int i = 0; i < 2; ++i) {
    std::ifstream file(kProcDirectory + kStatFilename);
    if (file.is_open()) {
      int user, nice, system, idle, iowait, irq, softirq;
      std::string line;
      std::getline(file, line);
      std::istringstream linestream(line);
      linestream >> key >> user >> nice >> system >> idle >> iowait >> irq >>
          softirq;
      total_jiffies[i] = user + nice + system + idle + iowait + irq + softirq;
      work_jiffies[i] = user + nice + system;
    }
    usleep(1000000);
  }
  total_over_period = total_jiffies[1] - total_jiffies[0];
  work_over_period = work_jiffies[1] - work_jiffies[0];
  return work_over_period / total_over_period * 100.f;
}

int LinuxParser::total_processes() {
  std::ifstream file(kProcDirectory + kStatFilename);
  std::string line;
  int processes = -1;
  if (file.is_open()) {
    std::string key, value;
    while (std::getline(file, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key.compare("processes") == 0) {
        processes = std::stoi(value, nullptr);
      }
    }
  }
  return processes;
}
int LinuxParser::running_processes() {
  std::ifstream file(kProcDirectory + kStatFilename);
  std::string line;
  int processes = -1;
  if (file.is_open()) {
    std::string key, value;
    while (std::getline(file, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key.compare("procs_running") == 0) {
        processes = std::stoi(value, nullptr);
      }
    }
  }
  return processes;
}

// cmd line: /proc/cmdline
std::string LinuxParser::cmd() {
  // Open specific file and read the data required
  return std::string();
}

// Get OS Name
std::string LinuxParser::os_release() {
  std::string key;
  std::string value;
  std::string line;
  std::ifstream file(kOSPath);
  if (file.is_open()) {
    while (std::getline(file, line)) {
      substitute_in_string(line, " ", "_");
      substitute_in_string(line, "=", " ");
      substitute_in_string(line, "\"", " ");
      std::istringstream linestream(line);
      if (linestream >> key >> value) {
        if (key.compare("PRETTY_NAME") == 0) {
          substitute_in_string(value, "_", " ");
          return value;
        }
      }
    };
  }
  return "INVALID";
}
