#include <iostream>
#include "vec.h"
#include <limits>

Vec::Vec(){
    nums = new int [1];
    capacity = 1;
    current = 0;
};

Vec::Vec(int * const arr, const int dim){
    nums = new int[dim];
    for (int i = 0; i < dim; ++i){
        nums[i] = arr[i];
    }
    capacity = current = dim;;
    
};

// copy constructor
Vec::Vec(const Vec& old){
    int size = old.size();
    capacity = current = size;
    nums = new int[size];
    // copy elements from old
    for (int i = 0; i < size; ++i){
        nums[i] = old.nums[i];
    }
}

Vec::~Vec(){
    std::cout << "Destructor called" << std::endl;
    delete [] nums;
};

void Vec::assign(int * const arr, const int dim){
    delete [] nums;
    nums = new int [dim];
    for (int i = 0; i < dim; ++i){
        nums[i] = arr[i];
    }
    capacity = current = dim;
}; 

void Vec::push_back(int num){
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

void Vec::pop_back(){
    if (current == 0){
        std::cout << "Error: No element in vec. Tereminated." << std::endl;
        exit(1);
    }
    else{
        --current;
    }   
};

int Vec::size() const{
    return current;
};

void Vec::sort(){
    // insertion sort
    for (int i = 1; i < current; ++i){
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && key < nums[j]){
            nums[j+1] = nums[j];
            --j;
        }
        nums[j+1] = key;
    }
};

void Vec::printVec(){
    for (int i = 0; i < current; ++i){
        std::cout << nums[i] << " ";
    }
    std::cout << "\n";
};

// if pass "Vec vec2" (copy one) rather than pass by reference, 
// descturctor will be called twice.
// one is when isEqual return, and the other is when main return
// And the memory allocated to the pointer in vec2 is destructed by the first call
// thus, an error occurs at the second call because it was already destructed
// "error for object 0x7f8211c00690: pointer being freed was not allocated"
bool Vec::isEqual(const Vec& vec2){
    // different number of elements, return false
    if (current != vec2.current) return false;

    for (int i = 0; i < current; ++i){
        if (nums[i] != vec2.nums[i]) return false;
    }
    return true;
};

void Vec::unionSet(const Vec& vec1, const Vec& vec2){
    // TODO
    const int size1 = vec1.size();
    const int size2 = vec2.size();
    capacity = size1 + size2;
    current = 0;
    delete []nums;
    nums = new int[capacity];
    Vec vec1Sorted(vec1);
    vec1Sorted.sort();
    Vec vec2Sorted(vec2);
    vec2Sorted.sort();
    
    int p1 = 0;
    int p2 = 0;
    while (p1 < size1 && p2 < size2){
        if (vec1Sorted.nums[p1] < vec2Sorted.nums[p2]) push_back(vec1Sorted.nums[p1++]);
        else if (vec1Sorted.nums[p1] > vec2Sorted.nums[p2]) push_back(vec2Sorted.nums[p2++]);
        else{
            push_back(vec1Sorted.nums[p1]);
            p1++;
            p2++;
        }
    }
    // push remaining elements in one vector
    while (p1 < size1) push_back(vec1Sorted.nums[p1++]);
    while (p2 < size2) push_back(vec2Sorted.nums[p2++]);
};

int Vec::min(){
    if (current == 0){
        std::cout << "Error: No Element in Vector" << std::endl;
        exit(1);
    }

    int min = nums[0];
    for (int i = 1; i < current; ++i){
        if (nums[i] < min) min = nums[i];
    }
    return min;
};
int Vec::max(){
    if (current == 0){
        std::cout << "Error: No Element in Vector" << std::endl;
        exit(1);
    }

    int max = nums[0];
    for (int i = 1; i < current; ++i){
        if (nums[i] > max) max = nums[i];
    }
    return max;
};

bool Vec::find(const int target){
    if (current == 0) return false;
    for (int i = 0; i < current; ++i){
        if (nums[i] == target) return true;
    }
    return false;
};

// remove duplicates
// return by reference, because local variable will be erased after function return
Vec& Vec::inpendetSet(){
    Vec* res = new Vec; // use new to allocate memory in heap
    for (int i = 0; i < current; ++i){
        if (i+1 < current && nums[i] == nums[i+1]) continue;
        res->push_back(nums[i]);
    }
    return *res;
}



