#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using std::string;

class Package{
private:
    int No;
    string senderName;
    string senderCity;
    string recipientName;
    string recipientCity;
    double weight;
    double costPerWeight;
    static int cnt;
public:
    Package(string sN="", string sC="", string rN="", string rC="", double w=0, double cpw=0);
    double calculateCost() const;
    double get_weight() const{return weight;}
    double get_costPerWeight() const{return costPerWeight;}
    int get_No() const{return No;}
    static int get_cnt() {return Package::cnt;}
    string get_senderName() const{return senderName;}
    string get_senderCity() const{return senderCity;}
    string get_recipientName() const{return recipientName;}
    string get_recipientCity() const{return recipientCity;}
    void display() const;
};


class TwoDayPackage : public Package{
private:
    double flatFee; // flat fee for two-day-delivery service
public:
   /* any member functions if necessary */
   TwoDayPackage(string sN="", string sC="", string rN="", string rC="", double w=0, double cpw=0, double flatF=0);
   double calculateCost() const;
};
class OvernightPackage : public Package {
private:
    double overnightFeePerWeight; // flat fee weight for overnight delivery
public:
   /* any member functions if necessary */
   OvernightPackage(string sN="", string sC="", string rN="", string rC="", double w=0, double cpw=0, double ofpw=0);
   double calculateCost() const;
}; 
#endif