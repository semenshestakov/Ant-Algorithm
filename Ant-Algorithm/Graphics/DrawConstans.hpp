//  Created by Семён Шестаков on 25.08.2024.
#ifndef DrawConstans_hpp
#define DrawConstans_hpp


#include <SFML/Graphics.hpp>


namespace draw
{

typedef const sf::Color Color_t;

struct LineColors
{
    inline static Color_t standart      = sf::Color(230, 175, 44);
    inline static Color_t antColony     = sf::Color(235, 53, 89);
    inline static Color_t brutForce     = sf::Color(0, 200, 0);
    inline static Color_t bestRote      = sf::Color(58, 202, 138);
};


Color_t colorPoint          = sf::Color(79,127,198); //  = sf::Color(235, 53, 89);
Color_t windowBackground    = sf::Color(221,221,221);


} // end draw space

#endif /* DrawConstans_hpp */
