// lab3-2-2.cpp
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
int main(){
    int a[10];
    srand(time(NULL));
    for (int i = 0;i < 10; i++){
        a[i] = rand()%20 + 10;
    }
    // int &refa; //error, ref must be initialized to an obj
    for (int i = 0; i < 10; i++){
        // refa = a[i];
        int &refa = a[i];
        cout << refa << " ";
    }
    cout << endl;
    return 0;
}
