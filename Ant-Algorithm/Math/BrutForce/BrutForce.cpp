//  Created by Семён Шестаков on 19.05.2024.
#include "BrutForce.hpp"


BrutForce::BrutForce(vector<ptrPoint>& points)
{
    for (auto& point : points)
    {
        __vectorPoints.push_back(point);
    }
}


void BrutForce::iteration()
{
    if (__isFinded || __vectorPoints.size() > MAX_LEN_ROUTE)
        return;
    
    for (size_t i = 0; i < __vectorPoints.size(); i++)
    {
        vector<ptrPoint> tempPoints = {__vectorPoints[i]};
        __recursion(tempPoints, 0.0);
        
    }
    __isFinded = true;
}


void BrutForce::__recursion(vector<ptrPoint>& points, double length)
{
    cout << length << endl;
    if (points.size() > __vectorPoints.size())
        throw "points.size() > __vectorPoints.size()";
        
    if (length > __lengthRoute)
        return;
    
    if (points.size() == __vectorPoints.size())
    {
        length += points[0]->euclideanDistance(*(points[points.size() - 1]));
        points.push_back(points[0]);
        if (length < __lengthRoute)
        {
            __lengthRoute = length;
            __bestRoute = points;
        }
        return;
    }
    
    for (auto& pointMain : __vectorPoints)
    {
        if (elemInVector(pointMain, points))
            continue;
        
        vector<ptrPoint> pointsTemp = points;
        double tempLength = pointsTemp[pointsTemp.size() - 1]->euclideanDistance(*pointMain) + length;
        
        pointsTemp.push_back(pointMain);
        
        __recursion(pointsTemp, tempLength);
    }
}
