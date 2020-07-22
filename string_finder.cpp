#include "string_finder.h"

namespace string_finder {

std::vector<std::string> StringFinder::find_strings(std::string file) {
  std::ifstream buffer{file, std::ios::binary};
  std::vector<std::string> stringsVector;
  char c;
  while(buffer.get(c)) {
    if(isprint(c)) {
      buffer.putback(c);
      stringsVector.push_back(get_string(buffer));
    }
  }
  return stringsVector;
}

std::string StringFinder::get_string(std::ifstream& buffer) {
  std::string str;
  char c;
  while(buffer.get(c) && isprint(c))
    str.push_back(c);
  return str;
}

}  // namespace string_finder
