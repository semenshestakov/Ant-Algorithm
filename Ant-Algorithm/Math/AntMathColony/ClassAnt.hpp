//  Created by Семён Шестаков on 12.11.2023.
#ifndef ClassAnt_hpp
#define ClassAnt_hpp

#include <random>
#include "PointObject.hpp"
#include "ColonyUtils.hpp"


namespace math::alg::colony 
{

using math::setPoint, std::unique_ptr, std::make_unique;


class Ant
{
public:
    Ant() = delete;
    ~Ant() = default;
    Ant( obj::ptrPoint&, std::vector< obj::ptrPoint >& );
    
private: // Math && Base Logic
    double calculateProbability( const obj::ptrPoint& );
    void nextVertex( obj::ptrPoint& );
    obj::ptrPoint popVertex();

public: 
    // Math && Base Logic
    void next();
    
    // Geters
    double getDistance();
    std::vector< obj::ptrPoint >& getHistory();
    
private:
    obj::ptrPoint m_start { nullptr }, m_fromPoint { nullptr }, m_toPoint { nullptr };
    double m_distance {}, m_pheromones {};
    
    std::vector< obj::ptrPoint > m_history;
    unique_ptr< setPoint > m_visit = make_unique< setPoint >();
    unique_ptr< setPoint > m_noVisit = make_unique< setPoint >();
};

} // end math::alg::colony space
#endif /* ClassAnt_hpp */
