#include "student.h"

istream& operator >> (istream& ins, Student& stu){
    ins >> stu.id >> stu.name;
    int num_subjects = 5;
    int num_sports = 5;
    double *test_scores = new double [num_subjects];
    int *sport_scores = new int [num_sports];
    for (int i = 0; i < num_subjects; ++i){
        ins >> test_scores[i];
    }
    for (int j = 0; j < num_sports; ++j){
        ins >> sport_scores[j];
    }
    stu.setEvaluation(Evaluation(test_scores, num_subjects, sport_scores, num_sports));
    
    return ins;
};

ostream& operator << (ostream& ost, Student& stu){
    ost << stu.getId() << " " << stu.getName() << " " << stu.getFinalScore() << "\n";
    return ost;
};