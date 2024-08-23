//  Created by Семён Шестаков on 30.12.2023.
#include "AntColony.hpp"




AntColony::AntColony() {}


AntColony::AntColony( std::vector< obj::ptrPoint >& vec )
{
    if (vec.size() < 2) throw SizeError();
    
    fullDist = std::make_shared< math::mapPoint >();
    initAntVec( vec );
    calcDist( vec );
}


// calc euclideanDistance many points to many points
void AntColony::calcDist( std::vector< obj::ptrPoint >& vec )
{
    for ( size_t i = 0; i < vec.size(); i++ )
    {
        for ( size_t j = 0; j < vec.size(); j++ )
        {
            double t = 0.2;
            if ( i == j )
            {
                t = 0;
            }
            
            struct math::PointToPoint&& temp
            {
                .distanceToPoint = vec[i]->distance( *vec[j] ),
                .P = t
            };
            (*fullDist)[vec[i]][vec[j]] = std::move( temp );
        }
    }
}


// init vector Ant
void AntColony::initAntVec( std::vector< obj::ptrPoint >& vec )
{
    for ( auto& elm : vec )
    {
        std::shared_ptr< Ant > temp = make_shared< Ant >( elm, vec );
        vecAnt.push_back( temp );
    }
}


// iteration on std::vector Ant
void AntColony::iteration()
{
    for ( auto& elm : vecAnt )
    {
        elm->next();
    }
    
    for ( auto& elm1 : obj::vecPoints )
    {
        for ( auto& elm2 : obj::vecPoints )
        {
            if (elm1 != elm2) (*fullDist)[ elm1 ][ elm2 ].P *= cP;
        }
    }
    
    for ( auto& elm : vecAnt )
    {
        if ( elm->getDist() <= m_lengthRoute && elm->getDist() != 0 )
        {
            m_lengthRoute = elm->getDist();
            m_bestRoute = elm->getHistory();
            
            for ( size_t i = 1; i < elm->getHistory().size(); i++ )
            {
                auto& first = elm->getHistory()[ i - 1 ];
                auto& last = elm->getHistory()[ i ];
                
                double res = std::min( Q / ( DIST_CONST / elm->getDist() ), MAX_P );
                (*fullDist)[ first ][ last ].P += res;
                (*fullDist)[ last ][ first ].P += res;
            }
        }
    }
}


double Ant::funcP(const obj::ptrPoint& elm)
{
    return pow( static_cast< double >( ( *fullDist )[ toPoint ][ elm ].P ), alpha ) *
           pow( DIST_CONST / ( *fullDist )[ toPoint ][ elm ].distanceToPoint, beta );
}
