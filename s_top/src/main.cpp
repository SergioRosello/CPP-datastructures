#include "../include/linuxParser.h"
#include "../include/process.h"
#include "../include/processParser.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
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
  pp.list_directories();
  // TODO: Test the _user method in Process and the get_user_name method
  cout << "Running processes: " << lp.running_processes() << endl;
  return 0;
}
