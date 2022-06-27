#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class CCount {
    unsigned int cnt;
public:
    CCount(int n=0) { cnt=n; }
    void display() { cout << cnt; }
    //prefix increment and postfix increment as memmber functions
    CCount& operator++(); 
    CCount& operator++(int);
    //prefix decrement and postfix decrement as friend functions
    friend CCount & operator--(CCount&);
    friend CCount & operator--(CCount&, int);
};

//prefix increment and postfix increment as memmber functions
CCount& CCount::operator++() {
    cnt++; 
	return *this;                
}
CCount& CCount::operator++(int) {
	CCount tmp(*this);
    cnt++; 
	return tmp;                
}

//prefix decrement and postfix decrement as friend functions
CCount & operator--(CCount& x) {
    x.cnt--; 
	return x;	 
} 
CCount & operator--(CCount& x, int y) {
    CCount tmp(x); 
	x.cnt--; 
	return tmp;  
} 

int main() {
	CCount d1(10), d2, d3;
    d2=d1++; //call postfix increment 
    d1.display();cout << " ";d2.display();cout << endl; // 11, 10
    d2=++d1; //call prefix increment
    d1.display();cout << " ";d2.display();cout << endl; // 12, 12
    ++++d1;
    d1.display();cout << " ";d2.display();cout << endl; // 14, 12
    //Q1 what if?
	d1++++;
    d1.display();cout << " ";d2.display();cout << endl; // 15, 12
	
	d1=10;
	d3=d1--; //call postfix increment 
    d1.display();cout << " ";d3.display();cout << endl; // 9, 10
    d3=--d1; //call prefix increment 
    d1.display();cout << " ";d3.display();cout << endl; // 8, 8
    ----d1;
    d1.display();cout << " ";d3.display();cout << endl; // 6, 8
	//Q1 what if?
	d1----;
	d1.display();cout << " ";d3.display();cout << endl; // 5, 8
	
	system("Pause");
    return 0;
}