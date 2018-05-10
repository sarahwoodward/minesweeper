CC=g++
CXXFLAGS=-g --std=c++11
WIDGET=term.o application.o keystream.o widget.o
TARGETS=main

all: $(TARGETS)
main: $(WIDGET)  cell.o minesweeper.o main.o
cell.o: cell.h cell.cpp
minesweeper.o: minesweeper.h minesweeper.cpp


clean:
	rm -f $(TARGETS) *.o
