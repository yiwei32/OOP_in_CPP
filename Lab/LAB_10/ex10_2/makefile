ex10_2: main.o student.o school.o
	g++ -o ex10_2 main.o student.o school.o
main.o: main.cpp
	g++ -c main.cpp
student.o: student.cpp
	g++ -c student.cpp
school.o: school.cpp
	g++ -c school.cpp

clean:
	rm -rf *.o
	rm ex10_2