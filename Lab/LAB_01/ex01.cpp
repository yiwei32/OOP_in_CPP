#include <iostream>
#include <string>
#include <stdlib.h>
#include "utils1-1.h"
using namespace std;

int main(int argc, char *argv[]){
    Complex::Cplex a, b; // use struct named Cplex under namespace 
    Complex::ReadTextFile(argv[1], a, b); // process text file
    Complex::Cplex results[4]; // store the results of diff. operation 
    results[0] = Complex::ComplexOperation(a, b, '+');
    results[1] = Complex::ComplexOperation(a, b, '-');
    results[2] = Complex::ComplexOperation(a, b, '*');
    results[3] = Complex::ComplexOperation(a, b, '/');
    Complex::PrintComplex(argv[2], results); // print the results on file.
    return 0;
}