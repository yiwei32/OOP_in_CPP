#include <iostream>
#include "utils1-1.h"
using namespace Complex;

// ex1-1.cpp
int main(int argc, char *argv[]){
    Cplex a, b; // use struct named Cplex under namespace Complex ReadTextFile(argv[1], a, b); // process text file
    Cplex results[4]; // store the results of diff. operation 
    results[0] = ComplexOperation(a, b, '+');
    results[1] = ComplexOperation(a, b, '-');
    results[2] = ComplexOperation(a, b, '*');
    results[3] = ComplexOperation(a, b, '/');
    PrintComplex(argv[2], results); // print the results on file.
    return 0;
}