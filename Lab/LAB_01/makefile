lab1-1prog: lab1-1.o main.o
	g++ -o lab1-1prog lab1-1.o 1-1main.o
lab1-1.o: lab1-1.cpp lab1-1.h
	g++ -c lab1-1.cpp
main.o: 1-1main.cpp lab1-1.h
	g++ -c 1-1main.cpp
clean:
	rm *.o