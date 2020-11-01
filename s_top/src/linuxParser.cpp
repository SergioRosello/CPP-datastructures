#include "../include/linuxParser.h"
#include <iostream>

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
        if (key.compare("PRETTY_NAME")) {
          substitute_in_string(value, "_", " ");
          return value;
        }
      }
    };
  }
  return "INVALID";
}
