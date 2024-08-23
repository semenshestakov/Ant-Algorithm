#include "Point.hpp"

namespace math
{
using std::cout, std::endl;


// = = = = = = = = = = = = = = = = = = = =
//      Constructors and Distructors
// = = = = = = = = = = = = = = = = = = = =
Point::Point( cord _x, cord _y ) : x( _x ), y( _y )
{
    cout << *this << endl;
}

Point::~Point()
{
    cout << '~' << *this << endl;
}


// - - - - - - - - - Math - - - - - - - - -
double Point::distance( const Point& other )
{
    return hypot( x - other.x, y - other.y );
}


// - - - - - - - - - Operators - - - - - - - - -
std::ostream& operator<<( std::ostream& os, const Point& point )
{
    os << "Point(" << point.x << ", " << point.y << ")";
    return os;
}

} // end math space
