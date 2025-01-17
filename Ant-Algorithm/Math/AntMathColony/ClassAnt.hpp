//  Created by Семён Шестаков on 12.11.2023.
#ifndef ClassAnt_hpp
#define ClassAnt_hpp

#include <random>
#include "DrawPoint.hpp"
#include "ColonyUtils.hpp"
#include "ClassUtils.hpp"


namespace math::alg::colony 
{

using draw::setPoint, std::unique_ptr, std::make_unique;


class Ant
{
public:
    Ant() = delete;
    ~Ant() = default;
    Ant( draw::ptrPoint&, draw::vectorPoint& );
    
    DELETE_COPY_AND_MOVE(Ant)
    
private: // Math && Base Logic
    double calculateProbability( const std::size_t );
    void nextVertex( const std::size_t );
    std::size_t popVertex();

public: 
    // Math && Base Logic
    void next();
    
    // Geters
    double getDistance();
    std::vector< std::size_t >& getHistory();
    
private:
    std::size_t m_start {}, m_fromPoint { }, m_toPoint { };
    double m_distance {10e100}, m_pheromones {};
    
    std::vector< std::size_t > m_history = {};
    unique_ptr< setPoint > m_visit = make_unique< setPoint >();
    unique_ptr< setPoint > m_noVisit = make_unique< setPoint >();
};

} // end math::alg::colony space
#endif /* ClassAnt_hpp */
