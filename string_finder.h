#ifndef STRINGFINDER_STRINGFINDER_H
#define STRINGFINDER_STRINGFINDER_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

namespace string_finder {

class StringFinder {
 public:
  std::vector<std::string> find_strings(std::string file);
 
 private:
  std::string get_string(std::ifstream& buffer);
};

}  // namespace string_finder

#endif  // STRINGFINDER_STRINGFINDER_H
