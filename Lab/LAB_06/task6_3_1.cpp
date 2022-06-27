#include <iostream>

const int num = 10;

class PointND{
private:
    int *coord;
    double value;
public:
    PointND();
    ~PointND();
    void assignValue(double v);
    void assignCoord(int *vec, int len);
    void displayPointND();
};

// original version in lab5-2.cpp
PointND::PointND(){
   value = 0.0;
   coord = new int [num];
   for (int i=0;i<num;i++) coord[i] = 0;
}
// modify version in lab6-3-1.cpp
PointND::PointND(){
    this->value = 0.0;
    this->coord = new int [num];
    for (int i=0;i<num;i++) this->coord[i] = 0;
}