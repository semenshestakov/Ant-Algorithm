//  Created by Семён Шестаков on 01.06.2024.
#ifndef Window_hpp
#define Window_hpp


#include "Drawer/draw.hpp"
#include "AntColony.hpp"
#include "BrutForce.hpp"
#include "AlgorithmSystem.hpp"
#include "ClassUtils.hpp"


typedef unsigned int uint;

static bool lock_click = false;
static bool gAlgorithmsIsWork = false;
static std::size_t iter = 0;


class Window
{
private:
    sf::RenderWindow window;
    systems::AlgorithmSystemPtr algSystem = nullptr;
    void eventHandler();
    void _clear();
    void _start();
    
public:
    Window() = delete;
    Window( uint , uint , std::string );
    
    DELETE_COPY_AND_MOVE(Window)
    
    bool isOpen();
    void update();
};


#endif /* Window_hpp */
