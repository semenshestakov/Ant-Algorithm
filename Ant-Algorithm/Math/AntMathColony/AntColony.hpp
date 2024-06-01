//  Created by Семён Шестаков on 30.12.2023.


#ifndef AntColony_hpp
#define AntColony_hpp

#include "ClassAnt.hpp"

#define DIST_CONST 200.0
#define Q 10.0
#define cP 0.7
#define MAX_P 0.5
#define alpha 0.5 // P
#define beta 1. // dist

#define STOP_ITER 100 // dist


class AntColony{
private:
    vector<shared_ptr<Ant>> vecAnt;
    double minDist = 10e100;
    size_t iter = 0;
    
public:
    AntColony();
    AntColony(vector<ptrPoint>&);
    ~AntColony();
    void calcDist(vector<ptrPoint>&);
    void initAntVec(vector<ptrPoint>&);
    void iteration();
};

double min(double&, double&);
#endif /* AntColony_hpp */
