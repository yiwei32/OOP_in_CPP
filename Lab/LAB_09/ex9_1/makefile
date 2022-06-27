ex9_1: main.o Point2D.o Point4D.o
	g++ -o ex9_1 main.o Point2D.o Point4D.o
main.o: main.cpp 
	g++ -c main.cpp
Point2D.o: Point2D.cpp 
	g++ -c Point2D.cpp
Point4D.o: Point4D.cpp 
	g++ -c Point4D.cpp

clean:
	rm -rf *.o