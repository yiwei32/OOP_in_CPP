// Point4D.h
#ifndef POINT4D_H
#define POINT4D_H
#include "Point2D.h"
class Point4D: public Point2D{
private:
    int *z;
    int *t;
public:
    Point4D(int n1 =0,int n2 = 0,int n3 = 0,int n4 = 0);
    // copy constructor
    Point4D(const Point4D& old);
    void display() const;
    int get_z() const;
    int get_t() const;
    void set_z(int val);
    void set_t(int val);
    // additional member function to allow pt4 = pt2
    Point4D& operator = (const Point2D& pt2d);
}; 
#endif