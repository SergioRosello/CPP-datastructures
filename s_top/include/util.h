#pragma once
#include <iostream>
#include <string>

void v_substitute_in_string(std::string &, std::string, std::string);

std::string substitute_in_string(std::string &, std::string, std::string);

// Constant Linux and Process file names
const std::string kProcDirectory{"/proc/"};
const std::string kCmdlineFilename{"/comm"};
const std::string kStatusFilename{"/status"};
const std::string kStatFilename{"/stat"};
const std::string kPasswordPath{"/etc/passwd"};

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
