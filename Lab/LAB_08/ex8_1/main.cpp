#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <unordered_map>

using namespace std;

class Item{
    friend class Person;
    string name;
    int armor_low;
    int armor_high;
    int damage_low;
    int damage_high;
    static unordered_map<string, Item> item_map;
    

public:
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
                ssLine >> armor;
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
                ssLine >> dmg;
                item.damage_high = item.damage_low = dmg;
            }
        }
        // After reach the end of stream, fail bit on
        // if not reset, we cannot extract value from the stream
        ssLine.clear(); 
        
    }
    (item.item_map)[item.name] = item;

    return ins;
}

void Item::display(){
    cout << "Item " << name << endl;
    string armor_str, damage_str;
    if (armor_low == armor_high){
        armor_str = to_string(armor_low);
    }
    else armor_str = (to_string(armor_low) + "-" + to_string(armor_high));
    if (damage_low == damage_high){
        damage_str = to_string(damage_low);
    }
    else damage_str = (to_string(damage_low) + "-" + to_string(damage_high));
    cout << "Armor:" << armor_str << endl;
    cout << "Damage:" << damage_str << endl;
};

class Person{
    std::string name;
    std::vector<Item> items;
    int armor_low;
    int armor_high;
    int damage_low;
    int damage_high;
public:
    Person();
    Person(string name, vector<Item>& items);
    string get_name(){return name;};
    void set_name(string name){this->name=name;};
    void add_item(const Item i);
    friend ostream& operator << (ostream&, Person&);
    friend istream& operator >> (istream& ins, Person& person);
};
Person::Person(){
    name = "";
    vector<Item> tmp;
    items = tmp;
    armor_low = 0;
    armor_high = 0;
    damage_low = 0;
    damage_high = 0;
}
Person::Person(string name, vector<Item>& items){
    name = name;
    items = items;
}

void Person::add_item(const Item i){
    items.push_back(i);
    armor_low += i.armor_low;
    armor_high += i.armor_high;
    damage_low += i.damage_low;
    damage_high += i.damage_high;
}

ostream& operator << (ostream& os, Person& person){
    string armor_str, damage_str;
    if (person.armor_low == person.armor_high){
        armor_str = to_string(person.armor_low);
    }
    else armor_str = (to_string(person.armor_low) + "-" + to_string(person.armor_high));
    if (person.damage_low == person.damage_high){
        damage_str = to_string(person.damage_low);
    }
    else damage_str = (to_string(person.damage_low) + "-" + to_string(person.damage_high));
    cout << left << setw(10) << person.get_name() 
    << "Damage:" << setw(10) << damage_str 
    << "Armor:"<< armor_str << endl;
    return os;
};
istream& operator >> (istream& ins, Person& person){
    // reset person
    person = Person();
    string line;
    getline(ins, line);
    stringstream ss(line);
    string person_name;
    ss >> person_name;
    person.set_name(person_name);
    string item_name;
    while (ss >> item_name){
        person.add_item(Item(item_name));
    }
    return ins;
};


int main(){
    ifstream inFile1("ex8_1_1.txt", ios::in);
    if (!inFile1) { cout << "ex8_1_1.txt cannot be opened!\n"; return -1;}
    ifstream inFile2("ex8_1_2.txt", ios::in);
    if (!inFile2) { cout << "ex8_1_2.txt cannot be opened!\n"; return -1;}

    vector<Person> persons;
    Item itmp;
    Person ptmp;
    while (inFile2 >> itmp);

     // construct item_map in class Item
    while (inFile1 >> ptmp){
        persons.push_back(ptmp);
    }
    for (int i = 0; i < persons.size(); ++i){
        cout << persons[i];
    }
    
    return 0;
}