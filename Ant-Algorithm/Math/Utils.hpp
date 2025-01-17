//
//  Utils.hpp
//  Ant-Algorithm
//
//  Created by Семён Шестаков on 02.06.2024.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <vector>


double maxP();

template < typename T >
bool elemInVector(const T& elem, const std::vector< T >& vec)
{
    for (auto& elemInVecor : vec)
    {
        if (elem == elemInVecor)
            return true;
    }
    
    return false;
}






#endif /* Utils_hpp */
