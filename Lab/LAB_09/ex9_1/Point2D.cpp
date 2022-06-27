#include <iostream>
#include "Point2D.h"

Point2D::Point2D(int n1, int n2){
    this->x = new int();
    this->y = new int();
    this->set_x(n1);
    this->set_y(n2);
};

Point2D::Point2D(const Point2D& old){
    this->x = new(int);
    this->y = new(int);
    this->set_x(old.get_x());
    this->set_y(old.get_y());
};

void Point2D::display() const{
    std::cout << get_x() << "," << get_y();
};