#include "../include/process.h"

Process::Process(){};

// Construct the process with the fields already initialised

string Process::get_pid() { return this->pid; }
string Process::get_user() { return this->user; }
string Process::get_command() { return this->command; }
int Process::get_cpu_usage() { return this->cpu_usage; }
int Process::get_memory_usage() { return this->memory_usage; }
int Process::get_time() { return this->time; }

void Process::set_pid(std::string pid) { this->pid = pid; }
void Process::set_user(string user) { this->user = user; }
void Process::set_command(string command) { this->command = command; }
void Process::set_cpu_usage(int cpu_usage) { this->cpu_usage = cpu_usage; }
void Process::set_memory_usage(int memory_usage) {
  this->memory_usage = memory_usage;
}
void Process::set_time(int time) { this->time = time; }

// Construct the Process object based on it's PID
Process::Process(std::string pid) : pid{pid} {
  _user();
  _command();
  _cpu_usage();
  _memory_usage();
  _time();
}

std::string Process::_user() {
  bool found_key = false;
  std::string line;
  std::string user_name;
  int user_id = -1;
  std::ifstream file(kProcDirectory + pid + "/" + kStatusFilename);
  if (file.is_open()) {
    std::string key;
    int value;
    std::string line;
    while (!found_key && std::getline(file, line)) {
      std::istringstream linestream(line);
      linestream >> key >> value;
      if (key.compare("Uid:") == 0) {
        user_id = value;
        found_key = true;
      }
    }
    user_name = get_user_name(user_id);
  }
  return user_name;
}

// TODO: Finish this method
std::string Process::get_user_name(int uid) {
  // Parse etc/passwd to find the user id and collect the User name
  std::ifstream file(kPasswordPath);
  if (file.is_open()) {
    std::string line;
    std::getline(file, line);
    v_substitute_in_string(line, ":", " ");
    std::cout << "Line: " << line << std::endl;
    //TODO: Complete method to parse and obtain username.
    //Continue development from here
  }
  return string();
}

int Process::_cpu_usage() { return int(); }
int Process::_memory_usage() { return int(); }
int Process::_time() { return int(); }
int Process::_command() { return int(); }
