assn06:  p1.o Matrix.o 
	g++ -c -o -Wall -pedantic-errors -std=c++14 -g -O0 assn06 p1.o Matrix.o

p1.o: p1.cpp Matrix.h
	g++ -c -Wall -pedantic-errors -std=c++14 -g -O0 p1.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -c -Wall -pedantic-errors -std=c++14 -g -O0 Matrix.cpp

run: assn06
	./assn06

clean:
	rm -rf assn07
	rm -rf *.o