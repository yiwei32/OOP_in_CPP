// lab10-4.cpp
#include <iostream>
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

class Shape{
protected:
    int color; 
};
class Circle: public Shape{
   // definition in lab10-3
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
class Triangle: public Shape{
   // definition in lab10-3
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

class Circle_in_Triangle: public Circle, public Triangle{
public:
    // ...
    void draw(){
    cout << "Circle's color: " << Circle::color << endl; cout << "Triangle's color: " << Triangle::color << endl; 
    Circle::draw();
    Triangle::draw();
    }
};