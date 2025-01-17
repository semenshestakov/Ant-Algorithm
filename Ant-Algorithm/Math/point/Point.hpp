//  Created by Семён Шестаков on 11.11.2023.
#ifndef point_hpp
#define point_hpp

#include <cmath>
#include <memory>
#include <iostream>
#include <stdio.h>
#include <exception>
#include <unordered_map>
#include <unordered_set>


namespace math 
{

typedef int cord;


class Point
{
public:
    Point() : Point( 0, 0 ) {};
    Point( cord, cord );
    virtual ~Point();
    
    union {
        struct {
            const cord x; const cord y;
        };
        const std::size_t hash;
    };
    
    // - - - - - - Math - - - - - -
    [[nodiscard]] double distance( const Point& );
    
    // - - - - - Operators - - - - -
    friend std::ostream& operator<<( std::ostream&, const Point& );
};


struct PointToPoint
{
    double distance = 0;
    double P = 0.2;
};

} // end space math
#endif /* point_hpp */
