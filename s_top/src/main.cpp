#include "../include/linuxParser.h"
#include "../include/process.h"
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
  return 0;
}
