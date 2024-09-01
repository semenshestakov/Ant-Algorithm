//  Created by Семён Шестаков on 01.06.2024.
#include "Window.hpp"


Window::Window( uint _x, uint _y, std::string _name ) : window( sf::VideoMode( _x, _y ), _name )
{
    algSystem = make_unique< AlgorithmSystem >();
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
                    _start();
                else
                    _clear();
            }
        }
        
        // Press button mouse left
        if ( event.type == sf::Event::MouseButtonPressed )
        {
            if ( event.mouseButton.button == sf::Mouse::Left && lock_click != true )
            {
                obj::ptrPoint temp ( new obj::Point( X, Y ) );
                obj::vecPoints.push_back( temp );
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
    
    drawVecPoints( window );
    window.display();
}


void Window::_clear()
{
    // Global
    obj::vecPoints = {};
    //obj::fullDist = {};
    iter = 0;
    
    // Instance
    algSystem = nullptr;
    
}


void Window::_start()
{    
    algSystem = make_unique< AlgorithmSystem >();
    //algSystem->add( new math::alg::colony::AntColony( obj::vecPoints ) );
    algSystem->add( new math::alg::BrutForce( obj::vecPoints ) );
}
