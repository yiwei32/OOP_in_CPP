// lab7-1-2.cpp
#include <iostream>
using std::cout;
using std::endl;
int min(int n1, int n2){
    int tmp = n1 < n2 ? n1 : n2;
    return tmp; 
};
int min(int n1, int n2, int n3){
    int tmp = min(n1,n2);
    return min(tmp,n3);
};
int main(){
    cout << "min(4,3) = " << min(4,3) << endl; cout << "min(1,3,2) = " << min(1,3,2) << endl;
    return 0; 
}


/*
Notice that, the function overloading can be achieved by different data type and different number of argument list, 
but it cannot be different return type. For example, int sum(int *array, int len) 
and double sum(int *array, int len) cannot exist at the same time.
*/