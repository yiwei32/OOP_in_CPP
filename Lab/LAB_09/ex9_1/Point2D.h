 // Point2D.h
#ifndef POINT2D_H
#define POINT2D_H
class Point2D{
private:
   int *x;
   int *y;
public:
    Point2D(int n1 = 0, int n2 = 0);
    // copy constructor
    Point2D(const Point2D& old);
    void display() const;
    int get_x() const{return *x;}
    int get_y() const{return *y;}
    void set_x(int val){*x=val;}
    void set_y(int val){*y=val;}
};
#endif