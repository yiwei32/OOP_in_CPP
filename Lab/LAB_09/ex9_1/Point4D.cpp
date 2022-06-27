#include <iostream>
#include "Point2D.h"
#include "Point4D.h"

Point4D::Point4D(int n1, int n2,int n3,int n4):Point2D(n1, n2){
    this->z = new(int);
    this->t = new(int);
    this->set_z(n3);
    this->set_t(n4);
};
// copy constructor
Point4D::Point4D(const Point4D& old):Point2D(old){
    this->set_z(old.get_z());
    this->set_t(old.get_t());
};
void Point4D::display() const{
    this->Point2D::display();
    std::cout << "," << this->get_z() << "," << this->get_t(); 
};
int Point4D::get_z() const{return *z;}
int Point4D::get_t() const{return *t;}
void Point4D::set_z(int val){*z = val;}
void Point4D::set_t(int val){*t = val;}
// additional member function to allow pt4 = pt2
Point4D& Point4D::operator = (const Point2D& pt2d){
    if (this == &pt2d) return *this;
    this->set_x(pt2d.get_x());
    this->set_y(pt2d.get_y());
    *(this->z) = *(this->t) = 0;
    return *this;
};