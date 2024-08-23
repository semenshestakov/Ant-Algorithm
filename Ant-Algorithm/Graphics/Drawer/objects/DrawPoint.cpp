//  Created by Семён Шестаков on 24.08.2024.
#include "DrawPoint.hpp"



namespace draw
{

// = = = = = = = = = = = = = = = = = = = =
//      Constructors and Distructors
// = = = = = = = = = = = = = = = = = = = =
Point::Point( math::cord _x, math::cord _y ) : math::Point( _x, _y)
{
    m_circle = drawPoint();
}

Point::Point() : Point( 0, 0 ) {}


sf::Vector2f Point::getVetrexDraw()
{
    return sf::Vector2f( x, y );
}

// = = = = = = = = = = = = = = = =
//            Geters
// = = = = = = = = = = = = = = = =
sf::CircleShape& Point::getCircle()
{
    return m_circle;
}


sf::CircleShape Point::drawPoint()
{
    sf::CircleShape circle;
    
    circle.setRadius( s_radius );
    circle.setFillColor( colorPoint );
    circle.setPosition( x - s_radius, y - s_radius );
    
    return circle;
}

} // end darw space

