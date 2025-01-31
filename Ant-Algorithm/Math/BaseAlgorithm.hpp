//  Created by Семён Шестаков on 01.06.2024.
#ifndef BaseAlgorithm_hpp
#define BaseAlgorithm_hpp

#include <SFML/Graphics.hpp>
#include "DrawPoint.hpp"
#include "ClassUtils.hpp"


namespace math::alg
{

enum AlgorithmTypes
{
    BASE,
    ANT_COLONY,
    BRUT_FORCE,
    
    MAX_VALUE // Last
};


class BaseAlgorithm
{
public:
    virtual void iteration() = 0;
    virtual void draw( sf::RenderWindow& window ) const;
    virtual int getType() const { return BaseAlgorithm::type; }
    
protected:
    inline static AlgorithmTypes type = AlgorithmTypes::BASE;
    std::vector< std::size_t > m_bestRoute = {};
    double m_lengthRoute = 10e100;
    
public:
    BaseAlgorithm() = default;
    virtual ~BaseAlgorithm() { m_bestRoute.clear(); }
    
    DELETE_COPY_AND_MOVE(BaseAlgorithm)
};

} // end space math::alg
#endif /* BaseAlgorithm_hpp */
