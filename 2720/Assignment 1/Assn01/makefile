CC = gcc
CCFLAGS = -Wall -g

main: main.o Student.o Instructor.o
<Tab>$(CC) $(CCFLAGS) -o main main.o Student.cpp Instructor.cpp

main.o: main.cpp Student.h Instructor.h
<Tab>$(CC) $(CCFLAGS) -c main.cpp

Student.o: Student.cpp
<Tab>$(CC) $(CCFLAGS) -c Student.cpp

Instructor.o: Instructor.cpp Student.h
<Tab>$(CC) $(CCFLAGS) -c Instructor.cpp
