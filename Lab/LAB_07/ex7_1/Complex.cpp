#include <iostream>
#include "Complex.h"
#include <math.h>

// Complex::Complex(){};
Complex::Complex(double r, double i){real = r;imag = i;}; 
Complex::Complex(const Complex& var){real = var.real; imag = var.imag;}; // copy constructor
// ~Complex(); // destructor
void printComplex(const Complex& c){
    if (c.imag >= 0) std::cout << c.real << "+" << c.imag << "i";
    else std::cout << c.real  << c.imag << "i";
}
void printMeg(const Complex& c1, const Complex& c2, char op){
    double r, i;
    if (op == '+'){
        r = c1.real + c2.real;
        i = c1.imag + c2.imag;
    }
    else if (op == '-'){
        r = c1.real - c2.real;
        i = c1.imag - c2.imag;
    }
    else if (op == '*'){
        r = c1.real*c2.real - c1.imag*c2.imag;
        i = c1.real*c2.imag + c1.imag*c2.real;
    }
    else if (op == '/'){
        double denominator = (pow(c2.real, 2) + pow(c2.imag, 2));
        r = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
        i = (c1.imag * c2.real - c1.real * c2.imag) / denominator;
    }
    else{
        std::cout << "Wrong operation" << std::endl;
        exit(1);
    }
    printComplex(Complex(r, i));
    std::cout << std::endl;
}
void Complex::setComplexNumber(double r, double i){
    real = r; 
    imag = i;
}
const Complex Complex::operator + (const Complex& c2){
    return Complex(real+c2.real, imag+c2.imag);
}
const Complex Complex::operator - (const Complex& c2){
    return Complex(real-c2.real, imag-c2.imag);
}
const Complex Complex::operator * (const Complex& c2){
    return Complex((real*c2.real - imag*c2.imag),(real*c2.imag + imag*c2.real));
}
const Complex Complex::operator / (const Complex& c2){
    double denominator = (pow(c2.real, 2) + pow(c2.imag, 2));
    double r = (real * c2.real + imag * c2.imag) / denominator;
    double i = (imag * c2.real - real * c2.imag) / denominator;
    return Complex(r, i);
}
const Complex Complex::operator - (){
    return Complex(-real, -imag);
}