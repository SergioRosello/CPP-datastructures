#include <string>

class Command{
  private:
    std::string command;
  public:
    Command(){};
    Command(std::string com):command{com}{};
    std::string getCommand(){return command;}
};

std::ostream& operator<<(std::ostream& output, std::string& command){
  output << command;
  return output;
}
