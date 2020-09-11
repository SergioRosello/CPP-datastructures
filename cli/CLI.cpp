#include "cli.h"

CLI::CLI(){}
CLI::CLI(Command com) :command{com} {}

CLI::~CLI(){}

void CLI::run(){
  while(true){
    getNextCommand();
    logCommand();
    executeCommand();
  }
}
