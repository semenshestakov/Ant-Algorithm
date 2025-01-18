#include "Point.hpp"
#include "LogUtils.hpp"

namespace math
{
using std::cout, std::endl;


// = = = = = = = = = = = = = = = = = = = =
//      Constructors and Distructors
// = = = = = = = = = = = = = = = = = = = =
Point::Point( cord _x, cord _y ) : x( _x ), y( _y )
{
    LOG_INFO( "%s", toString().c_str() );
}

Point::~Point()
{
    LOG_INFO( "~%s", toString().c_str() );
}


// - - - - - - - - - Math - - - - - - - - -
[[nodiscard]] double Point::distance( const Point& other )
{
    return hypot( x - other.x, y - other.y );
}


// - - - - - - - - - Operators - - - - - - - - -
std::ostream& operator<<( std::ostream& os, const Point& point )
{
    os << point.toString();
    return os;
}

std::string Point::toString() const 
{
    return "Point(" + std::to_string( x ) + ", " + std::to_string( y ) + ")::hash-" + std::to_string( hash );
}

} // end math space
