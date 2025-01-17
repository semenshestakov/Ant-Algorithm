//  Created by Семён Шестаков on 17.11.2023.
#ifndef draw_hpp
#define draw_hpp

#include "AntColony.hpp"
#include "BrutForce.hpp"
#include "DrawConstans.hpp"


constexpr float max_line_size = 5.0;


void drawLines( sf::RenderWindow& );
void drawPoints( sf::RenderWindow& );

namespace draw
{

struct ColorLine
{
    inline static draw::Color_t s_colorsByType[ math::alg::AlgorithmTypes::MAX_VALUE ] =  // AlgorithmTypes
    {
        LineColors::standart,
        LineColors::antColony,
        LineColors::brutForce
    };
    
    static Color_t& get( const int index )
    {
        return s_colorsByType[ index ];
    };
    
};
}; // end Draw

#endif /* draw_hpp */
