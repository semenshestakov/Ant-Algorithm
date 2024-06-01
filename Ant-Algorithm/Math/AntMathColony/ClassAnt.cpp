//  Created by Семён Шестаков on 12.11.2023.
#include "ClassAnt.hpp"

mapPointPtr fullDist = make_shared<mapPoint>();

// Ant() - error
Ant::Ant() : BaseAnt(){}

// Constructor Ant(hared_ptr<Point>&, vector<ptrPoint>&)
Ant::Ant(ptrPoint& start, vector<ptrPoint>& vec) : BaseAnt(start, vec){
    fromPoint = start;
    toPoint = start;
}

// flip toPoint and fromPoint with new point (next)
void Ant::nextVertex(ptrPoint& p){
    fromPoint = toPoint;
    toPoint = p;
    event = (*fullDist)[fromPoint][toPoint].distanceToPoint;
    distance += event;
    pheromones += (*fullDist)[fromPoint][toPoint].P;
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
    history.push_back(start);
    
    while (!novisit->empty()) {
        ptrPoint temp = popVertex();
        nextVertex(temp);
    }
    
    nextVertex(start);
    novisit.swap(visit);
}

double Ant::getDist(){return distance;}
vector<ptrPoint>& Ant::getHistory(){return history;}
