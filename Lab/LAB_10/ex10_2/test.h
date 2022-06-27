#ifndef TEST_H
#define TEST_H
#include "score.h"

class Test : virtual public Score{
protected:
    double *test_scores;
    size_t num_subjects;
    double avgTestScore;

public:
    Test(double *tS = NULL, int n = 0) : Score(), test_scores(tS), num_subjects(n){
        avgTestScore = 0;
        for (int i = 0; i < num_subjects; ++i){
            avgTestScore += test_scores[i];
        }
        avgTestScore /= num_subjects;
        score = avgTestScore;
    }
    double getTestScore() const{return avgTestScore;}
    void setTestScores(double *s){test_scores = s;}
    
};
#endif