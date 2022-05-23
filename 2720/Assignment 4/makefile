CC = gcc
CCFLAGS = -Wall -g

main: main.o BinaryTree.o 
<Tab>$(CC) $(CCFLAGS) -o main main.o BinaryTree.cpp 

main.o: main.cpp BinaryTree.h 
<Tab>$(CC) $(CCFLAGS) -c main.cpp

BinaryTree.o: BinaryTree.cpp
<Tab>$(CC) $(CCFLAGS) -c BinaryTree.cpp
