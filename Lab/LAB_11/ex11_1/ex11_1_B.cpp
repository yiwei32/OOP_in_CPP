// lab11-3-2.cpp
#include <iostream>
using std::cout; using std::endl;
/* abstract class Shape defined in lab11-3 */ 
/* general class Point2D defined in lab11-2 */
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
    void setColor(int c){color = c;}
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
    Circle(Point2D& p2d, double r = 0, int color = 0) : Shape(color), center(p2d), radius(r){
        cout << "construct Circle" << endl;
    }
    ~Circle(){cout << "Delete Circle" << endl;};
    void draw(){
        cout << "center: "; center.display(); 
        cout << endl;
        cout << "radius: " << radius << endl;
        cout << "color: " << getColor() << endl; 
    };
    bool is_closed() {return true;}
};


class Polygon: public Shape{
public:
    bool is_closed() {return true;} 
};

class Triangle: public Polygon{
private:
    Point2D *vertices;
public:
    // constructor for Triangle
    Triangle(Point2D* v, int c){
        setColor(c);
        vertices = new Point2D[3];
        for (int i = 0; i < 3; ++i){
            vertices[i].setPoint2D(v[i]);
        }
    }
    ~Triangle() {delete [] vertices;}
    void draw(){
        cout << "Color: " << getColor() << endl;
        cout << "Vertices: " << endl;
        for (int i = 0; i < 3; ++i){
            vertices[i].display();
            cout << endl;
        }
    };
};
int main() {
    Point2D *vec = new Point2D[3];
    vec[0].setPoint2D(1,1);
    vec[1].setPoint2D(6,1);
    vec[2].setPoint2D(1,8);
    Triangle t(vec,255);
    delete []vec;
    t.draw();
    return 0; 
}