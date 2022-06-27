#include <iostream>
using namespace std;
#define MAX 20

class Vec{
    
public:
    int *nums;
    unsigned int capacity;
    unsigned int current;

    Vec(){
    nums = new int [1];
    nums[0] = 1;
    capacity = 1;
    current = 0;
    };
    void push_back(const int num){
    // check capacity
    if (current == capacity){
        capacity *= 2;
        int *arrNew = new int[capacity];
        // copy elements
        for (int i = 0; i < current; ++i){
            arrNew[i] = nums[i];
        }
        delete []nums;
        nums = arrNew;
    }
    nums[current++] = num;
};

    Vec sort(){
        return *this;
    }
};


void readNums(int *arr, int& dim){
    cout << "Enter numbers:" << endl;
    int count = 0;
    int temp;
    while (cin >> temp){
        if (temp == -1) break;
        arr[count++] = temp;
    }
    dim = count;
};

void printArray(int *arr, const int& dim){
    for (int i = 0; i < dim; ++i){
        cout << arr[i] << " ";
    }
    cout << "\n";
};

int main(){
    int arr[MAX];
    int dim;
    readNums(arr, dim);
    printArray(arr, dim);

    return 0;
}