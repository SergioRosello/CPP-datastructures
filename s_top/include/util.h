#include <iostream>
#include <string>

std::string substitute_in_string(std::string &, std::string, std::string);

struct Time {
  int hours;
  int minutes;
  int seconds;
};

// Operator overload Time struct

std::ostream &operator<<(std::ostream &os, const Time &T) {
  os << T.hours << "/" << T.minutes << "/" << T.seconds;
  return os;
}
