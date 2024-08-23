//
//  PointObject.hpp
//  Ant-Algorithm
//
//  Created by Семён Шестаков on 01.09.2024.
//

#ifndef PointObject_hpp
#define PointObject_hpp

#include "HashablePoint.hpp"
#include "DrawPoint.hpp"

namespace obj
{


class Point : public draw::Point, public math::HashablePoint
{
public:
    Point() : Point ( 0 , 0 ) {}
    Point( math::cord _x, math::cord _y ) : math::Point( _x, _y ), math::HashablePoint( _x, _y ), draw::Point( _x , _y ) {}
};


typedef std::shared_ptr< Point > ptrPoint;
extern std::vector< ptrPoint > vecPoints;
}

#endif /* PointObject_hpp */
