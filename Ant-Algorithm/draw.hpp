//  Created by Семён Шестаков on 17.11.2023.

#ifndef draw_hpp
#define draw_hpp

#include "ClassAnt.hpp"
#define MAX_LINE 5

extern bool fisrt_point;

const sf::Color colorLine = sf::Color(230, 175, 44);
const sf::Color colorLineBest = sf::Color(58, 202, 138);
const sf::Color colorPoint = sf::Color(79,127,198);
const sf::Color colorFirstPoint = sf::Color(235, 53, 89);

size_t maxP();
void drawLines(sf::RenderWindow&);
void drawVecPoints(sf::RenderWindow&);


class DrawAnt : public Ant {
private:
    friend sf::ConvexShape& Line(sf::ConvexShape&, const sf::Vector2f, const sf::Vector2f);
public:
    DrawAnt();
    DrawAnt(shared_ptr<Point>&, vector<shared_ptr<Point>>&);
    shared_ptr<Point> popVertex() override;
    void nextVertex(shared_ptr<Point>&) override;
    void draw(sf::RenderWindow&);
    void drawLine(sf::RenderWindow&, shared_ptr<Point>&);
};
extern unique_ptr<DrawAnt> drawAntEx;

#endif /* draw_hpp */
