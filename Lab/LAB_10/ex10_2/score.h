#ifndef SCORE_H
#define SCORE_H

class Score{
protected:
    double score;
public:
    Score(double s = 0) : score(s){}
    double getScore() const{return score;}
};

#endif