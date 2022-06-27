// Complex.cpp
#include <iostream>
#include "Complex.h"
// Member-function definitions for class Complex.

Complex::Complex(){
    real = 0.0;
    imag = 0.0;
};
Complex::Complex(const Complex &var){
    real = var.real;
    imag = var.imag;
};
Complex::Complex(double r, double i){
    real = r;
    imag = i;
};

void Complex::printComplex(){
    if (imag >= 0){
        std::cout << real << "+" << imag <<"i"<< std::endl;
    }
    else{
        std::cout << real << imag << "i" << std::endl;
    }
};
Complex Complex::add(Complex cplx){
    cplx.real += real;
    cplx.imag += imag;
    return cplx;
};