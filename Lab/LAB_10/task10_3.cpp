// lab10-3.cpp
/* add area() for class Circle */ 
/* add area() for class Triangle */
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

class Point2D{
private:
    int x;
    int y;
public:
    Point2D(){x = 0; y = 0;}
    int get_x(){return x;}
    int get_y(){return y;}
    void display() const{cout << "(" << x << "," << y << ")";};
    // ...
};

class Circle{
private:
    Point2D center;
    double radius;
public:
    Circle(Point2D c, double r) : center(c), radius(r){}
    void draw(){
        center.display();
        cout << ", r = " << radius << endl;
    };
    double area(){return 3.14 * radius * radius;}
    
    //... 
};
class Triangle{
private:
    Point2D *vertices;
public: // ...
    Triangle(Point2D *v) : vertices(v){};
    ~Triangle(){delete [] vertices;}
    void draw(){
        for (int i = 0; i < 3; ++i){
            vertices[i].display();
            cout << " ";
        }
        cout << endl;
    };
    double area(){
        
        double a = abs(vertices[0].get_x() * (vertices[1].get_y() - vertices[2].get_y()) 
                    + vertices[1].get_x()*(vertices[2].get_y() - vertices[0].get_y()) 
                    + vertices[2].get_x()*(vertices[0].get_y() - vertices[1].get_y()));
        return a / 2;
    }
};

class Circle_in_Triangle: public Circle, public Triangle {


public:
    using Circle::area;
    // ...
    Circle_in_Triangle(Point2D c, double r, Point2D* v):Circle(c, r), Triangle(v){};
    void draw(){
       Circle::draw();
       Triangle::draw();
    }
};

int main() {
    Point2D p;
    Point2D *vec = new Point2D [3];
    Circle_in_Triangle ct(p,2,vec);
    ct.draw();
    cout << "Area of Circle: " << ct.Circle::area() << endl;
    cout << "Area of Triangle: " << ct.Triangle::area() << endl; 
    cout << "Area of Circle_in_Triangle: " << ct.area() << endl; 
    return 0;
}