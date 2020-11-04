#include "../include/process.h"

Process::Process(){};

Process::Process(std::string pid) : pid{pid} {
  _user();
  _command();
  _cpu_usage();
  _memory_usage();
  _time();
}

// Construct the process with the fields already initialised

std::string Process::get_pid() { return this->pid; }
std::string Process::get_user() { return this->user; }
std::string Process::get_command() { return this->command; }
int Process::get_cpu_usage() { return this->cpu_usage; }
int Process::get_memory_usage() { return this->memory_usage; }
int Process::get_time() { return this->time; }

void Process::set_pid(std::string pid) { this->pid = pid; }
void Process::set_user(std::string user) { this->user = user; }
void Process::set_command(std::string command) { this->command = command; }
void Process::set_cpu_usage(int cpu_usage) { this->cpu_usage = cpu_usage; }
void Process::set_memory_usage(int memory_usage) {
  this->memory_usage = memory_usage;
}
void Process::set_time(int time) { this->time = time; }

// Construct the Process object based on it's PID

void Process::_user() {
  bool found_key = false;
  std::string user_id;
  std::ifstream file(kProcDirectory + pid + "/" + kStatusFilename);
  if (file.is_open()) {
    std::string key, value;
    std::string line;
    while (!found_key && std::getline(file, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key.compare("Uid:") == 0) {
        user_id.assign(value);
        found_key = true;
      }
    }
    this->user = get_user_name(user_id);
  }
}

std::string Process::get_user_name(std::string uid) {
  std::ifstream file(kPasswordPath);
  std::string user_name;
  if (file.is_open()) {
    bool found = false;
    std::string key, line, value, password;
    while (!found && std::getline(file, line)) {
      v_substitute_in_string(line, ":", " ");
      std::istringstream linestream(line);
      linestream >> value >> password >> key;
      if (key.compare(uid) == 0) {
        user_name = value;
        found = true;
      }
    }
  }
  return user_name;
}

// TODO: Finish this method
void Process::_cpu_usage() {
  // time.emplace_back(utime);
  // time.emplace_back(stime);
  // time.emplace_back(cutime);
  // time.emplace_back(cstime);
  // time.emplace_back(startTime);
  // time.emplace_back(clock);
}

void Process::_memory_usage() {
  std::ifstream file(kProcDirectory + this->pid + "/" + kStatusFilename);
  if (file.is_open()) {
    bool found = false;
    std::string key;
    int value;
    std::string line;
    while (!found && std::getline(file, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key.compare("VmSize:") == 0) {
        this->memory_usage = value;
        found = true;
      }
    }
  }
}

void Process::_time() {}

void Process::_command() {
  std::ifstream file(kProcDirectory + this->pid + "/" + kCmdlineFilename);
  if (file.is_open()) {
    std::getline(file, this->command);
  }
}
