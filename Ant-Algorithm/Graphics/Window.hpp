//  Created by Семён Шестаков on 01.06.2024.
#ifndef Window_hpp
#define Window_hpp

#include <SFML/Graphics.hpp>
#include <string>
#include "../Math/point.hpp"
#include "draw.hpp"
#include "AntColony.hpp"


using std::string;


static bool lock_click = false;
static bool enter_click = false;
static size_t iter = 0;
extern AntColony colony;

class Window
{
private:
    sf::RenderWindow window;
    void eventHandler();
    
public:
    Window() = delete;
    Window(unsigned int _x, unsigned int _y, string _name) : window(sf::VideoMode(_x, _y), _name) {}
    
    bool isOpen();
    void next();
};

void clearAlg();
void startAlg();

#endif /* Window_hpp */
