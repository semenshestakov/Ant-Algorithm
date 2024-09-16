#include "draw.hpp"
#include "Utils.hpp"
#include "PointsSystem.hpp"


// help function
sf::ConvexShape& Line( sf::ConvexShape& convex, const sf::Vector2f v1, const sf::Vector2f v2 )
{
    convex.setPointCount(4);
    convex.setPoint(0, v1);
    convex.setPoint(1, v1);
    convex.setPoint(2, v2);
    convex.setPoint(3, v2);
     
    return convex;
}

// draw full lines
void drawLines( sf::RenderWindow& window )
{
    double _max = maxP() + 0.01;
    
    for ( auto& point1 : systems::pointSys.getPoints() )
    {
        for ( auto& point2 : systems::pointSys.getPoints() )
        {
            sf::ConvexShape convex;
            Line( convex, point1->getVetrexDraw(), point2->getVetrexDraw() );
            
            float outlineThickness = ( systems::pointSys[ point1 ][ point2 ].P / _max + 2.0 ) * 0.7;
            convex.setOutlineThickness( outlineThickness );
            convex.setOutlineColor( draw::LineColors::standart );
            window.draw( convex );
        }
    }
}

// draw point on window
void drawVecPoints( sf::RenderWindow& win )
{
    for ( auto& point : systems::pointSys.getPoints() ) 
    {
        win.draw( point->getCircle() );
    }
}


void math::alg::BaseAlgorithm::draw( sf::RenderWindow& window ) const
{
    for ( std::size_t i = 1; i < m_bestRoute.size(); i++ )
    {
        auto& point1 = m_bestRoute[ i - 1 ];
        auto& point2 = m_bestRoute[ i ];
        
        sf::ConvexShape convex;
        Line(convex, point1->getVetrexDraw(), point2->getVetrexDraw());
            
        float outlineThickness = MAX_LINE;
        convex.setOutlineThickness( outlineThickness );
        
        convex.setOutlineColor( draw::ColorLine::get < int >( this->getType() ) );
        window.draw( convex );
    }
}



