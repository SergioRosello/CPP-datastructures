#include "../include/linuxParser.h"
#include "../include/process.h"
#include "../include/processParser.h"
#include <iostream>

using namespace std;

int main() {
  LinuxParser lp;
  cout << "OS release: " << lp.os_release() << endl;
  cout << "Uptime: " << lp.uptime() << endl;
  cout << "CPU usage: " << lp.cpu_usage() << endl;
  cout << "RAM usage: " << lp.ram() << endl;
  cout << "Total Processes: " << lp.total_processes() << endl;
  cout << "Running processes: " << lp.running_processes() << endl;
  // Process parser that gets all current rulling processes and creates
  // the processes
  ProcessParser pp;
  while (true) {
    pp.get_processes();

    std::vector<Process> processes;
    for (auto process : pp.PIDs) {
      // Create a process object
      //TODO: Before creating, check wheather the process already exists, with it's specific pid
      //then, if it doesn't exist, create the new one. 
      //If the process exists, update it's fields.
      Process p(process);
      processes.push_back(p);
    }

    for (auto process : processes) {
      std::cout << "Process ID: " << process.get_pid()
                << " User: " << process.get_user()
                << " Command: " << process.get_command()
                << " Mem usage: " << process.get_memory_usage() << std::endl;
    }
  }
  return 0;
}
