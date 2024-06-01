//  Created by Семён Шестаков on 17.11.2023.
#ifndef draw_hpp
#define draw_hpp

#include "ClassAnt.hpp"
#define MAX_LINE 5.0

const sf::Color colorLine = sf::Color(230, 175, 44);
const sf::Color colorLineBest = sf::Color(58, 202, 138);
const sf::Color colorPoint = sf::Color(79,127,198);
const sf::Color colorFirstPoint = sf::Color(235, 53, 89);

class DrawAnt : public Ant {
private:
    friend sf::ConvexShape& Line(sf::ConvexShape&, const sf::Vector2f, const sf::Vector2f);
public:
    DrawAnt();
    DrawAnt(ptrPoint&, vector<ptrPoint>&);
    ptrPoint popVertex() override;
    void nextVertex(ptrPoint&) override;
    void draw(sf::RenderWindow&);
    void drawLine(sf::RenderWindow&, ptrPoint&);
    void printDistance();
};

// func
double maxP();
void drawLines(sf::RenderWindow&);
void drawVecPoints(sf::RenderWindow&);
void drawMinWay(sf::RenderWindow&);

// global var
extern unique_ptr<DrawAnt> drawAntEx;
extern bool fisrt_point;
#endif /* draw_hpp */
