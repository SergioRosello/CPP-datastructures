#include "../include/util.h"
#include <filesystem>
#include <iostream>
#include <string>
// Collects a list of the currently running processes
// Updates the processes, and creates new processes if
//    the system has created new processes
class ProcessParser {
private:
public:
  void map_processes();
  ProcessParser();
  void list_directories();
};
