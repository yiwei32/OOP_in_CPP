// lab3-1-1.cpp
#include <iostream>
using namespace std;

int main() {
    double a = 1.34;
    double *pa = &a;
    cout << "a = " << a << endl; // 1.34
    cout << "&a = " << &a << endl; // addr of a
    // cout << "*a = " << *a << endl; // error, a is a double, cannot dereference
    cout << "pa = " << pa << endl; // addr of a
    cout << "&pa = " << &pa << endl; // addr of addr of a
    cout << "*pa = " << *pa << endl; // 1.34
    *pa = 6.5;
    cout << "a = " << a << endl; // 6.5
    cout << "*pa = " << *pa << endl; // 6.5
    return 0; 
}