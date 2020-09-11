#include "command.h"
#include <future> // Async, future
#include <string>

class CLI{
  public:
    CLI();
    CLI(Command);
    // Execute the infinite loop
    // getCommand, logCommand, executeCommand
    void run();
    ~CLI();
  private:
    Command command;
    // Async get user input
    Command getNextCommand(){return command;}
    // Async write command to file
    void logCommand();
    // Async Execute command
    void executeCommand();
};
