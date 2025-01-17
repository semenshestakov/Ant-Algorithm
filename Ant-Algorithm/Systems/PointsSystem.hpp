//  Created by Семён Шестаков on 15.09.2024.

#ifndef PointSystem_hpp
#define PointSystem_hpp

#include "DrawPoint.hpp"
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
    draw::mapHashToPoint m_points = {};
    draw::mapPoint m_distances = {};
    
public: // Metods
    void add( const draw::ptrPoint& );
    void clear();
    draw::ptrPoint getPoint( const std::size_t );
    draw::mapHashToPoint& getMapPoints();
    draw::vectorPoint getVecPoints();
    draw::mapPointStruct& operator[]( const std::size_t );
};


extern PointsSystem pointSys;

} // end namespace systems

#endif /* PointSystem_hpp */
