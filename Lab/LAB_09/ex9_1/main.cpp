#include <iostream>
#include "Point2D.h"
#include "Point4D.h"

using std::cout; 
using std::endl;
int main(){
    Point2D pt1(1,2);
    Point2D pt2(3,4);
    pt1.display(); cout << endl;
    pt2.display(); cout << endl;
    pt2 = pt1;
    pt2.display(); cout << endl;
    Point4D pt4(5,6,7,8);
    pt4.display(); cout << endl;
    pt2 = pt4;
    pt2.display(); cout << endl;
    pt4 = pt1;
    pt4.display(); cout << endl;
    return 0;
}