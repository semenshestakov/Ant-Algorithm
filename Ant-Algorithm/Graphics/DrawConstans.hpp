//  Created by Семён Шестаков on 25.08.2024.
#ifndef DrawConstans_hpp
#define DrawConstans_hpp


#include <SFML/Graphics.hpp>


namespace draw
{

typedef const sf::Color Color_t;


Color_t colorLine           = sf::Color(230, 175, 44);
Color_t colorBrutForceLine  = sf::Color(0, 200, 0);
Color_t colorLineBest       = sf::Color(58, 202, 138);
Color_t colorPoint          = sf::Color(79,127,198); //  = sf::Color(235, 53, 89);
Color_t windowBackground    = sf::Color(221,221,221);

} // end draw space

#endif /* DrawConstans_hpp */
