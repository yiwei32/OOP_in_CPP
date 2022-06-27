#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <unordered_map>
#include <cstring>
#include <string>
using namespace std;


class Item{
public:
    friend class Person;
    string name;
    int armor_low;
    int armor_high;
    int damage_low;
    int damage_high;
    static unordered_map<string, Item> item_map;

    Item(){armor_low = armor_high = damage_low = damage_high = 0; name="";};
    Item(string item_name);
    friend istream& operator >> (istream&, Item&);
    void display();
    string get_name(){return name;};
};
unordered_map<string, Item> Item::item_map;

Item::Item(string item_name){
    *this = item_map[item_name];
};


istream& operator >> (istream& ins, Item& item){
    // reset item
    item = Item();
    string line, text;
    while (getline(ins, line)){
        text = text + " " + line;
        if (line == "}") break;
    }

    stringstream ss(text);
    stringstream ssLine;
    string tmp;
    ss >> tmp >> item.name >> tmp; // ignore "Item" and "{"
    // read the second line and third line, the order of damage and armor is random
    int cnt = 0;
    while (ss >> line){
        
        if (line.substr(0,5) == "Armor"){
            ssLine.str(line.substr(6)); // start from purely number
            // check if there is a range
            size_t pos = line.find("-");
            if (pos != string::npos){
                int low, high;
                ssLine >> low;
                ssLine >> high; // read negative number
                item.armor_low = low;
                item.armor_high = -high;
            }
            else{
                int armor;
                if (item.name == "Ring"){cout <<ssLine.str() << endl;};
                ssLine >> armor;
                if (item.name == "Ring"){cout << armor << endl;};
                item.armor_high = item.armor_low = armor;
            }
        }
        else if (line.substr(0, 6) == "Damage"){
            ssLine.str(line.substr(7)); // ignore Damage:,  start from purely number
            // check if there is a range
            size_t pos = line.find("-");
            if (pos != string::npos){
                int low, high;
                ssLine >> low;
                ssLine >> high; // read negative number
                item.damage_low = low;
                item.damage_high = -high;
            }
            else{
                int dmg;
                if (item.name == "Ring"){cout <<ssLine.str() << endl;};
                ssLine >> dmg;
                if (item.name == "Ring"){cout <<"dmg: " << dmg << endl;};
                item.damage_high = item.damage_low = dmg;
                
            }
        }
        ssLine.str(string());
        
        
    }
    (item.item_map)[item.name] = item;

    return ins;
}


int main(){
    // ifstream inf("try.txt", ios::in);
    // Item i;
    // inf >> i;

    string s = "244";
    stringstream ss(s);
    int a;
    cout << "state:" << ss.good() << endl;
    ss >> a;
    cout << "state:" << ss.good() << endl;
    ss.clear();
    ss << "345";
    cout << "state:" << ss.good() << endl;
    int b;
    ss >> b;
    cout << b << endl;
    cout << "state:" << ss.good() << endl;



    return 0;
}