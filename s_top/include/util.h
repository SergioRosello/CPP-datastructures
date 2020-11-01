#pragma once
#include <iostream>
#include <string>

std::string substitute_in_string(std::string &, std::string, std::string);

class Time {
public:
  int hours;
  int minutes;
  int seconds;

  Time();
  Time(int seconds);
};

// Operator overload Time struct

std::ostream &operator<<(std::ostream &os, const Time &T);
