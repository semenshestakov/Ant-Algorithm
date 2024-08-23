//  Created by Семён Шестаков on 24.08.2024.


#ifndef DrawPoint_hpp
#define DrawPoint_hpp


#include "DrawConstans.hpp"
#include "Point.hpp"


namespace draw
{

class Point : virtual public math::Point
{
public:
    Point();
    Point( math::cord, math::cord );
    
protected:
    sf::CircleShape m_circle;
    sf::CircleShape drawPoint();
    static inline int s_radius = 8;
    
public:
    sf::CircleShape& getCircle();
    sf::Vector2f getVetrexDraw();
};


} // end drawer space
#endif /* DrawPoint_hpp */
