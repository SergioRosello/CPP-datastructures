#include "../include/processParser.h"

// Collect all the processes in the system
ProcessParser::ProcessParser() {}

namespace fs = std::filesystem;

void ProcessParser::list_directories() {
  std::string path = kProcDirectory;
  for (const auto &entry : fs::directory_iterator(path))
    std::cout << entry.path() << std::endl;
}
