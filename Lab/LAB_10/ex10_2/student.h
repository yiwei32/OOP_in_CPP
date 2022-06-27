#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include "evaluation.h"
using std::string;
using std::istream;
using std::ostream;

class Student{
private:
    size_t id;
    string name;
    Evaluation evaluation;
public:
    Student(int stu_id=0, string stu_n="", Evaluation stu_fs=Evaluation()):id(stu_id), name(stu_n), evaluation(stu_fs){}
    string getName() const{return name;}
    size_t getId() const {return id;}
    Evaluation getEvaluation() const{return evaluation;}
    double getFinalScore() const {return evaluation.getScore();}
    void setEvaluation(Evaluation e){evaluation = e;}

    friend istream& operator >> (istream& ins, Student& stu);
    friend ostream& operator << (ostream& ost, Student& stu);
};

#endif