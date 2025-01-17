//  Created by Семён Шестаков on 15.09.2024.

#include "PointsSystem.hpp"
#include "draw.hpp"
#include <ranges>


namespace systems
{

PointsSystem pointSys;
using std::cout, std::endl;

// = = = = = = = = = = = = = = = = = = = =
//      Constructors and Distructor
// = = = = = = = = = = = = = = = = = = = =
PointsSystem::PointsSystem()
{
    std::cout << "PointsSystem()" << std::endl;
}

PointsSystem::~PointsSystem()
{
    std::cout << "~PointsSystem()" << std::endl;
    this->clear();
}

void PointsSystem::clear()
{
    m_distances.clear();
    m_points.clear();
}

// = = = = = = = = = = = = = = = = = = = =
//           Math && Base Logic
// = = = = = = = = = = = = = = = = = = = =
void PointsSystem::add( const draw::ptrPoint& newPoint )
{
    m_points[ newPoint->hash ] = newPoint;
    
    for ( const auto& [hash, point] : m_points )
    {
        double startProbability = 0.2;
        if ( newPoint->hash == point->hash )
        {
            startProbability = 0;
        }
        
        struct math::PointToPoint temp
        {
            .distance = newPoint->distance( *point ),
            .P = startProbability
        };
        m_distances[ newPoint->hash ][ point->hash ] = temp;
        m_distances[ point->hash ][ newPoint->hash ] = temp;
    }
}


// = = = = = = = = = = = = = = = = = = = =
//                 Geters
// = = = = = = = = = = = = = = = = = = = =
draw::mapPointStruct& PointsSystem::operator[]( const std::size_t key )
{
    return m_distances[ key ];
}

draw::ptrPoint PointsSystem::getPoint( const std::size_t hash )
{
    return m_points[ hash ];
}

draw::mapHashToPoint& PointsSystem::getMapPoints()
{
    return m_points;
}

draw::vectorPoint PointsSystem::getVecPoints()
{
    draw::vectorPoint vecPoints;
    vecPoints.reserve( m_points.size() );

    for ( const auto& [ key, value ] : m_points )
    {
        vecPoints.push_back( value );
    }

    return vecPoints;
}

} // end namespace systems
