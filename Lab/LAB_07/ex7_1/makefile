ex7_1: main.o Complex.o
	g++ -o ex7_1 Complex.o main.o
main.o: main.cpp Complex.h
	g++ -c main.cpp
Complex.o: Complex.cpp Complex.h
	g++ -c Complex.cpp
clean:
	rm *.o
