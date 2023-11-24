//  Created by Семён Шестаков on 12.11.2023.

#ifndef ClassAnt_hpp
#define ClassAnt_hpp

#include <unordered_set>
#include <unordered_map>
#include <vector>
#include "point.hpp"
#include <random>
#include <memory>

#define ANT_COUNT 100
#define DIST_CONST 250.0
#define Q 10.0
#define MEMORY 0.92
#define alpha 0.5
#define beta 5.0


class AntConstructor : public exception{};
class SizeError : public exception {};
class NullPointer : public exception {};

struct PointToPoint{
    double distanceToPoint = 0;
    double P = 0.2;
};

extern unordered_map<shared_ptr<Point>,
        unordered_map<
            shared_ptr<Point>, PointToPoint, Point::SharedPtrHash, Point::SharedPtrEqual>,
        Point::SharedPtrHash, Point::SharedPtrEqual> fullDist;


class BaseAnt{

protected:
    shared_ptr<Point> start = NULL;
    unique_ptr<unordered_set<shared_ptr<Point>, Point::SharedPtrHash, Point::SharedPtrEqual>> visit = make_unique<unordered_set<shared_ptr<Point>, Point::SharedPtrHash, Point::SharedPtrEqual>>();
    unique_ptr<unordered_set<shared_ptr<Point>, Point::SharedPtrHash, Point::SharedPtrEqual>> novisit = make_unique<unordered_set<shared_ptr<Point>, Point::SharedPtrHash, Point::SharedPtrEqual>>();
public:
    BaseAnt();
    BaseAnt(shared_ptr<Point>&, vector<shared_ptr<Point>>&);

};

class Ant : public virtual BaseAnt{
    
private:
    double distance = 0;
    double event = 0;
    double pheromones = 0;
    void next();
    double funcP(const shared_ptr<Point>&);
    vector<shared_ptr<Point>> history;
    friend void iteration();
    
protected:
    shared_ptr<Point> fromPoint = NULL;
    shared_ptr<Point> toPoint = NULL;
    virtual void nextVertex(shared_ptr<Point>&);
    virtual shared_ptr<Point> popVertex();

public:
    Ant();
    Ant(shared_ptr<Point>&, vector<shared_ptr<Point>>&);
};

static vector<shared_ptr<Ant>> vecAnt;
void calcDist(const vector<shared_ptr<Point>>&);
void initAntVec(vector<shared_ptr<Point>>);
void sum(vector<shared_ptr<Point>>);
void iteration();

#endif /* ClassAnt_hpp */
