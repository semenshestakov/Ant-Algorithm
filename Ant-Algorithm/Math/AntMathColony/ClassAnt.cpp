//  Created by Семён Шестаков on 12.11.2023.
#include "ClassAnt.hpp"
#include "PointsSystem.hpp"


namespace math::alg::colony
{
using std::static_pointer_cast;


// = = = = = = = = = = = = = = = = = = = =
//      Constructors and Distructors
// = = = = = = = = = = = = = = = = = = = =
Ant::Ant( obj::ptrPoint& start, std::vector< obj::ptrPoint >& vec)
{
    if ( vec.size() <= 2 )
        throw "[ERROR] vec.size() <= 2\n";
    
    this->m_start = start;
    for ( std::size_t i = 0; i < vec.size(); i++ )
    {

        if ( vec[ i ] != start )
        {
            auto hashablePointPtr = static_pointer_cast< math::HashablePoint >( vec[ i ] );
            m_noVisit->insert( hashablePointPtr );
        }
    }
    
    m_fromPoint = m_start;
    m_toPoint = m_start;
}


// = = = = = = = = = = = = = = = = = = = =
//              Math Logic Ant
// = = = = = = = = = = = = = = = = = = = =
/*
 @ flip toPoint and fromPoint with new point (next)
 */
void Ant::nextVertex( obj::ptrPoint& newPoint )
{
    m_fromPoint = m_toPoint;
    m_toPoint = newPoint;
    m_distance += systems::pointSys[ m_fromPoint ][ m_toPoint ].distance;
    m_pheromones += systems::pointSys[ m_fromPoint ][ m_toPoint ].P;
    m_history.push_back( newPoint );
}

/*
 @ raise next Point and del elem in m_noVisit and add elem m_visit
 */
obj::ptrPoint Ant::popVertex()
{
    std::size_t count { m_noVisit->size() }, index { 0 };
    double localSum { 0 }, generalSum { 0 };
    std::vector< double > m_probability( count, 0 );
    
    // Generate random value
    double _rand = static_cast< double >( rand() ) / RAND_MAX;
    
    for ( auto& elm : *(m_noVisit) )
    {
        obj::ptrPoint temp = static_pointer_cast< obj::Point >( elm );
        m_probability[ index++ ] = calculateProbability( temp );
        generalSum += m_probability[ index - 1 ];
    }
    
    index = 0;
    for ( auto& point : *m_noVisit )
    {
        localSum += ( m_probability[ index ] / generalSum );
        
        if ( _rand <= localSum )
        {
            auto findedPoint = m_noVisit->find( point );
            if ( findedPoint != m_noVisit->end() )
            {
                obj::ptrPoint result = static_pointer_cast< obj::Point >( point );
                
                m_visit->insert( result );
                m_noVisit->erase( findedPoint );
                
                return result;
            }
        }
        index++;
    }
    
    auto firstPoint = m_noVisit->begin();
    math::HashablePointPtr result = *firstPoint;
    m_visit->insert( result );
    m_noVisit->erase( firstPoint );
    
    return std::static_pointer_cast< obj::Point >( result );
}

/*
 @ For this method, the ant goes full circle
 */
void Ant::next()
{
    m_distance = m_pheromones = 0;
    m_history.clear();
    m_history.push_back( m_start );
    
    while ( !m_noVisit->empty() )
    {
        obj::ptrPoint temp = popVertex();
        nextVertex( temp );
    }
    
    nextVertex( m_start );
    m_noVisit.swap( m_visit );
}

/*
 calculate probability between the points
 F_p(p1, p2) = ( p12.pheromone ^ alpha ) * ( p12.dist ^ beta )
 */
double Ant::calculateProbability( const obj::ptrPoint& point )
{
    return pow( static_cast< double >( systems::pointSys[ m_toPoint ][ point ].P ), gColonyConst.alpha ) *
        pow( gColonyConst.dist / systems::pointSys[ m_toPoint ][ point ].distance, gColonyConst.beta );
}


// = = = = = = = = = = = = = = = = = = = =
//               GETERS
// = = = = = = = = = = = = = = = = = = = =
double Ant::getDistance()
{
    return m_distance;
}

std::vector< obj::ptrPoint >& Ant::getHistory()
{
    return m_history;
}

} // end math::alg::colony space
