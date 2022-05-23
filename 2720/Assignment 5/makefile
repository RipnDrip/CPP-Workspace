CC = gcc
CCFLAGS = -Wall -g

main: main.o Sorting.o 
<Tab>$(CC) $(CCFLAGS) -o main main.o Sorting.cpp 

main.o: main.cpp Sorting.h 
<Tab>$(CC) $(CCFLAGS) -c main.cpp

Sorting.o: Sorting.cpp
<Tab>$(CC) $(CCFLAGS) -c Sorting.cpp
