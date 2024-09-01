//
//  ColonyUtils.hpp
//  Ant-Algorithm
//
//  Created by Семён Шестаков on 15.09.2024.
//

#ifndef ColonyUtils_hpp
#define ColonyUtils_hpp

namespace math::alg::colony
{


/*
 @param dict - responsible for the distance metric, according to the formula F_1(dist) = dictConst / dist
 @param Q - responsible for evaluating the contribution of the distance traveled F_2(dist) = Q / F_1(dist)
 @param cP - coefficient of forgetting previous routes
 @param maxP - maximum contribution of an ant in one round
 @param alpha - final contribution of pheromones,
 according to the formula F_3(p_1, p_2, alpha) = p_12.pheromone ^ alpha
 @param beta - final contribution of dist,
 according to the formula F_3(p_1, p_2, alpha) = p_12.dist ^ alpha
 */
struct ColonyConstants
{
    double dist { 200.0 }, Q { 10.0 }, cP { 0.7 }, maxP{ 0.5 };
    double alpha { 0.5 }, beta { 1.0 };
};

constexpr ColonyConstants gColonyConst = {};


} // end namespace math::alg::colony

#endif /* ColonyUtils_hpp */
