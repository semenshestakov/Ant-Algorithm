#include "draw.hpp"

bool fisrt_point = true;
unique_ptr<DrawAnt> drawAntEx;

DrawAnt::DrawAnt() : BaseAnt(){}
DrawAnt::DrawAnt(shared_ptr<Point>& start, vector<shared_ptr<Point>>& vec) : BaseAnt(start, vec){
    fromPoint = start;
    toPoint = start;
}

size_t maxP(){
    size_t _max = 0, n = 1;
    
    for (auto& elm1 : vecPoints){
        for (auto& elm2 : vecPoints){
            if (_max < fullDist[elm1][elm2].P){
                _max += fullDist[elm1][elm2].P;
            }
            n++;
        }
    }
    return _max;
}

// draw
void DrawAnt::draw(sf::RenderWindow& window){
    
    while (!novisit->empty()) {
        shared_ptr<Point> temp = popVertex();
        drawLine(window, temp);
    }
    
    drawLine(window, start);
    novisit.swap(visit);
}

// help function
sf::ConvexShape& Line(sf::ConvexShape& convex, const sf::Vector2f v1, const sf::Vector2f v2){
    convex.setPointCount(3);
    convex.setPoint(0, v1);
    convex.setPoint(1, v2);
    convex.setPoint(2, v1);
     
    return convex;
}

// draw full lines
void drawLines(sf::RenderWindow& window){
    size_t _max = maxP();
    
    
    for (auto& elm1 : vecPoints){
        for (auto& elm2 : vecPoints){
            sf::ConvexShape convex;
            Line(convex, elm1->getVetrexDraw(), elm2->getVetrexDraw());
            
            float outlineThickness = (fullDist[elm1][elm2].P / _max + 0.2) * 10;
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

void DrawAnt::drawLine(sf::RenderWindow& window, shared_ptr<Point>& ptr){
    nextVertex(ptr);
    sf::ConvexShape convex;
    ::Line(convex, toPoint->getVetrexDraw(), fromPoint->getVetrexDraw());
    convex.setOutlineThickness(MAX_LINE);
    convex.setOutlineColor(colorLineBest);
    window.draw(convex);
}

void DrawAnt::nextVertex(shared_ptr<Point>& p){
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

shared_ptr<Point> DrawAnt::popVertex() {
    size_t P = 0;
    shared_ptr<Point> temp;
    
    for (auto& elm : *(novisit)){
        if (P < fullDist[toPoint][elm].P){
            P = fullDist[toPoint][elm].P;
            temp = elm;
        }
    }

    auto it = novisit->find(temp);
    visit->insert(temp);
    novisit->erase(it);
    return temp;
}

