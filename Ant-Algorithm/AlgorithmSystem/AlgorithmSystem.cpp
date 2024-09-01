//  Created by Семён Шестаков on 01.06.2024.
#include "AlgorithmSystem.hpp"


AlgorithmSystem::~AlgorithmSystem()
{
    std::cout << "~AlgorithmSystem" << std::endl;
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
