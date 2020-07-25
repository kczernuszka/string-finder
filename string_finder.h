#ifndef STRINGFINDER_STRINGFINDER_H
#define STRINGFINDER_STRINGFINDER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

namespace string_finder {

class StringFinder {
 public:
  StringFinder() = default;

  std::vector<std::string> findStrings(std::string file);
  void setMinChars(int min_chars);
  void setFilter(std::string);
 
 private:
  int min_chars{3};
  std::string grep_chars;

  std::string getString(std::ifstream& buffer);
  bool stringIsMatched(std::string str);
};

}  // namespace string_finder

#endif  // STRINGFINDER_STRINGFINDER_H
