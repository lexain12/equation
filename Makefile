CC=g++
CFLAGS=-c -std=c++17

all: main

main: main.o solve.o utils.o
	$(CC) main.o solve.o utils.o -o equationSolver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

solve.o: solve.cpp
	$(CC) $(CFLAGS) solve.cpp


utils.o: utils.cpp
	$(CC) $(CFLAGS) utils.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

debug: test.o solve.o utils.o
	$(CC) test.o solve.o utils.o -o test

clean:
	rm -rf *.o equation
