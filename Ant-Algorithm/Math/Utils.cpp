//  Created by Семён Шестаков on 02.06.2024.

#include "Utils.hpp"
#include "PointObject.hpp"


double maxP()
{
    double _max = 0, n = 1;
    
    for (auto& elm1 : obj::vecPoints)
    {
        for (auto& elm2 : obj::vecPoints)
        {
            if (_max < ( *obj::fullDist )[ elm1 ][ elm2 ].P)
            {
                _max += ( *obj::fullDist )[ elm1 ][ elm2 ].P;
            }
            n++;
        }
    }
    return _max;
}
