//  Created by Семён Шестаков on 19.05.2024.
#ifndef BrutForce_hpp
#define BrutForce_hpp

#include "Utils.hpp"
#include "BaseAlgorithm.hpp"

#define MAX_LEN_ROUTE 10


class BrutForce : public BaseAlgorithm
{
private:
    double __lengthRoute = 10e100;
    vector<ptrPoint> __vectorPoints;
    vector<ptrPoint> __bestRoute;
    void __recursion(vector<ptrPoint>&, double);
    bool __isFinded = false;
    
public:
    BrutForce() = delete;
    BrutForce(vector<ptrPoint>&);
    void iteration() override ;
    void draw(sf::RenderWindow&) override;
};


#endif /* BrutForce_hpp */
