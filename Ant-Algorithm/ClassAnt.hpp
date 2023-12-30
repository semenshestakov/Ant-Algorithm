//  Created by Семён Шестаков on 12.11.2023.
#ifndef ClassAnt_hpp
#define ClassAnt_hpp

#include <unordered_map>
#include <random>
#include "BaseAnt.hpp"


struct PointToPoint{
    double distanceToPoint = 0;
    double P = 0.2;
};

typedef unordered_set<ptrPoint, Point::SharedPtrHash, Point::SharedPtrEqual> setPoint;
typedef unordered_map<ptrPoint, unordered_map<ptrPoint, PointToPoint, Point::SharedPtrHash, Point::SharedPtrEqual>, Point::SharedPtrHash, Point::SharedPtrEqual> mapPoint;
typedef shared_ptr<mapPoint> mapPointPtr;

extern mapPointPtr fullDist;

class Ant : public virtual BaseAnt{
private:
    double distance = 0;
    double event = 0;
    double pheromones = 0;
    double funcP(const ptrPoint&);
    vector<ptrPoint> history;
    
protected:
    ptrPoint fromPoint = NULL;
    ptrPoint toPoint = NULL;
    virtual void nextVertex(ptrPoint&);
    virtual ptrPoint popVertex();

public:
    Ant();
    Ant(ptrPoint&, vector<ptrPoint>&);
    void next();
    double getDist();
    vector<ptrPoint>& getHistory();
};

#endif /* ClassAnt_hpp */
