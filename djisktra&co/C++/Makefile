CC = g++
CFLAGS = -g -Wall -O2
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
BIN = lab8

.PHONY: all clean

all: $(BIN)

build: lab8

lab8: Graph.o Node.o main.o Task1.o Task2.o Task3.o
	$(CC) $(CFLAGS) Graph.o Node.o main.o Task1.o Task2.o Task3.o -o lab8
  	
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
	
Graph.o: Graph.cpp
	$(CC) $(CFLAGS) -c Graph.cpp

Node.o: Node.cpp
	$(CC) $(CFLAGS) -c Node.cpp

Task1.o: Task1.cpp	
	$(CC) $(CFLAGS) -c Task1.cpp

Task2.o: Task2.cpp
	$(CC) $(CFLAGS) -c Task2.cpp

Task3.o: Task3.cpp
	$(CC) $(CFLAGS) -c Task3.cpp
	
clean:
	rm -f $(OBJ)
	rm -f $(BIN)
	rm -f *~
	rm -f *.out
