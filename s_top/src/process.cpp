#include "../include/process.h"

Process::Process(){};

int Process::get_pid() { return this->pid; }
string Process::get_user() { return this->user; }
string Process::get_command() { return this->command; }
int Process::get_cpu_usage() { return this->cpu_usage; }
int Process::get_memory_usage() { return this->memory_usage; }
int Process::get_time() { return this->time; }
void Process::set_pid(int pid) { this->pid = pid; }
void Process::set_user(string user) { this->user = user; }
void Process::set_command(string command) { this->command = command; }
void Process::set_cpu_usage(int cpu_usage) { this->cpu_usage = cpu_usage; }
void Process::set_memory_usage(int memory_usage) {
  this->memory_usage = memory_usage;
}
void Process::set_time(int time) { this->time = time; }
