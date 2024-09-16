//  Created by Семён Шестаков on 15.09.2024.

#ifndef PointSystem_hpp
#define PointSystem_hpp


#include "PointObject.hpp"
#include "ClassUtils.hpp"


namespace systems
{


class PointsSystem
{
public:
    PointsSystem();
    ~PointsSystem();
    
    DELETE_COPY_AND_MOVE(PointsSystem)
    
protected:
    std::vector< obj::ptrPoint > m_points;
    math::mapPoint m_distances;
    
public: // Metods
    void add( const obj::ptrPoint& );
    void clear();
    std::vector< obj::ptrPoint >& getPoints();
    math::structMapPoint operator[]( const obj::ptrPoint& );
};


extern PointsSystem pointSys;

} // end namespace systems

#endif /* PointSystem_hpp */
