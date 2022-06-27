// lab3-2-1.cpp
#include <iostream>
using namespace std;
int main() {
    int a = 1024;
    int &refa = a;
    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl; // addr of a
    // cout << "*a = " << *a << endl; // error
    cout << "refa = " << refa << endl; 
    cout << "&refa = " << &refa << endl;  // addr of refa, same as addr of a, since refa is reference
    // cout << "*refa = " << *refa << endl; // error
    return 0; 
}