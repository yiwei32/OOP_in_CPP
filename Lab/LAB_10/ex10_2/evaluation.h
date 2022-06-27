#ifndef EVALUATION_H
#define EVALUATION_H
#include "test.h"
#include "sport.h"

class Evaluation: public Test, public Sport{
public:
    Evaluation(double *testScores=NULL, int num_t=0, int *sportScores=NULL, int num_s=0) : Score(), Test(testScores, num_t), Sport(sportScores, num_s){
        score = avgTestScore + sportScore;
    }
};


#endif