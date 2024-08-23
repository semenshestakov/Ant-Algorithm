//  Created by Семён Шестаков on 12.11.2023.
#ifndef ClassAnt_hpp
#define ClassAnt_hpp

#include <random>
#include "BaseAnt.hpp"


//typedef unordered_set<obj::ptrPoint, Point::SharedPtrHash, Point::SharedPtrEqual> setPoint;
//typedef unordered_map<obj::ptrPoint, unordered_map<obj::ptrPoint, PointToPoint, Point::SharedPtrHash, Point::SharedPtrEqual>, Point::SharedPtrHash, Point::SharedPtrEqual> mapPoint;
//typedef shared_ptr<mapPoint> mapPointPtr;

extern math::mapPointPtr fullDist;

class Ant : public virtual BaseAnt
{
private:
    double distance = 0;
    double event = 0;
    double pheromones = 0;
    double funcP( const obj::ptrPoint& );
    std::vector< obj::ptrPoint > history;
    
protected:
    obj::ptrPoint fromPoint = NULL;
    obj::ptrPoint toPoint = NULL;
    virtual void nextVertex( obj::ptrPoint& );
    virtual obj::ptrPoint popVertex();

public:
    Ant();
    Ant( obj::ptrPoint&, std::vector< obj::ptrPoint >& );
    void next();
    double getDist();
    std::vector< obj::ptrPoint >& getHistory();
};

#endif /* ClassAnt_hpp */
