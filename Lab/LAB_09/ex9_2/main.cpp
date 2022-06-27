#include <iostream>
#include "Package.h" // Package class definition 
using std::cout; using std::endl;


int main(){
    Package package1("Lou Brown", "Boston","Mary Smith", "New York", 8.5, 0.5 ); 
    TwoDayPackage package2("Lisa Klein", "Somerville", "Bob George", "Cambridge", 10.5, .65, 2.0 );
    OvernightPackage package3("E Lewis", "Boston", "Don Kelly", "Denver", 12.25, 0.7, 0.25 );
    /* display the package’s information */
    package1.display(); cout << endl;
    package2.display(); cout << endl;
    package3.display();
    return 0; 
}