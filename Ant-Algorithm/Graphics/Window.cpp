//  Created by Семён Шестаков on 01.06.2024.
#include "Window.hpp"


Window::Window( uint _x, uint _y, string _name ) : window( sf::VideoMode(_x, _y), _name )
{
    algSystem = make_unique< AlgorithmSystem >();
}


void Window::eventHandler()
{
    // Mouse
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    math::cord X = mousePosition.x, Y = mousePosition.y;
        
    // Events
    sf::Event event;
    while ( window.pollEvent( event ) )
    {
        
        // Close window
        if ( event.type == sf::Event::Closed )
            window.close();
        
        if ( event.type == sf::Event::KeyPressed )
        {
            if ( event.key.code == sf::Keyboard::Enter )
            {
                enter_click = !enter_click;
                if ( enter_click )
                    _start();
                else
                    _clear();
            }
        }
        
        // Press button mouse left
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left && lock_click != true)
            {
                std::cout << X << " " << Y << std::endl;
                obj::ptrPoint temp (new obj::Point( X, Y ));
                
                obj::vecPoints.push_back( temp );
//                cout << "N: " << obj::vecPoints.size()
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
    window.clear( draw::windowBackground );
    drawLines( window );
    
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


void Window::_clear()
{
    // Global
    obj::vecPoints.clear();
    iter = 0;
    
    // Instance
    algSystem = nullptr;
}


void Window::_start()
{    
    algSystem = make_unique< AlgorithmSystem >();
    algSystem->add( new AntColony( obj::vecPoints ) );
    //algSystem->add( new BrutForce( obj::vecPoints ) );
}
