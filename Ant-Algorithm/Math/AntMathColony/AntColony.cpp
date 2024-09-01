//  Created by Семён Шестаков on 30.12.2023.
#include "AntColony.hpp"


namespace math::alg::colony
{

// = = = = = = = = = = = = = = = = = = = =
//      Constructors and Distructors
// = = = = = = = = = = = = = = = = = = = =
AntColony::AntColony( std::vector< obj::ptrPoint >& vec )
{
    if ( vec.size() < 2 )
        throw "[ERROR] vec.size() <= 2\n";
    
    obj::fullDist = std::make_shared< math::mapPoint >();
    initAntVec( vec );
    calcDist( vec );
}

// = = = = = = = = = = = = = = = = = = = =
//           Math && Base Logic
// = = = = = = = = = = = = = = = = = = = =

/* 
 calc euclideanDistance many points to many points
 */
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
            ( *obj::fullDist )[ vec[ i ] ][ vec[ j ] ] = temp;
        }
    }
}


void AntColony::initAntVec( std::vector< obj::ptrPoint >& vec )
{
    for ( auto& elm : vec )
    {
        std::shared_ptr< Ant > temp = make_shared< Ant >( elm, vec );
        vecAnt.push_back( temp );
    }
}

/*
 iteration on vector Ant
 */
void AntColony::iteration()
{
    // Count iter
    if ( m_iter >= s_stopIter )
        return;
    ++m_iter;
    
    // The ants are passing a circle
    for ( auto& elm : vecAnt )
    {
        elm->next();
    }
    
    // Forget pheromones
    for ( auto& elm1 : obj::vecPoints )
    {
        for ( auto& elm2 : obj::vecPoints )
        {
            if (elm1 != elm2) 
                ( *obj::fullDist )[ elm1 ][ elm2 ].P *= gColonyConst.cP;
        }
    }
    
    // Update pheromones and best route
    for ( auto& elm : vecAnt )
    {
        if ( elm->getDistance() <= m_lengthRoute && elm->getDistance() != 0 )
        {
            m_iter = 0;
            m_lengthRoute = elm->getDistance();
            m_bestRoute = elm->getHistory();
            
            for ( size_t i = 1; i < elm->getHistory().size(); i++ )
            {
                auto& first = elm->getHistory()[ i - 1 ];
                auto& last = elm->getHistory()[ i ];
                
                double result = gColonyConst.Q / ( gColonyConst.dist / elm->getDistance() );
                result = std::min( result, gColonyConst.maxP );
                ( *obj::fullDist )[ first ][ last ].P += result;
                ( *obj::fullDist )[ last ][ first ].P += result;
            }
        }
    }
}

} // end math::alg::colony space
