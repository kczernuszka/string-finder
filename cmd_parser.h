#ifndef STRINGFINDER_CMDPARSER_H
#define STRINGFINDER_CMDPARSER_H

#include <vector>
#include <string>

#include <boost/program_options.hpp>

namespace string_finder {

struct Arguments {
  std::vector<std::string> files;
  int min_chars;
  std::string grep_chars;
};

namespace po = boost::program_options;

class CmdParser {
 public:
  CmdParser(int argc, char **argv);
  std::unique_ptr<Arguments> getArguments();

 private:
  char **argv; int argc;

  po::variables_map createOptions();
  std::unique_ptr<Arguments> getValues(po::variables_map vm);
};

}  // namespace string_finder

#endif  // STRINGFINDER_STRINGFINDER_H
