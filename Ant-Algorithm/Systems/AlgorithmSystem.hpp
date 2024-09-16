//  Created by Семён Шестаков on 01.06.2024.
#ifndef AlgorithmSystem_hpp
#define AlgorithmSystem_hpp

#include <vector>
#include <memory>
#include <functional>
#include "../Math/BaseAlgorithm.hpp"
#include "ClassUtils.hpp"

namespace systems
{

using std::unique_ptr, std::make_unique, std::vector;


class AlgorithmSystem
{
private:
    vector< math::alg::BaseAlgorithm* > vectorAlgs;
    
public:
    AlgorithmSystem() = default;
    ~AlgorithmSystem();
    
    DELETE_COPY_AND_MOVE(AlgorithmSystem)
    
public: // Metods
    void add( math::alg::BaseAlgorithm* );
    void iteration();
    void draw( sf::RenderWindow& );
    
};

typedef unique_ptr< AlgorithmSystem >  AlgorithmSystemPtr;

} // end namespace systems
#endif /* AlgorithmSystem_hpp */
