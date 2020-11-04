#include "../include/processParser.h"

// Collect all the processes in the system
ProcessParser::ProcessParser() {}

namespace fs = std::filesystem;

void ProcessParser::get_processes() {
  std::string path = kProcDirectory;
  std::regex pid("/proc/([0-9]+)");
  for (const auto &entry : fs::directory_iterator(path)) {
    std::smatch sm;
    std::string filename = entry.path().string();
    if (std::regex_match(filename, sm, pid)) {
      PIDs.push_back(sm[1].str());
    }
  }
}
