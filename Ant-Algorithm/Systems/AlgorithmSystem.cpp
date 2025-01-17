//  Created by Семён Шестаков on 01.06.2024.
#include "AlgorithmSystem.hpp"

namespace systems
{


AlgorithmSystem::~AlgorithmSystem()
{
    for ( auto alg : vectorAlgs )
    {
        delete alg;
    }
    vectorAlgs.clear();
}


void AlgorithmSystem::add( math::alg::BaseAlgorithm* alg )
{
    vectorAlgs.push_back( alg );
}


void AlgorithmSystem::iteration()
{
    for ( auto& alg : vectorAlgs )
    {
        alg->iteration();
    }
}


void AlgorithmSystem::draw(sf::RenderWindow& window)
{
    for (auto& alg : vectorAlgs)
    {
        alg->draw( window );
    }
}

} // end namespace systems
