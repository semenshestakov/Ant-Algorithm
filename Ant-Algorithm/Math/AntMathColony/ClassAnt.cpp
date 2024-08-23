//  Created by Семён Шестаков on 12.11.2023.
#include "ClassAnt.hpp"

math::mapPointPtr fullDist = std::make_shared< math::mapPoint >();

// Ant() - error
Ant::Ant() : BaseAnt(){}

// Constructor Ant(hared_ptr<Point>&, std::vector< obj::ptrPoint >&)
Ant::Ant( obj::ptrPoint& start, std::vector< obj::ptrPoint >& vec) : BaseAnt( start, vec )
{
    fromPoint = start;
    toPoint = start;
}

// flip toPoint and fromPoint with new point (next)
void Ant::nextVertex( obj::ptrPoint& p )
{
    fromPoint = toPoint;
    toPoint = p;
    event = (*fullDist)[fromPoint][toPoint].distanceToPoint;
    distance += event;
    pheromones += (*fullDist)[fromPoint][toPoint].P;
    history.push_back(p);
}

// raise next Point and del elem in _novisit and add elem _visit
obj::ptrPoint Ant::popVertex(){
    std::size_t count { novisit->size() }, i { 0 };
    std::vector< double > probability( count, 0 );
    double _rand = static_cast< double >( rand() ) / RAND_MAX;
    double s = 0, _sum = 0;
    
    for ( auto& elm : *(novisit) )
    {
        obj::ptrPoint temp = std::static_pointer_cast<obj::Point>( elm );
        probability[ i++ ] = funcP( temp );
        _sum += probability[ i - 1 ];
    }

    i = 0;
    for ( auto& elm : *novisit )
    {
        s += ( probability[ i ] / _sum );
        
        if ( _rand <= s )
        {
            auto it = novisit->find(elm);
            
            if ( it != novisit->end() )
            {
                obj::ptrPoint res = std::static_pointer_cast< obj::Point >( elm );
                visit->insert( res );
                novisit->erase( it );
                return res;
            };
        }
        i++;
    }
    
    auto it = novisit->begin();
    math::HashablePointPtr res = *it;
    visit->insert(res);
    novisit->erase(it);
    return std::static_pointer_cast< obj::Point >( res );
}

// iter
void Ant::next()
{
    event = 0;
    distance = 0;
    pheromones = 0;
    history.clear();
    history.push_back( start );
    
    while ( !novisit->empty() )
    {
        obj::ptrPoint temp = popVertex();
        nextVertex( temp );
    }
    
    nextVertex( start );
    novisit.swap( visit );
}

double Ant::getDist(){return distance;}
std::vector< obj::ptrPoint >& Ant::getHistory(){return history;}
