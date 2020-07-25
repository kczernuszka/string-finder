#include "string_finder.h"

namespace string_finder {

std::vector<std::string> StringFinder::findStrings(std::string file) {
  std::ifstream buffer{file, std::ios::binary};
  std::vector<std::string> stringsVector;
  char c;
  while(buffer.get(c)) {
    if(isprint(c)) {
      buffer.putback(c);
      std::string str = getString(buffer);
      if(!str.empty())
        stringsVector.push_back(str);
    }
  }
  return stringsVector;
}

void StringFinder::setMinChars(int min_chars) {
  this->min_chars = min_chars;
}

void StringFinder::setFilter(std::string filter) {
  this->grep_chars = filter;
}

std::string StringFinder::getString(std::ifstream& buffer) {
  std::string str;
  char c;
  while(buffer.get(c) && isprint(c)) {
    str.push_back(c);
    if(stringIsMatched(str))
      return str;
  }
  return {};
}

bool StringFinder::stringIsMatched(std::string str) {
  if(str.size() >= min_chars) {
    if(grep_chars.empty() || str.find(grep_chars) != std::string::npos) {
      return true;
    }
  }
  return false;
}

}  // namespace string_finder
