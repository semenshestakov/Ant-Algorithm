//  Created by Семён Шестаков on 12.11.2023.
#include "ClassAnt.hpp"

mapPoint fullDist;
double minDist = 10e100;

// Ant() - error
Ant::Ant() : BaseAnt(){}

// Constructor Ant(hared_ptr<Point>&, vector<ptrPoint>&)
Ant::Ant(ptrPoint& start, vector<ptrPoint>& vec) : BaseAnt(start, vec){
    fromPoint = start;
    toPoint = start;
}

double Ant::funcP(const ptrPoint& elm){
    double temp = pow(static_cast<double>(fullDist[toPoint][elm].P), alpha) * pow(DIST_CONST / fullDist[toPoint][elm].distanceToPoint, beta);
    return temp;
}

// flip toPoint and fromPoint with new point (next)
void Ant::nextVertex(ptrPoint& p){
    fromPoint = toPoint;
    toPoint = p;
    event = fullDist[fromPoint][toPoint].distanceToPoint;
    distance += event;
    pheromones += fullDist[fromPoint][toPoint].P;
    history.push_back(p);
}

// raise next Point and del elem in _novisit and add elem _visit
ptrPoint Ant::popVertex(){
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
                ptrPoint res = *it;
                visit->insert(res);
                novisit->erase(it);
                return res;
            };
        }
        i++;
    }
    
    auto it = novisit->begin();
    ptrPoint res = *it;
    visit->insert(res);
    novisit->erase(it);
    return res;
}

// iter
void Ant::next(){
    event = 0;
    distance = 0;
    pheromones = 0;
    history.clear();
    
    while (!novisit->empty()) {
        ptrPoint temp = popVertex();
        nextVertex(temp);
    }
    
    nextVertex(start);
    novisit.swap(visit);
}

// calc euclideanDistance many points to many points
void calcDist(const vector<ptrPoint>& vec){
    for (size_t i = 0; i < (vec.size()); i++){
        for (size_t j = 0; j < (vec.size()); j++){
            double t = 0.2;
            if (i == j)
                t = 0;

            struct PointToPoint temp {
                .distanceToPoint = euclideanDistance(*vec[i], *vec[j]),
                .P = t
            };
            fullDist[vec[i]][vec[j]] = std::move(temp);
        }
    }
}

// init vector Ant
void initAntVec(vector<ptrPoint> vec){
    calcDist(vec);
    if (vec.size() < 2) throw SizeError();
    
    for (auto& elm : vec){
        shared_ptr<Ant> temp = make_shared<Ant>(elm, vec);
        vecAnt.push_back(temp);
    }
}

// iteration on vector Ant
void iteration(){
    for (auto& elm : vecAnt){elm->next();}
    
    for (auto& elm1 : vecPoints){
        for (auto& elm2 : vecPoints){
            if (elm1 != elm2){
                fullDist[elm1][elm2].P *= cP;
            }
        }
    }
    
    for (auto& elm : vecAnt){
        if (elm->distance <= minDist && elm->distance != 0){
            minDist = elm->distance;
            for (size_t i = 1;i < elm->history.size();i++){
                auto& first = elm->history[i-1];
                auto& last = elm->history[i];
                
                double res = Q / (DIST_CONST / elm->distance);
                fullDist[first][last].P += res;
                fullDist[last][first].P += res;
            }
        }
    }
}
