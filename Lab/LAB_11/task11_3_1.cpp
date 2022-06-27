// lab11-3.cpp
#include <iostream>
using std::cout;
using std::endl;

class Point2D{
private:
    int *x;
    int *y;
public:
    Point2D(int x_val = 0, int y_val = 0){x = new int (x_val);y=new int (y_val); cout << "New X and Y" << endl;}
    Point2D(const Point2D& old){
        x = new int (*(old.x));
        y = new int (*(old.y));
        cout << "Copy x and y" << endl;
    }
    virtual ~Point2D(){delete x; delete y; cout << "Delete X and Y" << endl;} 
    void setPoint2D(int x_val, int y_val){*x = x_val; *y = y_val;}
    void setPoint2D(const Point2D& pt2d){*x = *(pt2d.x); *y = *(pt2d.y);}
    
    virtual void display() const;
    
};

void Point2D::display() const{
    cout << *x << "," << *y;
}

class Shape{
protected:
    int color;
public:
    Shape(int c = 0):color(c){}
    int getColor() const{return color;}
    virtual ~Shape(){ cout << "Delete Shape" << endl;}
    virtual void draw() = 0;
    virtual bool is_closed() = 0;
};


class Circle: public Shape{
private:
    Point2D center;
    double radius;
public:
// constructor of Circle.
    Circle(const Point2D& pt2d, double r = 0, int color = 0) : Shape(color), radius(r){
        // center is default constructed automatically since it it not in initializer list
        // simply put it in initializer list and everything will be fine
        center.setPoint2D(pt2d); 

        // center = pt2d; // Error occurs!! pt will be destructed twice!
        
        cout << "construct Circle" << endl;
    }
    ~Circle(){cout << "Delete Circle" << endl;};
    void draw(){
        cout << "Color: " << getColor() << endl; 
        cout << "Center: "; center.display(); 
        cout << endl;
        cout << "Radius: " << radius << endl;
        
    };
    bool is_closed() {return true;}
    void displayCenter() const{center.display();}
};

int main() {
    Point2D pt(3,4);
    
    Circle c(pt,5,255);
    /*
        when passing pt to Circle(), Point2D copy constructor is called if not pass by reference
        when using initializer list center(pt2d), Point2D copy constructor is called

        When a variable is not given in the initalizer list, then it is default constructed automatically
    */

    
    // pt.setPoint2D(1,1);
    c.draw();
    return 0;
}

/*
    Note:
    1. if pass by reference and assign pt2d to center, then the center of circle will change 
       when you change pt.

    2. The destructor of Point2D pt will be called twice and thus error occurs. 
       That is, pt will be deleted when circle destructed, 
       and will be deleted the second time when main function exits.
*/