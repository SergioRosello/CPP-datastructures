#pragma once
#include "../include/util.h"
#include <fstream>
#include <sstream>
#include <string>

class Process {
private:
  std::string pid;
  std::string user;
  int cpu_usage;
  int memory_usage;
  int time;
  std::string command;

  void _user();
  void _cpu_usage();
  void _memory_usage();
  void _time();
  void _command();

  std::string get_user_name(std::string);

public:
  Process();
  // Given the process ID, get it's information
  Process(std::string pid);

  std::string get_pid();
  std::string get_user();
  std::string get_command();
  int get_cpu_usage();
  int get_memory_usage();
  int get_time();

  void set_pid(std::string pid);
  void set_user(std::string user);
  void set_command(std::string command);
  void set_cpu_usage(int cpu_usage);
  void set_memory_usage(int memory_usage);
  void set_time(int time);
};
