ex9_2: main.o Package.o
	g++ -o ex9_2 main.o Package.o
main.o: main.cpp 
	g++ -c main.cpp
Package.o: Package.cpp
	g++ -c Package.cpp

clean:
	rm -rf *.o