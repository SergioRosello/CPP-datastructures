#pragma once
#include <string>

using namespace std;

class Process {
private:
  int pid;
  std::string user;
  std::string command;
  int cpu_usage;
  int memory_usage;
  int time;

public:
  Process();

  int get_pid();
  string get_user();
  string get_command();
  int get_cpu_usage();
  int get_memory_usage();
  int get_time();

  void set_pid(int pid);
  void set_user(string user);
  void set_command(string command);
  void set_cpu_usage(int cpu_usage);
  void set_memory_usage(int memory_usage);
  void set_time(int time);
};
