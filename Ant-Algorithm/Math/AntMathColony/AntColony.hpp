//  Created by Семён Шестаков on 30.12.2023.


#ifndef AntColony_hpp
#define AntColony_hpp

#include "ClassAnt.hpp"
#include "BaseAlgorithm.hpp"
#include "ClassUtils.hpp"


namespace math::alg::colony
{

/*
 A class that is a colony of ants, where each sea starts from a different position
 */
class AntColony : public BaseAlgorithm
{
public:
    AntColony() = delete;
    AntColony( std::vector< obj::ptrPoint >& );
    ~AntColony() = default;
    
    DELETE_COPY_AND_MOVE(AntColony)
    
protected:
    inline static AlgorithmTypes type = AlgorithmTypes::ANT_COLONY;
    std::vector< std::shared_ptr< Ant > > vecAnt;
    std::size_t m_iter = 0;
    
public:
    int getType() const override  { return AntColony::type; }
    void initAntVec( std::vector< obj::ptrPoint >& );
    void iteration() override;

private:
    inline static std::size_t s_stopIter = 100000;
};

} // end math::alg::colony space
#endif /* AntColony_hpp */
