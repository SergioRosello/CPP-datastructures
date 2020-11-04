#pragma once
#include "../include/util.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Process {
private:
  string pid;
  std::string user;
  int cpu_usage;
  int memory_usage;
  int time;
  std::string command;

  std::string _user();
  int _cpu_usage();
  int _memory_usage();
  int _time();
  int _command();

  string get_user_name(int);

public:
  Process();
  // Given the process ID, get it's information
  Process(string pid);

  string get_pid();
  string get_user();
  string get_command();
  int get_cpu_usage();
  int get_memory_usage();
  int get_time();

  void set_pid(string pid);
  void set_user(string user);
  void set_command(string command);
  void set_cpu_usage(int cpu_usage);
  void set_memory_usage(int memory_usage);
  void set_time(int time);
};
