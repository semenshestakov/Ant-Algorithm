#include <ctime>
#include <unistd.h>
#include "Graphics/Window.hpp"

///opt/homebrew/Cellar/sfml/2.6.0
///clang++ -std=c++20 point.cpp WriteFile.cpp BaseAnt.cpp ClassAnt.cpp AntColony.cpp  draw.cpp main.cpp -I/opt/homebrew/Cellar/sfml/2.6.0/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.0/lib/ -lsfml-graphics -lsfml-window -lsfml-system



void test(){
    /*
    obj::vecPoints.push_back(make_shared<Point>(179, 216));
    obj::vecPoints.push_back(make_shared<Point>(381, 72));
    obj::vecPoints.push_back(make_shared<Point>(377, 303));
    obj::vecPoints.push_back(make_shared<Point>(630, 173));
    obj::vecPoints.push_back(make_shared<Point>(503, 346));
    obj::vecPoints.push_back(make_shared<Point>(700, 227));
    obj::vecPoints.push_back(make_shared<Point>(585, 59));
    obj::vecPoints.push_back(make_shared<Point>(413, 213));
    obj::vecPoints.push_back(make_shared<Point>(184, 416));
    obj::vecPoints.push_back(make_shared<Point>(696, 404));
    obj::vecPoints.push_back(make_shared<Point>(739, 250));
    obj::vecPoints.push_back(make_shared<Point>(781, 71));
    obj::vecPoints.push_back(make_shared<Point>(168, 84));
    obj::vecPoints.push_back(make_shared<Point>(98, 269));
    obj::vecPoints.push_back(make_shared<Point>(99, 476));
    obj::vecPoints.push_back(make_shared<Point>(430, 487));
    obj::vecPoints.push_back(make_shared<Point>(690, 550));
     */
}
Window window = {900, 600, "AntAlg"};

int main() {
    srand( time_t( nullptr ) );
    while ( window.isOpen() )
    {
        window.update();
    }
    
}

