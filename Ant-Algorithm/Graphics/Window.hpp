//  Created by Семён Шестаков on 01.06.2024.
#ifndef Window_hpp
#define Window_hpp


#include "Drawer/draw.hpp"
#include "AntColony.hpp"
#include "BrutForce.hpp"
#include "AlgorithmSystem.hpp"


typedef unique_ptr<AlgorithmSystem> AlgorithmSystemPtr;
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
    void __clear();
    void __start();
    
public:
    Window() = delete;
    Window(unsigned int _x, unsigned int _y, string _name) : window(sf::VideoMode(_x, _y), _name) { algSystem = make_unique<AlgorithmSystem>(); }
    
    bool isOpen();
    void update();
};


#endif /* Window_hpp */
