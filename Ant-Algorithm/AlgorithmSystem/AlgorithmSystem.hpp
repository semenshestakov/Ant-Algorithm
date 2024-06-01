//  Created by Семён Шестаков on 01.06.2024.
#ifndef AlgorithmSystem_hpp
#define AlgorithmSystem_hpp

#include <vector>
#include <memory>
#include <functional>
#include "../Math/BaseAlgorithm.hpp"


using std::unique_ptr, std::make_unique, std::vector;

class AlgorithmSystem
{
private:
    vector<BaseAlgorithm*> vectorAlgs;
    
public:
    AlgorithmSystem() = default;
    ~AlgorithmSystem();
    void add(BaseAlgorithm*);
    void iteration();
    void draw(sf::RenderWindow&);
    
};


#endif /* AlgorithmSystem_hpp */
