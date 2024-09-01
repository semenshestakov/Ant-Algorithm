//  Created by Семён Шестаков on 19.05.2024.
#include "BrutForce.hpp"


namespace math::alg
{

using std::cout, std::endl;


BrutForce::BrutForce( std::vector< obj::ptrPoint >& points )
{
    for ( auto& point : points )
    {
        m_vectorPoints.push_back(point);
    }
}


void BrutForce::iteration()
{
    if ( m_isFinded || m_vectorPoints.size() > m_maxLenRoute )
        return;
    
    for ( std::size_t i = 0; i < m_vectorPoints.size(); i++)
    {
        std::vector< obj::ptrPoint > tempPoints = { m_vectorPoints[i] };
        _recursion( tempPoints, 0.0 );
        
    }
    m_isFinded = true;
}


void BrutForce::_recursion( std::vector< obj::ptrPoint >& points, double length )
{
    if ( points.size() > m_vectorPoints.size() )
        throw "points.size() > m_bestRoute.size()";
    
    if ( length > m_lengthRoute )
        return;
    
    if ( points.size() == m_vectorPoints.size() )
    {
        length += points[ 0 ]->distance( *( points[ points.size() - 1 ] ) );
        points.push_back( points[ 0 ] );
        if ( length < m_lengthRoute )
        {
            m_lengthRoute = length;
            m_bestRoute = points;
        }
        return;
    }
    
    for ( auto& pointMain : m_vectorPoints )
    {
        if ( elemInVector( pointMain, points ) )
            continue;
        
        std::vector< obj::ptrPoint > pointsTemp = points;
        double tempLength = pointsTemp[ pointsTemp.size() - 1 ]->distance( *pointMain ) + length;
        
        pointsTemp.push_back(pointMain);
        
        _recursion(pointsTemp, tempLength);
    }
}

} // end space math::alg
