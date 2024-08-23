//  Created by Семён Шестаков on 01.06.2024.
#ifndef Window_hpp
#define Window_hpp


#include "Drawer/draw.hpp"
#include "AntColony.hpp"
#include "BrutForce.hpp"
#include "AlgorithmSystem.hpp"


typedef unique_ptr< AlgorithmSystem>  AlgorithmSystemPtr;
typedef unsigned int uint;
using std::string;

static bool lock_click = false;
static bool enter_click = false;
static size_t iter = 0;


class Window
{
private:
    sf::RenderWindow window;
    AlgorithmSystemPtr algSystem = nullptr;
    void eventHandler();
    void _clear();
    void _start();
    
public:
    Window() = delete;
    Window(uint , uint , string);
    
    bool isOpen();
    void update();
};


#endif /* Window_hpp */
