// utils1-1.h
#ifndef UTILS1_1_H
#define UTILS1_1_H

namespace Complex{
    typedef struct{
        double real;
        double image;
    }Cplex;
    const double pi = 3.1416;
    void ReadTextFile(std::string filename, Cplex &a, Cplex &b);
    Cplex ComplexOperation(const Cplex &a, const Cplex &b, const char op);
    void PrintComplex(std::string filename, Cplex* results);
    // void lineToCplex(std::string line, Complex::Cplex &cplex);
};
#endif