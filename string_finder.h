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

  std::vector<std::string> find_strings(std::string file);
  void set_min_chars(int min_chars);
  void set_filter(std::string);
 
 private:
  int min_chars{3};
  std::string grep_chars;

  std::string get_string(std::ifstream& buffer);
  bool string_is_matched(std::string str);
};

}  // namespace string_finder

#endif  // STRINGFINDER_STRINGFINDER_H
