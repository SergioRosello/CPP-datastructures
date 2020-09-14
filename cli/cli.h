#pragma once
#include <signal.h>     /* signal, raise, sig_atomic_t */
#include "command.h"
#include <cstdlib>
#include <future> // Async, future
#include <string>
#include <istream>
#include <iostream>

class CLI{
  public:
    CLI();
    CLI(std::istream&);
    // Execute the infinite loop
    // getCommand, logCommand, executeCommand
    void run();
    ~CLI();
  private:
    std::istream& stream;
    Command command;

    void printTerminal();
    // Async get user input
    void getNextCommand();
    // Async write command to file
    void logCommand();
    // Async Execute command
    void executeCommand();
};
