CXX=g++
CXXFLAGS=-c -std=c++17 -Wall -Wextra -Wpedantic -Wfloat-equal -O2

all: main

main: main.o solve.o utils.o
	$(CXX) bin/main.o bin/solve.o bin/utils.o -o equationSolver

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o bin/main.o

solve.o: solve.cpp
	$(CXX) $(CXXFLAGS) solve.cpp -o bin/solve.o


utils.o: utils.cpp
	$(CXX) $(CXXFLAGS) utils.cpp -o bin/utils.o

test.o: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o bin/test.o

debug: test.o solve.o utils.o
	$(CXX) bin/test.o bin/solve.o bin/utils.o -o test

clean:
	rm -rf bin/*.o equation
