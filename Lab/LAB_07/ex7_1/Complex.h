// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H
/* Write class definition for Complex including constructors*/
class Complex{
private:
    double real;
    double imag;
public:
    Complex(){}; // default constructor
    Complex(double r, double i); 
    Complex(const Complex &var); // copy constructor
    // ~Complex(); // destructor
    friend void printComplex(const Complex& c);
    friend void printMeg(const Complex& c1, const Complex& c2, char op);
    void setComplexNumber(double r, double i);
    const Complex operator + (const Complex& c2);
    const Complex operator - (const Complex& c2);
    const Complex operator * (const Complex& c2);
    const Complex operator / (const Complex& c2);
    const Complex operator - ();
    // Implementation with friend function
    // friend Complex operator + (const Complex& c1, const Complex& c2);
    // ...

};
#endif