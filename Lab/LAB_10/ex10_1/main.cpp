#include <iostream>
using std::cout;
using std::endl;

class Point2D{
private:
    int x;
    int y;
public:
    Point2D(int x_val = 0, int y_val = 0){x = x_val; y = y_val;}
    int get_x(){return x;}
    int get_y(){return y;}
    void display() const{cout << "(" << x << "," << y << ")";};
    // ...
};

class Shape{
protected:
    int color; 
public:
    Shape(int c):color(c){}
    int get_color(){return color;}
    void set_color(int c){color=c;};
};

class Circle: public virtual Shape {
   // definition in lab10-3
private:
    Point2D center;
    double radius;
public:
    Circle(int color, Point2D c, double r) : Shape(color), center(c), radius(r){}
    void draw(){
        cout << "Center: ";
        center.display();
        cout << endl; 
        cout << "Radius: " << radius << endl;
    };
    double area(){return 3.14 * radius * radius;}
    void display_area(){
        cout << "Area of Circle: " << area() << endl;
    }
    
    //... 
};

class Triangle: public virtual Shape {
    // definition in lab10-3
private:
    Point2D *vertices;
public: 
    // ...
    Triangle(int color, Point2D *v) : Shape(color), vertices(v){};
    ~Triangle(){delete [] vertices;}
    void draw(){
        cout << "Vertices: " << endl;
        for (int i = 0; i < 3; ++i){
            vertices[i].display();
            cout << endl;;
        }
    };
    double area(){
        
        double a = abs(vertices[0].get_x() * (vertices[1].get_y() - vertices[2].get_y()) 
                    + vertices[1].get_x()*(vertices[2].get_y() - vertices[0].get_y()) 
                    + vertices[2].get_x()*(vertices[0].get_y() - vertices[1].get_y()));
        return a / 2;
    }
    void display_area(){
        cout << "Area of Triangle: " << area() << endl;
    }
};

class Circle_in_Triangle: public Circle, public Triangle {
public:
    // ...
    Circle_in_Triangle(int color, Point2D center, double r, Point2D* v):Shape(color), Circle(color, center, r), Triangle(color, v){}
    // ~Circle_in_Triangle(){}
    double area(){return Triangle::area() - Circle::area();}
    void draw(){
        cout << "Circle's color: " << Circle::color << endl; 
        cout << "Triangle's color: " << Triangle::color << endl; 
        Circle::draw();
        Triangle::draw();
    }
    void display_area(){
        Circle::display_area();
        Triangle::display_area();
        cout << "Area of Circle_in_Triangle: " << area() << endl;
    }
    
};

int main(){
    /*
        destructor in Triangle uses delete, which means that if we declare tri[3] in main function, 
        the memory allocated to tri is in stack and cannot be deleted / freed.
        
        Another way is to comment the destructor of Triangle ~Triangle().
        Then the default destructor autometically generated by compiler will do nothing.
    */

    // Point2D tri[3] = {Point2D(2,1), Point2D(8, 1), Point2D(5, 6)};
    Point2D *tri = new Point2D [3];
    tri[0] = Point2D(2, 1);
    tri[1] = Point2D(8, 1);
    tri[2] = Point2D(5, 6);
    int color = 255;
    double radius = 1;
    Point2D center(2, 2);
    Circle_in_Triangle s1(color, center, radius, tri);
    s1.draw();
    s1.display_area();
    return 0;
}