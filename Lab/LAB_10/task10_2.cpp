// lab10-2
#include <iostream>
using std::cout;
using std::endl;

class Point2D{
private:
    int x;
    int y;
public:
    Point2D(){x = 0; y = 0;}
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
};

class Circle_in_Triangle: public Circle, public Triangle {
public:
    // ...
    Circle_in_Triangle(Point2D c, double r, Point2D* v):Circle(c, r), Triangle(v){};
    void draw(){
       Circle::draw();
       Triangle::draw();
    }
};

int main(){
    Point2D p;
    Point2D *vec = new Point2D [3];
    Circle_in_Triangle ct(p,0,vec);
    ct.draw();
    return 0; 
}