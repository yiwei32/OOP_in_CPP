// Ex6-1.cpp
#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

class quadrangle{
public:
    class vertex{
        friend class quadrangle;
        int x;
        int y;
    public:
        vertex(int i = 0, int j = 0){x=i; y=j;};
        inline void assign(int u, int w){x=u; y=w;};
        void printVertex(){cout << "(" << x << "," << y << ")";};
        void move(int x_offset, int y_offset){x+=x_offset; y+=y_offset;};
    };
    static vertex origin;
    bool isRect;
    quadrangle();
    quadrangle(vertex lower_l, vertex lower_r, vertex upper_r, vertex upper_l);
    quadrangle(vertex lower_l, vertex upper_r);
    void draw();
    void move(vertex v);
    
private:
    vertex lower_left;
    vertex lower_right;
    vertex upper_left;
    vertex upper_right;
};
quadrangle::vertex quadrangle::origin = quadrangle::vertex(0, 0);

quadrangle::quadrangle(vertex lower_l, vertex lower_r, 
                        vertex upper_r, vertex upper_l){
    this->lower_left = lower_l;
    this->lower_right = lower_r;
    this->upper_left = upper_l;
    this->upper_right = upper_r;
    if (lower_l.y == lower_r.y && lower_l.x == upper_l.x && upper_l.y == upper_r.y 
            && upper_r.x == lower_l.x) this->isRect = true;
    else this->isRect = false;
}
quadrangle::quadrangle(vertex lower_l, vertex upper_r){
    this->lower_left = lower_l;
    this->upper_right = upper_r;
    this->lower_right.assign(upper_r.x, lower_l.y);
    this->upper_left.assign(lower_l.x, upper_r.y);
    this->isRect = true;
};

void quadrangle::draw(){
    cout << "v1: ";
    this->lower_left.printVertex();
    cout << "    ";
    cout << "v2: ";
    this->lower_right.printVertex();
    cout << "    ";
    cout << "v3: ";
    this->upper_right.printVertex();
    cout << "    ";
    cout << "v4: ";
    this->upper_left.printVertex();
    if (isRect) cout << "    Area: " << (lower_right.x-lower_left.x)*(upper_left.y - lower_left.y);
};

void quadrangle::move(vertex v){
    int x_offset = v.x - lower_left.x;
    int y_offset = v.y - lower_left.y;
    lower_left = v;
    lower_right.move(x_offset, y_offset);
    upper_right.move(x_offset, y_offset);
    upper_left.move(x_offset, y_offset);
    cout << "Distance: " << sqrt(pow(x_offset,2) + pow(y_offset,2)) << endl;
};


int main(){
    quadrangle q1(quadrangle::vertex(0,0), quadrangle::vertex(3,2),
                 quadrangle::vertex(10,7),
                  quadrangle::vertex(8,10));
    quadrangle q2(quadrangle::vertex(3,6), quadrangle::vertex(10,9)); 
    cout << "q1 information" << endl;
    q1.draw();
    cout << endl;
    cout << "q2 information" << endl;
    q2.draw();
    cout << endl;
    cout << "q1 move to (5,5) " << endl;
    q1.move(quadrangle::vertex(5,5));
    cout << "q1 information" << endl;
    q1.draw();
    cout << endl;
    quadrangle::origin = quadrangle::vertex(-5,3); 
    cout << "q2 move to (-1,2) " << endl; 
    q2.move(quadrangle::vertex(-1,2));
    cout << "q2 information" << endl;
    q2.draw();
    cout << endl;
    return 0;
} // end main