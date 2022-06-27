ex5_3: vec.o main.o
	g++ -o ex5_3 vec.o main.o
vec.o: vec.cpp vec.h
	g++ -c vec.cpp
main.o: main.cpp vec.h
	g++ -c main.cpp
clean:
	rm *.o
