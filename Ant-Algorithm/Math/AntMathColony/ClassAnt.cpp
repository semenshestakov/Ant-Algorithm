//  Created by Семён Шестаков on 12.11.2023.
#include "ClassAnt.hpp"
#include "PointsSystem.hpp"


namespace math::alg::colony
{

// = = = = = = = = = = = = = = = = = = = =
//      Constructors and Distructors
// = = = = = = = = = = = = = = = = = = = =

Ant::Ant( draw::ptrPoint& start, draw::vectorPoint& vec)
{
    if ( vec.size() <= 2 )
        throw "[ERROR] vec.size() <= 2\n";
    
    m_start = start->hash;
    for ( std::size_t i = 0; i < vec.size(); i++ )
    {
        if ( vec[ i ] != start )
        {
            m_noVisit->insert( vec[ i ]->hash );
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
void Ant::nextVertex( std::size_t newPoint )
{
    if (newPoint == 0)
    {
        throw "";
    }
    m_fromPoint = m_toPoint;
    m_toPoint = newPoint;
    m_distance += systems::pointSys[ m_fromPoint ][ m_toPoint ].distance;
    m_pheromones += systems::pointSys[ m_fromPoint ][ m_toPoint ].P;
    m_history.push_back( newPoint );
}

/*
 @ raise next Point and del elem in m_noVisit and add elem m_visit
 */
std::size_t Ant::popVertex()
{
    std::size_t count { m_noVisit->size() }, index { 0 };
    double localSum { 0 }, generalSum { 0 };
    std::vector< double > m_probability( count, 0 );
    
    // Generate random value
    double _rand = static_cast< double >( std::rand() ) / RAND_MAX;
    
    for ( auto& point : *(m_noVisit) )
    {
        m_probability[ index ] = calculateProbability( point );
        generalSum += m_probability[ index ];
        index++;
    }
    
    index = 0;
    for ( const std::size_t pointHash : *m_noVisit )
    {
        localSum += ( m_probability[ index ] / generalSum );
        
        if ( _rand <= localSum )
        {
            auto findedPointHash = m_noVisit->find( pointHash );
            if ( findedPointHash != m_noVisit->end() )
            {
                m_visit->insert( pointHash );
                m_noVisit->erase( findedPointHash );
                
                return pointHash;
            }
        }
        index++;
    }
    
    
    auto firstPoint = m_noVisit->begin();
    std::size_t pointHash = *firstPoint;
    
    m_visit->insert( pointHash );
    m_noVisit->erase( firstPoint );
    
    return pointHash;
}

/*
 @ For this method, the ant goes full circle
 */
void Ant::next()
{
    m_distance = m_pheromones = 0;
    m_history.clear();
    
    m_toPoint = m_fromPoint = m_start;
    m_history.push_back( m_start );
    
    while ( !m_noVisit->empty() )
    {
        std::size_t temp = popVertex();
        nextVertex( temp );
    }
    
    nextVertex( m_start );
    m_noVisit.swap( m_visit );
}

/*
 calculate probability between the points
 F_p(p1, p2) = ( p12.pheromone ^ alpha ) * ( p12.dist ^ beta )
 */
double Ant::calculateProbability( const std::size_t keyPoint )
{
    math::PointToPoint params = systems::pointSys[ m_toPoint ][ keyPoint ];
    
    return pow( static_cast< double >( params.P ), gColonyConst.alpha ) *
        pow( gColonyConst.dist / params.distance, gColonyConst.beta );
}


// = = = = = = = = = = = = = = = = = = = =
//               GETERS
// = = = = = = = = = = = = = = = = = = = =
double Ant::getDistance()
{
    return m_distance;
}

std::vector< std::size_t >& Ant::getHistory()
{
    return m_history;
}

} // end math::alg::colony space
