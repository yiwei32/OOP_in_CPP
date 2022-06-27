// CPP program to illustrate
// concept of Virtual Functions
 
#include<iostream>
using namespace std;

int& func(int& i){
    int& b = i;
    return b;
}

int main(){
    int a = 10;
    int b = func(a);
    a = 5;
    cout << a << " " << b << endl;

    return 0;
}