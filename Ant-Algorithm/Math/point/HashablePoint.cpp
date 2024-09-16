//  Created by Семён Шестаков on 23.08.2024.

#include "HashablePoint.hpp"

namespace math
{
// = = = = = = = = = = = = = = = = = = = =
//      Constructors and Distructors
// = = = = = = = = = = = = = = = = = = = =
HashablePoint::HashablePoint() : HashablePoint( 0, 0 ) {}


HashablePoint::HashablePoint(cord _x, cord _y) : math::Point(_x, _y)
{
    m_identifier = hash_point();
}


std::size_t HashablePoint::hash_point()
{
    size_t hashA = std::hash< cord >()( x );
    size_t hashB = std::hash< cord >()( y );
    return hashA ^ (( hashB + 1 ) + 0x9e3779b9 + (( hashA + 1 ) << 6) + (( hashA + 5 ) >> 2 ));
}

// = = = = = = = = = = = = = = = = = = = =
//                  Getters
// = = = = = = = = = = = = = = = = = = = =
std::size_t HashablePoint::getIdentifier() const 
{
    return m_identifier;
};


// = = = = = = = = = = = = = = = = = = = =
//                Operators
// = = = = = = = = = = = = = = = = = = = =
bool operator!=( const HashablePointPtr p1, const HashablePointPtr p2 )
{
    return p1->getIdentifier() != p2->getIdentifier();
}


bool HashablePoint::operator==( const HashablePointPtr other ) const
{
    return this->getIdentifier() == other->getIdentifier();
}


std::size_t HashablePoint::SharedPtrHash::operator()( const HashablePointPtr ptr ) const
{
    return ptr->m_identifier;
}


bool HashablePoint::SharedPtrEqual::operator()( const HashablePointPtr ptr1, const HashablePointPtr ptr2 ) const
{
    return ptr1->m_identifier == ptr2->m_identifier;
}
} // end math space
