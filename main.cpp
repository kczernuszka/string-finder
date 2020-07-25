#include "string_finder.h"
#include "cmd_parser.h"

int main(int argc, char *argv[]) {
  string_finder::CmdParser cmd_parser{argc, argv};
  string_finder::StringFinder string_finder;
  auto arguments = cmd_parser.getArguments();

  if(arguments->min_chars > 0)
    string_finder.setMinChars(arguments->min_chars);
  if(!arguments->grep_chars.empty())
    string_finder.setFilter(arguments->grep_chars);

  for(auto &file: arguments->files) {
    auto stringsVector = string_finder.findStrings(file);
    for(auto &string: stringsVector) {
      std::cout << string << std::endl;
    }
  }
  return 0;
}
