#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

extern void func1(void){cout<< 1 << endl;};
extern void func2(void){cout<< 2 << endl;};
extern void func3(void){cout<< 3 << endl;};
extern void func4(void){cout<< 4 << endl;};
extern void func5(void){cout<< 5 << endl;};

void yo(int n)
{
    void (*pf[5])(void) = {func1, func2, func3, func4, func5};
    pf[n-1]();
}
// int main(){
//     yo(3);
//     return 0;
// }



void printVec(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


class MinHeap{
    int *arr;
    int capacity;
    int heap_size;
    void swap(int *a, int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
public:
    MinHeap(int cap);
    // to heapify a subtree with the root at given index
    void MinHeapify(int i);
    int left(int i) {return (2*i+1);}
    int right(int i) {return (2*i+2);}
    int parent(int i) {return (i-1)/2;}
    int getMin() {return arr[0];}
    int extractMin();
    void decreaseKey(int i, int newVal);
    void insertKey(int val);
    void deleteKey(int i);
};

MinHeap::MinHeap(int cap){
    capacity = cap;
    arr = new int [cap];
    heap_size = 0;
}
void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && arr[l] < arr[smallest]) smallest = l;
    if (r < heap_size && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i){
        swap(&arr[i], &arr[smallest]);
        MinHeapify(smallest);
    } 
}

int MinHeap::extractMin(){
    if (heap_size <= 0){
        cout << "\nHeap size <= 0\n";
        return INT_MAX;
    }
    if (heap_size == 1){
        heap_size--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[--heap_size];
    MinHeapify(0);
    return root;
}

void MinHeap::decreaseKey(int i, int newVal){
    if (i >= heap_size){
        cout << "\nout of bound\n";
        return;
    }
    arr[i] = newVal;
    while (i != 0 && arr[parent(i)] > arr[i]){
        swap(&arr[parent(i)], &arr[i]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::insertKey(int val){
    if (heap_size == capacity){
        cout << "\n overflow, cannot insert\n";
        return; 
    }
    int i = heap_size;
    heap_size++;
    arr[i] = val;
    while (i != 0 && arr[parent(i)] > arr[i]){
        swap(&arr[parent(i)], &arr[i]);
        i = parent(i);
    }
}




void Merge(vector<int>& nums, int front, int mid, int end){
    int leftSubLen = mid - front + 1;
    int rightSubLen = end - mid;

    // copy data to two sub arrays
    vector<int> leftSub, rightSub;
    for (int i = front; i <= mid; ++i){
        leftSub.push_back(nums[i]);
    }
    for (int j = mid+1; j <= end; ++j){
        rightSub.push_back(nums[j]);
    }

    int leftIdx = 0;
    int rightIdx = 0;
    int mergeIdx = front;

    while (leftIdx < leftSubLen && rightIdx < rightSubLen){
        if (leftSub[leftIdx] < rightSub[rightIdx]){
            nums[mergeIdx] = leftSub[leftIdx];
            leftIdx++;
        }
        else{
            nums[mergeIdx] = rightSub[rightIdx];
            rightIdx++;
        }
        mergeIdx++;
    }

    // copy remaining
    while (leftIdx < leftSubLen){
        nums[mergeIdx] = leftSub[leftIdx];
        mergeIdx++;
        leftIdx++;
    }
    while (rightIdx < rightSubLen){
        nums[mergeIdx] = rightSub[rightIdx];
        mergeIdx++;
        rightIdx++;
    }
}

void MergeSort(vector<int>& nums, int front, int end){
    if (front < end){
        int mid = front + (end - front) / 2;
        MergeSort(nums, front, mid);
        MergeSort(nums, mid+1, end);
        Merge(nums, front, mid, end);
    }
}




// // 一個整型數（An integer） 
// int a;
// // 一個指向整型數的指標（A pointer to an integer）
// int *a;
// // 一個指向指標的的指標，它指向的指標是指向一個整型數（A pointer to a pointer to an integer）
// int **a;
// // 一個有10個整型數的陣列（An array of 10 integers）
// int a[10];
// // 一個有10個指標的陣列，該指標是指向一個整型數的（An array of 10 pointers to integers）
// int *a[10];
// // 一個指向有10個整型數陣列的指標（A pointer to an array of 10 integers）
// int (*a)[10];
// // 一個指向函數的指標，該函數有一個整型參數並返回一個整型數（A pointer to a function that takes an integer as an argument and returns an integer）
// int (*a)(int);
// // 一個有10個指標的陣列，該指標指向一個函數，該函數有一個整型參數並返回一個整型數（ An array of ten pointers to functions that take an integer argument and return an integer ）
// int (*a[10])(int);

class ListNode{
public:
    int val;
    ListNode* next;
};

class Stack{
    ListNode* head;
    int stack_size;
public:
    Stack();
    int peek();
    int pop();
    void push(int val);
    int size() {return stack_size;};
    bool isEmpty(){return stack_size == 0;}
};
Stack::Stack(){
    head = NULL;
    stack_size = 0;
}

int Stack::peek(){
    if (isEmpty()){
        cout << "Empty!" << endl;
        return -1;
    }
    return head->val;
}

int Stack::pop(){
    if (isEmpty()){
        cout << "Empty!" << endl;
        return -1;
    }
    ListNode* tmp = head->next;
    int res = head->val;
    delete head;
    head = tmp;
    stack_size--;
    return res;
}

void Stack::push(int val){
    ListNode* toPush = new ListNode();
    toPush->val = val;
    toPush->next = head;
    head = toPush;
    stack_size++;
}






int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front-1;
    for (int j = front; j < end; ++j){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        };
    }
    i++;
    swap(&arr[end], &arr[i]);
    return i;
};

void QuickSort(int *arr, int front, int end){
    
    if (front < end){
        int pi = Partition(arr, front, end);
        QuickSort(arr, front, pi-1);
        QuickSort(arr, pi+1, end);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}




const int MAX = 10;

class QueueCircularArr{
    int *arr;
    int capacity;
    int queue_size;
    int front;
    int back;
    void DoubleCapacity();
public:
    QueueCircularArr():capacity(MAX), queue_size(0), front(0), back(0){
        arr = new int [capacity];
    }
    void push(int val);
    int pop();
    int getFront();
    int getBack();
    int getSize();
    bool isEmpty(){return back==front;}
    bool isFull(){return (back+1)%capacity==front;}
};

void QueueCircularArr::DoubleCapacity(){
    int *Darr = new int [capacity*2];
    for (int i = 0; i < capacity; ++i){
        Darr[i] = arr[i];
    }
    capacity *= 2;
    delete arr;
    arr = Darr;
}

void QueueCircularArr::push(int val){
    if (isFull()) DoubleCapacity();
    back = (back+1) % capacity;
    arr[back] = val;
}
int QueueCircularArr::pop(){
    if (isEmpty()){
        cout << "Empty Queue" << endl;
        return -1;
    }
    front = (front + 1) % capacity;
    return arr[front];
}

int QueueCircularArr::getFront(){
    if (isEmpty()){
        cout << "Empty Queue" << endl;
        return -1;
    }
    return arr[(front+1)%capacity];
}
int QueueCircularArr::getBack(){
    if (isEmpty()){
        cout << "Empty Queue" << endl;
        return -1;
    }
    return arr[back];
}
int QueueCircularArr::getSize(){
    if (back > front){
        return back - front;
    }
    else{
        return back + capacity - front;
    }
}





// class QueueSArr{
//     int *arr;
//     int capacity, front, back;
//     void DoubleCapacity();
// public:
//     QueueSArr():capacity(MAX), front(-1), back(-1){
//         arr = new int [capacity];
//     }
//     void push(int val);
//     int pop();
//     int getFront();
//     int getBack();
//     int getSize() {return back-front;}
// };

// void QueueSArr::push(int val){
//     if (back+1 == capacity){
//         DoubleCapacity();
//     }
//     arr[++back] = val;
// }

// int QueueSArr::pop(){
//     if(front == back){
//         cout << "Empty queue" << endl;
//         return -1;
//     }
//     return arr[++front];
// }

// int QueueSArr::getFront(){
//     if (back == front){
//         cout << "Empty queue!" << endl;
//         return -1;
//     }
//     return arr[front+1];
// }
// int QueueSArr::getBack(){
//     if (back == front){
//         cout << "Empty queue!" << endl;
//         return -1;
//     }
//     return arr[back];
// }

void printCircularQueue (QueueCircularArr queue){
    cout << "front: " << queue.getFront() << "    back: " << queue.getBack() << "\n"
    << "  number of elements: " << queue.getSize() << "\n\n";
}



void copySetBits(unsigned& x, unsigned& y, unsigned l, unsigned r){
    for (int i = l; i <= r; ++i){
        int mask = 1 << i;
        if (x & mask){
             y |= mask;
        }
        else{
            y &= ~mask;
        }
    }
}

int main(){
    unsigned x = 13;
    unsigned y = 10;
    copySetBits(x, y, 0, 1);
    cout << y << endl;


    return 0;
}

