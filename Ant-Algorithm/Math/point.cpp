#include "point.hpp"

vector<ptrPoint> vecPoints;
// Constructor Point(cord, cord)
Point::Point(cord x, cord y){    
    _x = x - RADIUS;
    _y = y - RADIUS;
    _circle = drawPoint();
    _identifier = hash_point();
    cout << *this << endl;
}

Point::~Point(){
    cout << '~' << *this << endl;
}

// calc Distance this to Point
double Point::euclideanDistance( const Point& p )
{
    return hypot(_x - p._x, _y - p._y);
}

// get figure
sf::CircleShape& Point::getCircle(){ return _circle; }

// raise hash for Point
size_t Point::getIdentifier()const { return _identifier; };
sf::Vector2f Point::getVetrexDraw()
{
    return sf::Vector2f(_x + RADIUS, _y + RADIUS);
}

// func calc Point this to Point
double euclideanDistance( const Point& p1, const Point& p2 ){
    return hypot(p1._x - p2._x, p1._y - p2._y);;
}

// cacl hash for Point
size_t Point::hash_point()
{
    size_t hashA = hash<cord>()(_x);
    size_t hashB = hash<cord>()(_y);
    return hashA ^ ((hashB + 1) + 0x9e3779b9 + ((hashA + 1) << 6) + ((hashA + 5)>> 2));
}

// no-equel Identifier
bool operator!=(const Point& p1,const Point& p2)
{
    return p1.getIdentifier() != p2.getIdentifier();
}

// equel Identifier
bool Point::operator==( const Point& other ) const 
{
    return this->getIdentifier() == other.getIdentifier();
}

// cout <<
ostream& operator<<( ostream& os, const Point& point )
{
    os << "Point(" << point._x << ", " << point._y << ")";
    return os;
}

size_t Point::operator()(const Point& p) const { return _identifier; }

// for Hash
size_t Point::SharedPtrHash::operator()(const ptrPoint& ptr) const
{
    return ptr->_identifier;
}

bool Point::SharedPtrEqual::operator()(const ptrPoint& ptr1, const ptrPoint& ptr2) const
{
    return ptr1->_identifier == ptr2->_identifier;
    
}
cord Point::getX(){ return _x; }
cord Point::getY(){ return _y; }
