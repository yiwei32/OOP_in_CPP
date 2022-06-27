#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "score.h"
#include "school.h"
#include "student.h"
using namespace std;

int main(){
    School nctu;
    cout << nctu.getStudent(0).getName() << endl;
    // double t[5] = {99, 90, 80, 90, 90};
    // int s[5] = {1, 1, 0, 0, 0};
    // Evaluation e(t, 5, s, 5);
    // cout << e.getScore() << endl;
    // cout << e.getSportScore() << endl;
    // cout << e.getTestScore() << endl;
    return 0;

}