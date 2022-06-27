#include <iostream>
#include "vec.h"

using std::cout;
using std::endl;

#define INPUTSIZE 20

void readNums(int *arr, int& dim){
    cout << "Enter numbers:" << endl;
    
    int count = 0;
    int temp;
    // without the if (temp == -1) statement, the loop won't stop unless enter "ctrl + d"
    // which means entering "EOF"
    while (std::cin >> temp){
        if (temp == -1) break;
        arr[count++] = temp;
    }
    dim = count;
};

int main() {
    int *array1,*array2;
    int dim1, dim2;
    /* read numbers from screen for array1 and array2 */ 
    array1 = new int[INPUTSIZE];
    array2 = new int[INPUTSIZE];
    /* enter -1 to end input */ 
    /* return the dimension of each array */
    readNums(array1, dim1);
    readNums(array2, dim2);
    Vec vec1(array1,dim1);
    Vec vec2;
    vec2.assign(array2, dim2);
    cout << "vec1(sorted): ";
    vec1.sort();

    vec1.printVec();
    cout << "vec2(sorted): ";
    vec2.sort();
    vec2.printVec();
    bool isEqual = vec1.isEqual(vec2);
    /* print out the message if vec1 and vec2 are the same or not*/
    if (isEqual) cout << "vec1 and vec2 are the same" << endl;
    else cout << "vec1 is not equal to vec2" << endl;
    Vec vec3;
    vec3.unionSet(vec1,vec2);
    cout << "vec3: ";
    vec3.printVec();
    vec3.sort();
    cout << "vec3(sorted): ";
    vec3.printVec();
    // vec3 is union set of vec1 and vec2
    cout << "Min in vec1 and vec2: " << vec3.min() << endl; cout << "Max in vec1 and vec2: " << vec3.max() << endl;
    int target = 10;
    bool findInVec = vec3.find(target);
    /* print out the message if target is found or not. */
    if (findInVec) cout << "target found!" << endl;
    else cout << "Target " << target << " cannot be found in vec1 or vec2" << endl;
    Vec vec4;
    vec4 = vec3.inpendetSet();
    cout << "vec4: ";
    vec4.printVec();
    delete [] array1;
    delete [] array2;
    return 0;
}