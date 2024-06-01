//  Created by Семён Шестаков on 17.11.2023.
#ifndef draw_hpp
#define draw_hpp

#include "AntColony.hpp"
#include "BrutForce.hpp"
#define MAX_LINE 5.0

const sf::Color colorLine = sf::Color(230, 175, 44);
const sf::Color colorBrutForceLine = sf::Color(0, 200, 0);
const sf::Color colorLineBest = sf::Color(58, 202, 138);
const sf::Color colorPoint = sf::Color(79,127,198);
const sf::Color colorFirstPoint = sf::Color(235, 53, 89);
const sf::Color windowBackground = sf::Color(221,221,221);

// func
double maxP();
void drawLines(sf::RenderWindow&);
void drawVecPoints(sf::RenderWindow&);

// global var
extern bool fisrt_point;
#endif /* draw_hpp */
