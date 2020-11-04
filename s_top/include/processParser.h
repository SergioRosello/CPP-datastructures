#include "../include/util.h"
#include <filesystem>
#include <vector>
#include <iostream>
#include <string>
#include <regex>
// Collects a list of the currently running processes
// Updates the processes, and creates new processes if
//    the system has created new processes
class ProcessParser {
public:
  std::vector<std::string> PIDs;
  void map_processes();
  ProcessParser();
  void get_processes();
};
