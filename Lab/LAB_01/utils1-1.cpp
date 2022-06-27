#include <iostream>
#include <fstream>
#include "utils1-1.h"
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

void lineToCplex(std::string line, Complex::Cplex &cplex){
    if (line[0]!='-'){
        line = '+' + line;
    }
    size_t found = line.find_last_of("+-");
    cplex.real = stod(line.substr(0,found));
    cplex.image = stod(line.substr(found, line.length()-found-1));
};

void Complex::ReadTextFile(std::string filename, Complex::Cplex &a, Complex::Cplex &b){
    
    std::ifstream file(filename);
    if (!file.is_open()){
        std::cout << "Error file open" << std::endl;
    }
    std::string line;
    std::getline(file, line);
    lineToCplex(line, a);
    std::getline(file, line);
    lineToCplex(line, b);
    file.close();
};

Complex::Cplex Complex::ComplexOperation(const Complex::Cplex &a, const Complex::Cplex &b, char op){

    Complex::Cplex res;
    if (op == '+'){
        res.real = a.real + b.real;
        res.image = a.image + b.image;
    }
    else if (op == '-'){
        res.real = a.real - b.real;
        res.image = a.image - b.image;
    }
    else if (op == '*'){
        res.real = a.real*b.real - a.image*b.image;
        res.image = a.real*b.image + a.image*b.real;
    }
    else if (op == '/'){
        // 
        double denominator = (std::pow(b.real, 2) + std::pow(b.image, 2));
        res.real = (a.real * b.real + a.image * b.image) / denominator;
        res.image = (a.image * b.real - a.real * b.image) / denominator;
    }
    else{
        std::cout << "Wrong operation" << std::endl;
        exit(1);
    }
    return res;
};

void Complex::PrintComplex(std::string filename, Complex::Cplex* results){
    std::ofstream file(filename);
    if (!file.is_open()){
        std::cout << "Error file open" << std::endl;
    }
    file << std::fixed << std::setprecision(3);
    // 4 operations, +, -, *, /
    for (int i = 0; i < 4; ++i){
        if (results[i].image >= 0){
            file << results[i].real << '+' << results[i].image << 'i' << std::endl;
        }
        else{
            file << results[i].real << results[i].image << 'i' << std::endl;
        }
    }
    file.close();
};

