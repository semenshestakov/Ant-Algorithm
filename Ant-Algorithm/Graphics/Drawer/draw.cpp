#include "draw.hpp"
#include "Utils.hpp"


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
void drawLines(sf::RenderWindow& window)
{
    double _max = maxP() + 0.01;
    
    for (auto& elm1 : obj::vecPoints)
    {
        for (auto& elm2 : obj::vecPoints)
        {
            sf::ConvexShape convex;
            Line( convex, elm1->getVetrexDraw(), elm2->getVetrexDraw() );
            
            float outlineThickness = ( ( *obj::fullDist )[ elm1 ][ elm2 ].P / _max + 2.0 ) * 0.7;
            convex.setOutlineThickness( outlineThickness );
            convex.setOutlineColor( draw::LineColors::standart );
            window.draw( convex );
        }
    }
}

// draw point on window
void drawVecPoints(sf::RenderWindow& win)
{
    for (auto& elm : obj::vecPoints) 
    {
        win.draw( elm->getCircle() );
    }
}


void math::alg::BaseAlgorithm::draw( sf::RenderWindow& window ) const
{
    for (size_t i = 1; i < m_bestRoute.size(); i++)
    {
        auto& elm1 = m_bestRoute[ i - 1 ];
        auto& elm2 = m_bestRoute[ i ];
        
        sf::ConvexShape convex;
        Line(convex, elm1->getVetrexDraw(), elm2->getVetrexDraw());
            
        float outlineThickness = MAX_LINE;
        convex.setOutlineThickness( outlineThickness );
        
        convex.setOutlineColor( draw::ColorLine::get < int >( this->getType() ) );
        window.draw(convex);
    }
}



