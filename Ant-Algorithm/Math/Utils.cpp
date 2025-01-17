//  Created by Семён Шестаков on 02.06.2024.

#include "Utils.hpp"
#include "DrawPoint.hpp"
#include "PointsSystem.hpp"


double maxP()
{
    double _max = 0, n = 1;
    
    for ( const auto& [hash1, point1] : systems::pointSys.getMapPoints() )
    {
        for ( const auto& [hash2, point2] : systems::pointSys.getMapPoints() )
        {
            double pointToPointRes = systems::pointSys[ hash1 ][ hash2 ].P;
            if ( _max < pointToPointRes )
            {
                _max += pointToPointRes;
            }
            n++;
        }
    }
    return _max;
}
