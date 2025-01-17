//  Created by Семён Шестаков on 24.08.2024.


#ifndef DrawPoint_hpp
#define DrawPoint_hpp


#include "DrawConstans.hpp"
#include "Point.hpp"


namespace draw
{

using std::unordered_map, std::unordered_set;


class Point : virtual public math::Point
{
public:
    Point();
    Point( math::cord, math::cord );
    
protected:
    sf::Vector2f m_vecPoint;
    sf::CircleShape m_circle;
    sf::CircleShape drawPoint();
    
    static inline int s_radius = 8;
    
public:
    sf::CircleShape& getCircle();
    sf::Vector2f& getVetrexDraw();
};

typedef std::shared_ptr< Point > ptrPoint;

typedef unordered_set< std::size_t > setPoint;

typedef unordered_map< std::size_t, math::PointToPoint > mapPointStruct;

typedef unordered_map< std::size_t, ptrPoint > mapHashToPoint;

typedef unordered_map< std::size_t, mapPointStruct > mapPoint;

typedef std::vector< ptrPoint > vectorPoint;

typedef std::shared_ptr< mapPoint > mapPointPtr;

} // end drawer space
#endif /* DrawPoint_hpp */
