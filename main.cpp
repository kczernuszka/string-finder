#include "string_finder.h"

int main(int argc, char *argv[]) {
  string_finder::StringFinder string_finder;
  if(argv[1]) {
    std::string file{argv[1]};
    auto stringsVector = string_finder.find_strings(argv[1]);
    for(auto &string: stringsVector) {
        std::cout << string << std::endl;
    }
  }
  return 0;
}
