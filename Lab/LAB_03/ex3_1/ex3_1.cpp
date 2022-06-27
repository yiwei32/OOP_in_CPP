// ex3-1.cpp
#include <iostream>
#include "linkedlist.h"
using namespace std;
List list;
int main(){
    size_t i = 0;
    while (1){
        cout << "Please select an option:" << endl
             << "1.Insert a node" << endl
             << "2.Delete a node" << endl
             << "3.Display the list" << endl
             << "4.End" << endl;
        cin >> i;
        int data;
        switch(i){
            case 1:
                cout << "Please enter the number:" << endl;
                cin >> data;
                list.InsertNode(data);
                break;
            case 2:
                cout << "Please enter the number:" << endl;
                cin >> data;
                if (!list.DeleteNode(data) )
                cout << "Failed to delete node " << data << endl; 
                break;
            case 3:
                list.Display();
                break;
            case 4:
                return 0;
            default:
                break;
        }
    }
}