CXX = g++
CXXFLAGS = -g
OBJ = main.o string_finder.o

string_finder: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

string_finder.o: string_finder.cpp string_finder.h
	$(CXX) $(CXXFLAGS) string_finder.cpp -c -o string_finder.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o