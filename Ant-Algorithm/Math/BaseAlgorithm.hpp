//  Created by Семён Шестаков on 01.06.2024.
#ifndef BaseAlgorithm_hpp
#define BaseAlgorithm_hpp

#include <SFML/Graphics.hpp>
#include "PointObject.hpp"


class BaseAlgorithm 
{
public:
    virtual void iteration() = 0;
    virtual void draw( sf::RenderWindow& window ) const = 0;
    
protected:
    std::vector< obj::ptrPoint > m_bestRoute;
    double m_lengthRoute = 10e100;
    
public:
    virtual ~BaseAlgorithm() { m_bestRoute.clear(); }
};

#endif /* BaseAlgorithm_hpp */
