#ifndef SCHOOL_H
#define SCHOOL_H
#include <string>
#include "student.h"
using std::string;
class School{
private:
    Student *students;
    double avg;
    size_t num_students;
public:
    School(string inFile="performance.txt");
    size_t get_num() const{return num_students;}
    Student& getStudent(int idx) const{return students[idx];}
    void report(string out) const;
};
#endif