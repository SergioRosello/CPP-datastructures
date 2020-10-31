#include "../include/util.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

const std::string kProcDirectory{"/proc/"};
const std::string kCmdlineFilename{"/cmdline"};
const std::string kCpuinfoFilename{"/cpuinfo"};
const std::string kStatusFilename{"/status"};
const std::string kStatFilename{"/stat"};
const std::string kUptimeFilename{"/uptime"};
const std::string kMeminfoFilename{"/meminfo"};
const std::string kVersionFilename{"/version"};
const std::string kOSPath{"/etc/os-release"};
const std::string kPasswordPath{"/etc/passwd"};

class LinuxParser {
public:
  LinuxParser();
  std::string cmd();
  std::string cpu_info();
  std::string status();
  std::string os_release();
  Time uptime();
};
