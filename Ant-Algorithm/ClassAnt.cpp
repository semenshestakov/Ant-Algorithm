//  Created by Семён Шестаков on 12.11.2023.


#include "ClassAnt.hpp"


unordered_map<shared_ptr<Point>,
        unordered_map<
            shared_ptr<Point>, PointToPoint, Point::SharedPtrHash, Point::SharedPtrEqual>,
        Point::SharedPtrHash, Point::SharedPtrEqual> fullDist;

// Constructor Ant(), BaseAnt() - error
BaseAnt::BaseAnt(){throw AntConstructor();}
Ant::Ant(){}

// Constructor BaseAnt(shared_ptr<Point>&, vector<shared_ptr<Point>>&)
BaseAnt::BaseAnt(shared_ptr<Point>& start, vector<shared_ptr<Point>>& vec){
    if (vec.size() <= 2){ throw SizeError();}
    this->start = start;
    for (size_t i = 0; i < (vec.size());i++){
        if (*vec[i] != *start){ novisit->insert(vec[i]);}
    }
}

// Constructor Ant(hared_ptr<Point>&, vector<shared_ptr<Point>>&)
Ant::Ant(shared_ptr<Point>& start, vector<shared_ptr<Point>>& vec) : BaseAnt(start, vec){
    fromPoint = start;
    toPoint = start;
}

// flip toPoint and fromPoint with new point (next)
void Ant::nextVertex(shared_ptr<Point>& p){
    fromPoint = toPoint;
    toPoint = p;
    event = fullDist[fromPoint][toPoint].distanceToPoint;
    distance += event;
    pheromones += fullDist[fromPoint][toPoint].P;
    history.push_back(p);
}

double Ant::funcP(const shared_ptr<Point>& elm){
    double temp = pow(static_cast<double>(fullDist[toPoint][elm].P), alpha) * pow(fullDist[toPoint][elm].distanceToPoint, beta);
    return temp;
}

// raise next Point and del elem in _novisit and add elem _visit
shared_ptr<Point> Ant::popVertex(){
    size_t count = novisit->size(), i=0;
    vector<double> probability(count, 0);
    double _rand = static_cast<double>(rand()) / RAND_MAX;
    double s = 0, _sum = 0;
    
    for (auto& elm : *(novisit)){
        probability[i++] = funcP(elm);
        _sum += probability[i-1];
    }

    i = 0;
    for (auto& elm : *(novisit)){
        s += (probability[i] / _sum);
        
        if (_rand <= s){
            auto it = novisit->find(elm);
            
            if (it != novisit->end()){
                shared_ptr<Point> res = *it;
                visit->insert(res);
                novisit->erase(it);
                return res;
            };
        }
        i++;
    }
    
    auto it = novisit->begin();
    shared_ptr<Point> res = *it;
    visit->insert(res);
    novisit->erase(it);
    return res;
//    return popVertex();
}

// iter
void Ant::next(){
    event = 0;
    distance = 0;
    pheromones = 0;
    history.clear();
    
    while (!novisit->empty()) {
        shared_ptr<Point> temp = popVertex();
        nextVertex(temp);
    }
    
//    shared_ptr<Point> temp = popVertex();
    nextVertex(start);
    novisit.swap(visit);
}


// calc euclideanDistance many points to many points
void calcDist(const vector<shared_ptr<Point>>& vec){
    for (size_t i = 0; i < (vec.size()); i++){
        for (size_t j = 0; j < (vec.size()); j++){
            size_t n = 0;
            if (*vec[i] != *vec[j]){n = 1;}
            struct PointToPoint temp {
                .distanceToPoint = DIST_CONST / euclideanDistance(*vec[i], *vec[j]),
            };
            fullDist[vec[i]][vec[j]] = std::move(temp);
        }
    }
}

// init vector Ant
void initAntVec(vector<shared_ptr<Point>> vec){
    calcDist(vec);
    if (vec.size() < 2) throw SizeError();
    
    shared_ptr<Point> start = vec[0];
    
    for (auto& elm : vec){
        shared_ptr<Ant> temp = make_shared<Ant>(elm, vec);
        vecAnt.push_back(temp);

    }
}


// iteration on vector Ant
void iteration(){
    for (auto& elm : vecAnt){elm->next();}
//    double _sum = sum(vecPoints);
    for (auto& elm1 : vecPoints){
        for (auto& elm2 : vecPoints){
            if (elm1 != elm2){
                fullDist[elm1][elm2].P *= MEMORY;
            }
        }
    }
    
    for (auto& elm : vecAnt){
        for (size_t i = 1;i < elm->history.size();i++){
            auto& first = elm->history[i-1];
            auto& last = elm->history[i];
            
            fullDist[first][last].P += Q / elm->distance;
        }
    }
}

