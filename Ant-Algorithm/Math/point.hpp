//  Created by Семён Шестаков on 11.11.2023.
#ifndef point_hpp
#define point_hpp

#include <SFML/Graphics.hpp>
#include <cmath>
#include <memory>
#include <iostream>
#include <stdio.h>
#include <exception>
#include <unordered_map>
#include <unordered_set>
#include <functional>
    
#define RADIUS 8

using namespace std;
typedef int cord;


class Point
{
private:
    cord _x;
    cord _y;
    size_t _identifier;
    sf::CircleShape _circle;
    sf::CircleShape drawPoint();
    size_t hash_point();
    
public:
    Point() = delete;
    Point(cord, cord);
    ~Point();
    cord getX();
    cord getY();
    
    
    // operators
    bool operator==(const Point&) const;
    size_t operator()(const Point& p) const;
    friend ostream& operator<<(ostream& os, const Point& point);
    
    
    // func
    double euclideanDistance(const Point&);
    sf::CircleShape& getCircle();
    size_t getIdentifier() const;
    sf::Vector2f getVetrexDraw();
    friend double euclideanDistance(const Point&, const Point&);
    void firstPointInit();
    
    
    // for hash
    struct SharedPtrHash
    {
        size_t operator()(const shared_ptr<Point>& ptr) const;
    };
    
    struct SharedPtrEqual
    {
        bool operator()(const shared_ptr<Point>& lhs, const shared_ptr<Point>& rhs) const;
    };
};

struct PointToPoint
{
    double distanceToPoint = 0;
    double P = 0.2;
};

typedef shared_ptr<Point> ptrPoint;
typedef unordered_set<ptrPoint, Point::SharedPtrHash, Point::SharedPtrEqual> setPoint;
typedef unordered_map<ptrPoint, unordered_map<ptrPoint, PointToPoint, Point::SharedPtrHash, Point::SharedPtrEqual>, Point::SharedPtrHash, Point::SharedPtrEqual> mapPoint;
typedef shared_ptr<mapPoint> mapPointPtr;

bool operator!=(const Point&, const Point&);
void drawVecPoints(sf::RenderWindow&);
extern vector<ptrPoint> vecPoints;

#endif /* point_hpp */
