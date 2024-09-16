//  Created by Семён Шестаков on 17.11.2023.
#ifndef draw_hpp
#define draw_hpp

#include "AntColony.hpp"
#include "BrutForce.hpp"
#include "DrawConstans.hpp"


#define MAX_LINE 5.0


void drawLines( sf::RenderWindow& );
void drawVecPoints( sf::RenderWindow& );

namespace draw
{

struct ColorLine
{
    inline static draw::Color_t colorsByType[ math::alg::AlgorithmTypes::MAX_VALUE ] =  // AlgorithmTypes
    {
        LineColors::standart,
        LineColors::antColony,
        LineColors::brutForce
    };
    
    template < typename T >
    static Color_t& get( T index )
    {
        return colorsByType[ index ];
    };
    
};
}; // end Draw

#endif /* draw_hpp */
