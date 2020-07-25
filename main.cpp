#include "string_finder.h"
#include "cmd_parser.h"

int main(int argc, char *argv[]) {
  string_finder::CmdParser cmd_parser{argc, argv};
  auto arguments = cmd_parser.getArguments();
  string_finder::StringFinder 
      string_finder{arguments->grep_chars, arguments->min_chars};
  for(auto &file: arguments->files) {
    auto stringsVector = string_finder.find_strings(file);
    for(auto &string: stringsVector) {
        std::cout << string << std::endl;
    }
  }
  return 0;
}
