//  Created by Семён Шестаков on 19.05.2024.
#ifndef BrutForce_hpp
#define BrutForce_hpp

#include "point.hpp"

class BrutForce
{
private:
    class BrutForceConstructor : public exception {};
    double _lengthRoute = 0;
    uint _len = 0;
    vector<ptrPoint> _bestRoute;
    
public:
    BrutForce() { throw BrutForceConstructor(); };
    BrutForce( vector<ptrPoint>& );
    void iter();
};


#endif /* BrutForce_hpp */
