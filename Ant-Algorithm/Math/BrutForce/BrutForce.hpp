//  Created by Семён Шестаков on 19.05.2024.
#ifndef BrutForce_hpp
#define BrutForce_hpp

#include "Utils.hpp"
#include "BaseAlgorithm.hpp"


class BrutForce : public BaseAlgorithm
{
public:
    BrutForce() = delete;
    BrutForce( std::vector< obj::ptrPoint >& );
    void iteration() override ;
    void draw( sf::RenderWindow& ) const override;
    
private:
    const std::size_t m_maxLenRoute = 10;
    double m_lengthRoute = 10e100;
    std::vector< obj::ptrPoint > m_vectorPoints;
    std::vector< obj::ptrPoint > m_bestRoute;
    void _recursion( std::vector< obj::ptrPoint >&, double );
    bool m_isFinded = false;

};


#endif /* BrutForce_hpp */
