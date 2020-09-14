#include <iostream>
#include <istream>
#include <fstream>
#include "cli.h"

int main(int argc, char *argv[])
{
  if (argc == 2){
    std::ifstream str{argv[1]};
    CLI cli{str};
    cli.run();
  }else{
    CLI cli{std::cin};
    cli.run();
  }
  return 0;
}
