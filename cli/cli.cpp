#include "cli.h"
#include <cstdio>
#include <fstream>

std::ostream& operator<<(std::ostream& output, Command& com){
  output << com.command;
  return output;
}

CLI::~CLI(){}

CLI::CLI(std::istream& stre) :stream{stre} {}


void CLI::run(){
  while(!stream.eof()){
    printTerminal();
    // Reference for ostream
    getNextCommand();
    //logCommand();
    executeCommand();
  }
}

void CLI::printTerminal(){
  std::cout << ">> ";
}
void CLI::getNextCommand(){
  std::getline(stream, command.command);
}

void CLI::executeCommand(){
  std::system(command.command.c_str());
}



