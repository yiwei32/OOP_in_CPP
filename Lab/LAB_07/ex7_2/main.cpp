#include "my_string.h"
#include <iostream>
using namespace std;

int main() {
    mystring t1("New");
    cout << "t1=" << t1 << endl;
    mystring t2 = "York";
    cout << "t2=" << t2 << endl;
    mystring t3 = t1 + " " + t2; 
    cout << "t3=" << t3 << endl;
    if ( t1 <= t2 )
    cout << t1 << " is smaller than " << t2 << endl;
    else
        cout << t1 << " is bigger than " << t2 << endl;

    return 0; 
}
 