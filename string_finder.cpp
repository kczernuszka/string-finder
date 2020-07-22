#include "string_finder.h"

namespace string_finder {

const int DEFAULT_MIN_CHARS = 3;

StringFinder::StringFinder() : min_chars{DEFAULT_MIN_CHARS} {}

StringFinder::StringFinder(int min_chars) : min_chars{min_chars} {}

std::vector<std::string> StringFinder::find_strings(std::string file) {
  std::ifstream buffer{file, std::ios::binary};
  std::vector<std::string> stringsVector;
  char c;
  while(buffer.get(c)) {
    if(isprint(c)) {
      buffer.putback(c);
      std::string str = get_string(buffer);
      if(!str.empty())
        stringsVector.push_back(str);
    }
  }
  return stringsVector;
}

std::string StringFinder::get_string(std::ifstream& buffer) {
  std::string str;
  char c;
  while(buffer.get(c) && isprint(c))
    str.push_back(c);
  str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
  if(str.size() >= min_chars)
    return str;
  else
    return {};
}

}  // namespace string_finder
