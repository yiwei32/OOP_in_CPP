#ifndef SPORT_H
#define SPORT_H
#include "score.h"

class Sport : virtual public Score{
protected:
    int *sport_scores;
    size_t num_sports;
    int sportScore;
    
public:
    Sport(int *sS = NULL, int n = 0) : Score(), sport_scores(sS), num_sports(n){
        sportScore = 0;
        for (int i = 0; i < num_sports; ++i){
            if (sport_scores[i] == 1) sportScore += 5;
        }
        score = sportScore;
    }
    double getSportScore() const{return sportScore;}
    void setSportScores(int *s){sport_scores = s;}
};

#endif