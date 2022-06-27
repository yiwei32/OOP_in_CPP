#include <iostream>
#include <fstream>
#include <sstream>
#include "school.h"
#include "student.h"
using std::fstream; 
using std::ofstream;
using std::stringstream;
using std::ios;
using std::cout; using std::endl;

School::School(string inFile){
    fstream ifs(inFile, ios::in);
    string line;
    stringstream ss;
    // read first line: number of students
    getline(ifs, line);
    ss.str(line);
    ss >> School::num_students;
    // read students
    Student *student_list = new Student [num_students];
    size_t i = 0;
    int sum = 0;
    while (getline(ifs, line)){
        ss.clear();
        ss.str(line);
        ss >> student_list[i];
        sum += student_list[i++].getFinalScore();
    }
    students = student_list;
    avg = sum / double(num_students);
    ifs.close();
};

void School::report(string out) const{
    fstream ofs(out, ios::out);
    for (int i = 0; i < num_students; ++i){
        ofs << students[i];
    }
    ofs << "Average: " << avg << endl;
    ofs.close();
};
