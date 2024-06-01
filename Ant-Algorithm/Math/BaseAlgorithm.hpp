//  Created by Семён Шестаков on 01.06.2024.
#ifndef BaseAlgorithm_hpp
#define BaseAlgorithm_hpp

#include <SFML/Graphics.hpp>
#include "point.hpp"


class BaseAlgorithm 
{
public:
    virtual void iteration() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
protected:
    vector<ptrPoint> __bestRoute;
    double __lengthRoute = 10e100;
public:
    virtual ~BaseAlgorithm() { __bestRoute.clear(); }
};

#endif /* BaseAlgorithm_hpp */
