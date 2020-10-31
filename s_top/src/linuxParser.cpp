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
    int time = std::stoi(line.substr(0, pos), nullptr);
    std::cout << "TIME: " << time << std::endl;
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

Time parse_seconds(int time_s) {
  int seconds;
  int minutes = 60;
  int hours = 60 * 60;
  return Time();
}
