//  Created by Семён Шестаков on 30.12.2023.


#ifndef AntColony_hpp
#define AntColony_hpp

#include "ClassAnt.hpp"

#define DIST_CONST 100.0
#define Q 10.0
#define cP 0.72
#define alpha 0.5 // P
#define beta 1. // dist

class AntColony{
private:
    vector<shared_ptr<Ant>> vecAnt;
    double minDist = 10e100;
    
public:
    AntColony();
    AntColony(vector<ptrPoint>&);
    void calcDist(vector<ptrPoint>&);
    void initAntVec(vector<ptrPoint>&);
    void iteration();
};

#endif /* AntColony_hpp */
