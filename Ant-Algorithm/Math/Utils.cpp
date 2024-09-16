//  Created by Семён Шестаков on 02.06.2024.

#include "Utils.hpp"
#include "PointObject.hpp"
#include "PointsSystem.hpp"


double maxP()
{
    double _max = 0, n = 1;
    
    for ( const auto& point1 : systems::pointSys.getPoints() )
    {
        for ( const auto& point2 : systems::pointSys.getPoints() )
        {
            if ( _max < systems::pointSys[ point1 ][ point2 ].P )
            {
                _max += systems::pointSys[ point1 ][ point2 ].P;
            }
            n++;
        }
    }
    return _max;
}
