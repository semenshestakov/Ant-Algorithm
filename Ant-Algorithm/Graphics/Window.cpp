//  Created by Семён Шестаков on 01.06.2024.
#include "Window.hpp"
#include "PointsSystem.hpp"


Window::Window( const uint _x, const uint _y, const std::string _name ) : window( sf::VideoMode( _x, _y ), _name )
{
    algSystem = std::make_unique< systems::AlgorithmSystem >();
}


void Window::eventHandler()
{
    // Mouse
    sf::Vector2i mousePosition = sf::Mouse::getPosition( window );
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
                gAlgorithmsIsWork = !gAlgorithmsIsWork;
                if ( gAlgorithmsIsWork )
                {
                    _start();
                }
                else
                {
                    _clear();
                }
            }
        }
        
        // Press button mouse left
        if ( event.type == sf::Event::MouseButtonPressed )
        {
            if ( event.mouseButton.button == sf::Mouse::Left && lock_click != true )
            {
                draw::ptrPoint temp ( new draw::Point( X, Y ) );
                systems::pointSys.add( temp );
            }
        }
        
        // un-Press button mouse left
        if ( event.type == sf::Event::MouseButtonReleased )
        {
            if ( event.mouseButton.button == sf::Mouse::Left )
            {
                lock_click = false;
            }
        }
        
    }
}


bool Window::isOpen()
{
    return window.isOpen();
}


void Window::update()
{
    eventHandler();
    window.clear( draw::windowBackground );
    drawLines( window );
    
    if ( gAlgorithmsIsWork )
    {
        algSystem->iteration();
        algSystem->draw( window );
    }
    
    drawPoints( window );
    window.display();
}


void Window::_clear()
{
    iter = 0;
    
    // Instance
    algSystem = nullptr;
    systems::pointSys.clear();
}


void Window::_start()
{
    draw::vectorPoint points = systems::pointSys.getVecPoints();
    algSystem = std::make_unique< systems::AlgorithmSystem >();
    algSystem->add( new math::alg::colony::AntColony( points ) );
    algSystem->add( new math::alg::BrutForce( points ) );
}
