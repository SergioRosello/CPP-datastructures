#include "../include/linuxParser.h"
#include "../include/process.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  LinuxParser lp;
  cout << "OS release: " << lp.os_release() << endl;
  cout << "Uptime: " << lp.uptime() << endl;
  return 0;
}
