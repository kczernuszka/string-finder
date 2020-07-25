#include "cmd_parser.h"

namespace string_finder {

CmdParser::CmdParser(int argc, char **argv) : argc{argc}, argv{argv} {}

std::unique_ptr<Arguments> CmdParser::getArguments() {
  auto vm = createOptions();
  return getValues(vm);
}

po::variables_map CmdParser::createOptions() {
  po::options_description desc("Cmd options");
  desc.add_options()
      ("number,n", po::value<int>()->default_value(0),
       "Show strings with minimum n chars")
      ("filter,f", po::value<std::string>(), "Filter results with substring")
      ("input-files", po::value<std::vector<std::string>>()->multitoken(),
       "Input files");

  po::positional_options_description p;
  p.add("input-files", -1);

  po::variables_map vm;
  store(po::command_line_parser(argc, argv).options(desc).positional(p).run(),
        vm);
  notify(vm);

  return vm;
}

std::unique_ptr<Arguments> CmdParser::getValues(po::variables_map vm) {
  auto arguments = std::make_unique<Arguments>();
  if(vm.count("number"))
    arguments->min_chars = vm["number"].as<int>();
  if(vm.count("filter"))
    arguments->grep_chars = vm["filter"].as<std::string>();
  if(vm.count("input-files"))
    arguments->files = vm["input-files"].as<std::vector<std::string>>();
  return arguments;
}

}  // namespace string_finder
