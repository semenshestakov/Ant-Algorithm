//  Created by Семён Шестаков on 15.09.2024.

#include "PointsSystem.hpp"
#include "draw.hpp"


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
void PointsSystem::add( const obj::ptrPoint& newPoint )
{
    m_points.push_back( newPoint );
    for ( const auto& point : m_points )
    {
        double startProbability = 0.2;
        if ( newPoint == point )
        {
            startProbability = 0;
        }
        
        struct math::PointToPoint temp
        {
            .distance = newPoint->distance( *point ),
            .P = startProbability
        };
        m_distances[ newPoint ][ point ] = temp;
        m_distances[ point ][ newPoint ] = temp;
    }
}


// = = = = = = = = = = = = = = = = = = = =
//                 Geters
// = = = = = = = = = = = = = = = = = = = =
math::structMapPoint PointsSystem::operator[]( const obj::ptrPoint& point )
{
    return m_distances[ point ];
}

std::vector< obj::ptrPoint >& PointsSystem::getPoints()
{
    return m_points;
}

} // end namespace systems
