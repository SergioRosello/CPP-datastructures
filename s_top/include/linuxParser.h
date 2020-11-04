#pragma once
#include "../include/util.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

const std::string kCpuinfoFilename{"/cpuinfo"};
const std::string kUptimeFilename{"/uptime"};
const std::string kMeminfoFilename{"/meminfo"};
const std::string kVersionFilename{"/version"};
const std::string kOSPath{"/etc/os-release"};

class LinuxParser {
public:
  LinuxParser();
  std::string cmd();
  float cpu_usage();
  std::string status();
  int total_processes();
  int running_processes();
  float ram();
  std::string os_release();
  Time uptime();
};
