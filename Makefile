CC=g++
CFLAGS=-c -std=c++17

all: main

main: main.o solve.o utils.o
	$(CC) bin/main.o bin/solve.o bin/utils.o -o equationSolver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o bin/main.o

solve.o: solve.cpp
	$(CC) $(CFLAGS) solve.cpp -o bin/solve.o


utils.o: utils.cpp
	$(CC) $(CFLAGS) utils.cpp -o bin/utils.o

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp -o bin/test.cpp

debug: test.o solve.o utils.o
	$(CC) test.o solve.o utils.o -o test

clean:
	rm -rf *.o equation
