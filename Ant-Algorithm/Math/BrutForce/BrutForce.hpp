//  Created by Семён Шестаков on 19.05.2024.
#ifndef BrutForce_hpp
#define BrutForce_hpp

#include "Utils.hpp"
#include "BaseAlgorithm.hpp"


namespace math::alg {


class BrutForce : public BaseAlgorithm
{
public:
    BrutForce() = delete;
    BrutForce( std::vector< obj::ptrPoint >& );
    ~BrutForce() {}
    
protected:
    inline static AlgorithmTypes type = AlgorithmTypes::BRUT_FORCE;
    int getType() const override { return BrutForce::type; }
    
    const std::size_t m_maxLenRoute = 10;
    bool m_isFinded = false;
    
public:
    void iteration() override;
    
protected:
    std::vector< obj::ptrPoint > m_vectorPoints;
    void _recursion( std::vector< obj::ptrPoint >&, double );
};

} // end space math::alg
#endif /* BrutForce_hpp */
