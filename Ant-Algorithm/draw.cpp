#include "draw.hpp"

bool fisrt_point = true;
unique_ptr<DrawAnt> drawAntEx;

DrawAnt::DrawAnt() : BaseAnt(){}
DrawAnt::DrawAnt(ptrPoint& start, vector<ptrPoint>& vec) : BaseAnt(start, vec){
    fromPoint = start;
    toPoint = start;
}

double maxP(){
    double _max = 0, n = 1;
    
    for (auto& elm1 : vecPoints){
        for (auto& elm2 : vecPoints){
            if (_max < (*fullDist)[elm1][elm2].P){
                _max += (*fullDist)[elm1][elm2].P;
            }
            n++;
        }
    }
    return _max;
}

// draw
void DrawAnt::draw(sf::RenderWindow& window){
    
    while (!novisit->empty()) {
        ptrPoint temp = popVertex();
        drawLine(window, temp);
    }
    
    drawLine(window, start);
    novisit.swap(visit);
}

// help function
sf::ConvexShape& Line(sf::ConvexShape& convex, const sf::Vector2f v1, const sf::Vector2f v2){
    convex.setPointCount(4);
    convex.setPoint(0, v1);
    convex.setPoint(1, v1);
    convex.setPoint(2, v2);
    convex.setPoint(3, v2);
     
    return convex;
}

// draw full lines
void drawLines(sf::RenderWindow& window){
    double _max = maxP() + 0.01;
    
    for (auto& elm1 : vecPoints){
        for (auto& elm2 : vecPoints){
            sf::ConvexShape convex;
            Line(convex, elm1->getVetrexDraw(), elm2->getVetrexDraw());
            
            float outlineThickness = ((*fullDist)[elm1][elm2].P / _max + 2.0) * 0.7;
            convex.setOutlineThickness(outlineThickness);
            convex.setOutlineColor(colorLine);
            window.draw(convex);
        }
    }
}

// draw point on window
void drawVecPoints(sf::RenderWindow& win){
    for (auto& elm : vecPoints){win.draw(elm->getCircle());}
}

void DrawAnt::drawLine(sf::RenderWindow& window, ptrPoint& ptr){
    nextVertex(ptr);
    sf::ConvexShape convex;
    ::Line(convex, toPoint->getVetrexDraw(), fromPoint->getVetrexDraw());
    convex.setOutlineThickness(MAX_LINE);
    convex.setOutlineColor(colorLineBest);
    window.draw(convex);
}

void DrawAnt::nextVertex(ptrPoint& p){
    fromPoint = toPoint;
    toPoint = p;
}

// drawPoint
sf::CircleShape Point::drawPoint(){
    sf::CircleShape circle;
    circle.setRadius(RADIUS);
    
    circle.setFillColor(colorPoint);
    if (fisrt_point)
        circle.setFillColor(colorFirstPoint);
    
    circle.setPosition(_x, _y);
    return circle;
}

//

ptrPoint DrawAnt::popVertex() {
    size_t P = 0;
    ptrPoint temp;
    
    for (auto& elm : *(novisit)){
        if (P < (*fullDist)[toPoint][elm].P){
            P = (*fullDist)[toPoint][elm].P;
            temp = elm;
        }
    }

    auto it = novisit->find(temp);
    visit->insert(temp);
    novisit->erase(it);
    return temp;
}

void drawMinWay(sf::RenderWindow& window){
//
    for (size_t i = 1; i < minVecPoints.size(); i++){
        auto& elm1 = minVecPoints[i-1];
        auto& elm2 = minVecPoints[i];
        
        sf::ConvexShape convex;
        Line(convex, elm1->getVetrexDraw(), elm2->getVetrexDraw());
            
        float outlineThickness = MAX_LINE;
        convex.setOutlineThickness(outlineThickness);
        convex.setOutlineColor(colorFirstPoint);
        window.draw(convex);
    }
}

