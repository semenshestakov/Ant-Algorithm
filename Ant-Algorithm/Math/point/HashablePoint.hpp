//
//  HashablePoint.hpp
//  Ant-Algorithm
//
//  Created by Семён Шестаков on 23.08.2024.
//

#ifndef HashablePoint_hpp
#define HashablePoint_hpp

#include <functional>
#include "Point.hpp"


namespace math
{

class HashablePoint;
typedef std::shared_ptr< HashablePoint > HashablePointPtr;


class HashablePoint : virtual public math::Point
{    
public:
    HashablePoint();
    HashablePoint( cord, cord );
    ~HashablePoint() = default;
    std::size_t getIdentifier() const;
    
protected:
    std::size_t m_identifier;
    std::size_t hash_point();
    
public:
    struct SharedPtrHash
    {
        size_t operator()( const HashablePointPtr ) const;
    };
    
    struct SharedPtrEqual
    {
        bool operator()( const HashablePointPtr, const HashablePointPtr ) const;
    };

    bool operator==( const HashablePointPtr ) const;
};


bool operator!=( const HashablePointPtr, const HashablePointPtr );


struct PointToPoint
{
    double distance = 0;
    double P = 0.2;
};


#include "HashablePoint.ipp" // definds
} // end namespace math

#endif /* HashablePoint_hpp */
