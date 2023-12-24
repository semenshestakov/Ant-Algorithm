//  Created by Семён Шестаков on 12.11.2023.
#ifndef ClassAnt_hpp
#define ClassAnt_hpp

#include <unordered_map>
#include <random>
#include "BaseAnt.hpp"

#define DIST_CONST 100.0
#define Q 10.0
#define cP 0.52
#define alpha 0.5 // P
#define beta 1. // dist

struct PointToPoint{
    double distanceToPoint = 0;
    double P = 0.2;
};

typedef unordered_set<ptrPoint, Point::SharedPtrHash, Point::SharedPtrEqual> setPoint;
typedef unordered_map<ptrPoint, unordered_map<ptrPoint, PointToPoint, Point::SharedPtrHash, Point::SharedPtrEqual>, Point::SharedPtrHash, Point::SharedPtrEqual> mapPoint;

extern mapPoint fullDist;
extern double minDist;


class Ant : public virtual BaseAnt{
    
private:
    double distance = 0;
    double event = 0;
    double pheromones = 0;
    void next();
    double funcP(const ptrPoint&);
    vector<ptrPoint> history;
    friend void iteration();
    
protected:
    ptrPoint fromPoint = NULL;
    ptrPoint toPoint = NULL;
    virtual void nextVertex(ptrPoint&);
    virtual ptrPoint popVertex();

public:
    Ant();
    Ant(ptrPoint&, vector<ptrPoint>&);
};

static vector<shared_ptr<Ant>> vecAnt;
void calcDist(const vector<ptrPoint>&);
void initAntVec(vector<ptrPoint>);
void iteration();

#endif /* ClassAnt_hpp */
