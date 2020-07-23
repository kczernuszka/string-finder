#include "string_finder.h"

namespace string_finder {

StringFinder::StringFinder(int min_chars) : min_chars{min_chars} {}

StringFinder::StringFinder(std::string grep_chars) : grep_chars{grep_chars} {}

StringFinder::StringFinder(std::string grep_chars, int min_chars) 
    : grep_chars{grep_chars}, min_chars{min_chars} {}

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
  while(buffer.get(c) && isprint(c)) {
    str.push_back(c);
    if(string_is_matched(str))
      return str;
  }
  return {};
}

bool StringFinder::string_is_matched(std::string str) {
  if(str.size() >= min_chars) {
    if(grep_chars.empty() || str.find(grep_chars) != std::string::npos) {
      return true;
    }
  }
  return false;
}

}  // namespace string_finder
