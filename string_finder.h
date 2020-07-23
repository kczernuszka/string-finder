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
  StringFinder(int min_char);
  StringFinder(std::string grep_char);
  StringFinder(std::string grep_char, int min_char);

  std::vector<std::string> find_strings(std::string file);
 
 private:
  int min_chars{3};
  std::string grep_chars;

  std::string get_string(std::ifstream& buffer);
  bool string_is_matched(std::string str);
};

}  // namespace string_finder

#endif  // STRINGFINDER_STRINGFINDER_H
