#include <assert.h>
#include <string>

std::string substitute_in_string(std::string &src, std::string pat,
                                 std::string subst) {

  std::size_t found;
  while ((found = src.find(pat)) != std::string::npos) {
    src.replace(found, pat.length(), subst);
  }
  return src;
}
