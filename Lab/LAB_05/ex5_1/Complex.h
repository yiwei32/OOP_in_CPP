// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
/* Write class definition for Complex including constructors*/
class Complex{
private:
    double real;
    double imag;
public:
    Complex(); // default constructor
    Complex(double r, double i); 
    Complex(const Complex &var); // copy constructor
    // ~Complex(); // destructor
    void printComplex();
    Complex add(Complex cplx);
};
#endif