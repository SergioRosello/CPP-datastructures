#include "../include/util.h"
#include <assert.h>
#include <string>

void v_substitute_in_string(std::string &src, std::string pat,
                            std::string subst) {

  std::size_t found;
  while ((found = src.find(pat)) != std::string::npos) {
    src.replace(found, pat.length(), subst);
  }
}

std::string substitute_in_string(std::string &src, std::string pat,
                                 std::string subst) {

  std::size_t found;
  while ((found = src.find(pat)) != std::string::npos) {
    src.replace(found, pat.length(), subst);
  }
  return src;
}

std::ostream &operator<<(std::ostream &os, const Time &T) {
  os << T.hours << ":" << T.minutes << ":" << T.seconds;
  return os;
}

Time::Time() {
  this->hours = 0;
  this->minutes = 0;
  this->seconds = 0;
}

Time::Time(int uptime) {
  int tmp_minutes = int(uptime / 60);
  hours = int(tmp_minutes / 60);
  minutes = tmp_minutes % 60;
  seconds = int(uptime % 60);
}
