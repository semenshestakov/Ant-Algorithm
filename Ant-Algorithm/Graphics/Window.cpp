//  Created by Семён Шестаков on 01.06.2024.
#include "Window.hpp"


void Window::eventHandler()
{
    // Mouse
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    cord X = mousePosition.x, Y = mousePosition.y;
        
    // Events
    sf::Event event;
    while (window.pollEvent(event)) {
        
        // Close window
        if (event.type == sf::Event::Closed)
            window.close();
        
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                enter_click = !enter_click;
                if (enter_click)
                    __start();
                else
                    __clear();
            }
        }
        
        // Press button mouse left
        if (event.type == sf::Event::MouseButtonPressed){
            if (event.mouseButton.button == sf::Mouse::Left && lock_click != true){
                ptrPoint temp = make_shared<Point>(X, Y);
                
                if (fisrt_point)
                    fisrt_point = false;
                
                vecPoints.push_back(temp);
//                cout << "N: " << vecPoints.size()
//                << "  X = " << X
//                << " Y = " << Y << endl;
//                cout << sizeof(temp) << " " << sizeof(*temp) << endl;
            }
        }
        
        // un-Press button mouse left
        if (event.type == sf::Event::MouseButtonReleased){
            if (event.mouseButton.button == sf::Mouse::Left){
                lock_click = false;
            }
        }
    }
}


bool Window::isOpen() { return window.isOpen(); }


void Window::update()
{
    eventHandler();
    window.clear(windowBackground);
    drawLines(window);
    
    if (enter_click)
    {
        algSystem->iteration();
//        cout << iter++ << endl;
//                    usleep(100000); // 0.1
//                    usleep(1000000); // 1
        
        algSystem->draw(window);
    }
    
    drawVecPoints(window);
    window.display();
}


void Window::__clear()
{
    // Global
    vecPoints.clear();
    fisrt_point = true;
    iter = 0;
    
    // Instance
    algSystem = nullptr;
}


void Window::__start()
{    
    algSystem = make_unique<AlgorithmSystem>();
    algSystem->add(new AntColony(vecPoints));
    algSystem->add(new BrutForce(vecPoints));
}
