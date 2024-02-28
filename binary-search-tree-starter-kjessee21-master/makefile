EXE = bin/BinaryTreeTest
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

all:$(EXE)
.PHONY: all run test memcheck clean

run:$(EXE)
	@echo "Press enter to run the test driver"
	@read DUMMY
	@-$(EXE)
	@echo "Press enter to memcheck the test driver"
	@read DUMMY
	$(MEMCHECK) $(EXE)

test: $(EXE)
	$(EXE)

memcheck: $(EXE)
	$(MEMCHECK) $(EXE)

clean:
	mkdir -p obj
	mkdir -p bin
	rm obj/*
	rm bin/*
	rmdir obj
	rmdir bin

$(EXE):obj/BinaryTreeTest.o
	mkdir -p bin
	$(CC) $(OPTIONS) $(DEBUG) -o $(EXE) obj/BinaryTreeTest.o

obj/BinaryTreeTest.o:src/BinaryTreeTest.cpp inc/BinaryTree.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/BinaryTreeTest.o -c  -I inc/ src/BinaryTreeTest.cpp
