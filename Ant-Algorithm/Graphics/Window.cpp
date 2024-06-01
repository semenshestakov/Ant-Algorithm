//  Created by Семён Шестаков on 01.06.2024.
#include "Window.hpp"



AntColony colony;

void startAlg(){
    cout << "\n===Start===\n" << endl;
    drawAntEx = make_unique<DrawAnt>(vecPoints[0], vecPoints);
    colony = AntColony(vecPoints);
}

void clearAlg(){
    cout << "\n====End====\n" << endl;
    for (auto& elm1 : vecPoints){
        cout << *elm1 << endl;
        for (auto& elm2 : vecPoints){
            cout << "\tto" << *elm2
            << ": P = " << (*fullDist)[elm1][elm2].P << endl;
        }
    }
    vecPoints.clear();
    colony = AntColony();
    fisrt_point = true;
    iter = 0;
}


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
                if (enter_click){
                    startAlg();
                } else {
                    clearAlg();
                }
            }
        }
        
        // Press button mouse left
        if (event.type == sf::Event::MouseButtonPressed){
            if (event.mouseButton.button == sf::Mouse::Left && lock_click != true){
                ptrPoint temp = make_shared<Point>(X, Y);
                
                if (fisrt_point)
                    fisrt_point = false;
                
                vecPoints.push_back(temp);
                cout << "N: " << vecPoints.size()
                << "  X = " << X
                << " Y = " << Y << endl;
                cout << sizeof(temp) << " " << sizeof(*temp) << endl;
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


void Window::next()
{

    eventHandler();

    
    window.clear(sf::Color(221,221,221));
    drawLines(window);
    if (enter_click){
        colony.iteration();
        cout << iter++ << endl;
//                    usleep(100000); // 0.1
//                    usleep(1000000); // 1
        
//            drawAntEx->draw(window);
    }
    drawMinWay(window);
    drawVecPoints(window);
    window.display();
}
