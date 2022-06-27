#include <iostream>
#include "Package.h"
#include <assert.h>
#include <iomanip>
using std::cout;
using std::endl;

// If you put variable definitions into a header, 
// it is going to be defined in each translation unit where the header is included.
int Package::cnt = 0; 

Package::Package(string sN, string sC, string rN, string rC, double w, double cpw){
    assert(w >= 0 && cpw >= 0);
    senderName = sN;
    senderCity = sC;
    recipientName = rN;
    recipientCity = rC;
    weight = w;
    costPerWeight = cpw;
    Package::cnt += 1;
    No = Package::cnt;
};
double Package::calculateCost() const{
    return weight * costPerWeight;
};

void Package::display() const{
    cout << "Package " << get_No() << ":" << endl;
    cout << "Sender:" << endl;
    cout << get_senderName() << " / " << get_senderCity() << endl;
    cout << "Recipient:" << endl;
    cout << get_recipientName() << " / " << get_recipientCity() << endl;
    cout << "Cost: $" << std::fixed << std::setprecision(3) << this->calculateCost() << endl;
};

TwoDayPackage::TwoDayPackage(string sN, string sC, string rN, string rC, double w, double cpw, double flatF):
Package(sN, sC, rN, rC, w, cpw){
    assert(flatF >= 0);
    flatFee = flatF;
};

double TwoDayPackage::calculateCost() const{
    return Package::calculateCost() + flatFee;
};

OvernightPackage::OvernightPackage(string sN, string sC, string rN, string rC, double w, double cpw, double ofpw):
Package(sN, sC, rN, rC, w, cpw){
    assert(ofpw >= 0);
    overnightFeePerWeight = ofpw;
};

double OvernightPackage::calculateCost() const{
    return get_weight() * (get_costPerWeight() + overnightFeePerWeight);
};

