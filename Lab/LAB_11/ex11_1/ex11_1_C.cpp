#include <iostream>
using namespace std;

class Point2D{
private:
    int* x;
    int* y;
public:
    Point2D(int x_vay = 0, int y_val = 0) : x(new int (x_vay)), y(new int (y_val)){}
    Point2D(const Point2D& old) : x(new int (old.getXVal())), y(new int (old.getYVal())){}
    ~Point2D(){delete x; delete y; cout << "Delete Point2D" << endl;}
    int* getXAddr() const {return x;}
    int* getYAddr() const {return y;}
    int getXVal() const {return *x;}
    int getYVal() const {return *y;}
    void setPoint2D(int x_val, int y_val){*x=x_val; *y=y_val;}
    void setPoint2D(const Point2D& old){*x = old.getXVal(); *y = old.getYVal();}
    void display() const { cout << "(" << *x << "," << *y << ")";}
};

class Shape{
protected:
    int color;
public:
    Shape(int c = 0) : color(c){}
    virtual ~Shape(){cout << "Delete Shape" << endl;}
    int getColor() const{return color;}
    void setColor(int c) {color = c;}
    void displayColor() const{cout << "Color: " << color;}
    virtual double area() const = 0;
    virtual void draw() const= 0;
};

class Circle : public Shape{
private:
    Point2D center;
    double radius;
public:
    Circle(const Point2D& pt2d, double r, int c = 0) : Shape(c), center(pt2d), radius(r){}
    ~Circle(){cout << "Delete Circle" << endl;};
    double area() const{return 3.14 * radius * radius;}
    void draw() const{
        displayColor();
        cout << endl;
        cout << "Center: "; 
        center.display();
        cout << endl;
        cout << "Radius: " << radius << endl;
    }
};

class Triangle : public Shape{
private:
    Point2D* vertices;
public:
    Triangle(Point2D* vec, int c = 0) : Shape(c){
        
        vertices = new Point2D [3];
        for (int i = 0; i < 3; ++i){
            vertices[i].setPoint2D(vec[i]);
        }
        cout << "Construct Triangle" << endl;
        cout << "Addr of vertices: " << long(vertices) << endl;
        cout << "Addr of vec " << long(vec) << endl;
    }
    ~Triangle(){delete [] vertices; cout << "Delete Triangle" << endl;}
    double area() const{
        double a = abs(vertices[0].getXVal() * (vertices[1].getYVal() - vertices[2].getYVal()) 
                    + vertices[1].getXVal()*(vertices[2].getYVal() - vertices[0].getYVal()) 
                    + vertices[2].getXVal()*(vertices[0].getYVal() - vertices[1].getYVal()));
        return a / 2;
    }
    void draw() const{
        displayColor(); 
        cout << endl;
        cout << "Vertices:" << endl;
        for (int i = 0; i < 3; ++i){
            vertices[i].display();
            cout << endl;
        }
        cout << "Area: " << area() << endl;
    }
};

class Rectangle : public Shape{
private:
    Point2D* vertices;
public:
    Rectangle(Point2D* vec, int c = 0) : Shape(c){
        vertices = new Point2D [4];
        for (int i = 0; i < 4; ++i){
            vertices[i].setPoint2D(vec[i]);
        }
        cout << "Construct Rectangle" << endl;
    }
    ~Rectangle(){delete [] vertices; cout << "Delete Rectangle" << endl;}

    double area() const{
        double length = vertices[1].getXVal() - vertices[0].getXVal();
        double width =  vertices[3].getYVal() - vertices[0].getYVal();
        return length * width;
    }
    void draw() const{
        displayColor(); 
        cout << endl;
        cout << "Vertices:" << endl;
        for (int i = 0; i < 4; ++i){
            vertices[i].display();
            cout << endl;
        }
        cout << "Area: " << area() << endl;
    }
};


int main() {

    Point2D pt(3,4);
    Circle cir(pt, 5);
    Point2D *vec = new Point2D [3]; 
    vec[0].setPoint2D(1,1); 
    vec[1].setPoint2D(1,6); 
    vec[2].setPoint2D(8,1);
    Triangle tri(vec);
    delete []vec;
    vec = new Point2D [4];
    vec[0].setPoint2D(1,1); 
    vec[1].setPoint2D(6,1);
    vec[2].setPoint2D(6,6); 
    vec[3].setPoint2D(1,6);
    Rectangle rect(vec);
    delete [] vec;
    Shape *collection[3];
    collection[0] = &cir;
    collection[1] = &tri;
    collection[2] = &rect;
    cout << "Area of Circle: " << collection[0]->area() << endl; 
    cout << "Area of Triangle: " << collection[1]->area() << endl; 
    cout << "Area of Rectangle: " << collection[2]->area() << endl;
    return 0; 
}