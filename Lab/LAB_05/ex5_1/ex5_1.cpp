// ex5-1.cpp
#include <iostream>
using std::cout;
using std::endl;
#include "Complex.h"

int main(){
    Complex a(1.0, 7.0), b(9.0, 2.0), c; 
    a.printComplex(); // output object a cout << " + ";
    b.printComplex(); // output object b cout << " = ";
    c = a.add(b); // invoke add function
    c.printComplex(); // output object c

    // create three Complex objects and assign to object c
    Complex d(c); // use copy constructor to create object d 
    d.printComplex(); // output object d
    return 0;
}