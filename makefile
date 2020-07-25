CXX = g++
CXXFLAGS = -g
LDLIBS = -lboost_program_options
OBJ = main.o string_finder.o cmd_parser.o

string_finder: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

string_finder.o: string_finder.cpp string_finder.h
	$(CXX) $(CXXFLAGS) string_finder.cpp -c -o string_finder.o

cmd_parser.o: cmd_parser.cpp cmd_parser.h
	$(CXX) $(CXXFLAGS) cmd_parser.cpp -c -o cmd_parser.o $(LDLIBS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o