#include "draw.hpp"
#include "Utils.hpp"
#include "PointsSystem.hpp"


using namespace systems;


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
    
    for ( auto& [hash1, point1] : systems::pointSys.getMapPoints() )
    {
        for ( auto& [hash2, point2] : systems::pointSys.getMapPoints() )
        {
            sf::ConvexShape convex;
            Line( convex, point1->getVetrexDraw(), point2->getVetrexDraw() );
            
            float outlineThickness = ( systems::pointSys[ hash1 ][ hash2 ].P / _max + 2.0 ) * 0.7;
            convex.setOutlineThickness( outlineThickness );
            convex.setOutlineColor( draw::LineColors::standart );
            window.draw( convex );
        }
    }
}

// draw point on window
void drawPoints( sf::RenderWindow& win )
{
    for ( auto& [hash, point] : systems::pointSys.getMapPoints() ) 
    {
        win.draw( point->getCircle() );
    }
}


void math::alg::BaseAlgorithm::draw( sf::RenderWindow& window ) const
{
    for ( std::size_t i = 1; i < m_bestRoute.size(); i++ )
    {
        const std::size_t hash1 = m_bestRoute[ i - 1 ];
        const std::size_t hash2 = m_bestRoute[ i ];
        
        sf::ConvexShape convex;
        Line(
             convex,
             pointSys.getPoint( hash1 )->getVetrexDraw(), pointSys.getPoint( hash2 )->getVetrexDraw()
             );
            
        convex.setOutlineThickness( max_line_size );
        
        convex.setOutlineColor( draw::ColorLine::get( this->getType() ) );
        window.draw( convex );
    }
}



