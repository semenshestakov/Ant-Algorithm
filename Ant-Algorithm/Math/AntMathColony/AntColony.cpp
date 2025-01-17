//  Created by Семён Шестаков on 30.12.2023.
#include "AntColony.hpp"
#include "PointsSystem.hpp"


namespace math::alg::colony
{

// = = = = = = = = = = = = = = = = = = = =
//      Constructors and Distructors
// = = = = = = = = = = = = = = = = = = = =
AntColony::AntColony( draw::vectorPoint& vec )
{
    if ( vec.size() < 2 )
        throw "[ERROR] vec.size() <= 2\n";
    
    for ( auto& elm : vec )
    {
        std::shared_ptr< Ant > temp = make_shared< Ant >( elm, vec );
        vecAnt.push_back( temp );
    }
}

// = = = = = = = = = = = = = = = = = = = =
//           Math && Base Logic
// = = = = = = = = = = = = = = = = = = = =

/*
 iteration on vector Ant
 */
void AntColony::iteration()
{
    // Count iter
    if ( m_iter >= s_stopIter )
    {
        return;
    }
    ++m_iter;
    
    // The ants are passing a circle
    for ( auto& elm : vecAnt )
    {
        elm->next();
    }
    
    // Forget pheromones
    for ( auto& [hash1, point1] : systems::pointSys.getMapPoints() )
    {
        for ( auto& [hash2, point2] : systems::pointSys.getMapPoints() )
        {
            if ( hash1 != hash2 )
            {
                systems::pointSys[ hash1 ][ hash2 ].P *= gColonyConst.cP;
            }
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
                systems::pointSys[ first ][ last ].P += result;
                systems::pointSys[ last ][ first ].P += result;
            }
        }
    }
}

} // end math::alg::colony space
