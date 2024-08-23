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
using std::unordered_map, std::unordered_set;


class Point
{
public:
    Point() : Point( 0, 0 ) {};
    Point( cord, cord );
    virtual ~Point();
    
    cord x, y;
    
    // - - - - - - Math - - - - - -
    double distance( const Point& );
    
    // - - - - - Operators - - - - -
    friend std::ostream& operator<<( std::ostream&, const Point& );
};

} // end space math
#endif /* point_hpp */
