#include <ctime>
#include "draw.hpp"
#include "AntColony.hpp"
#include "WriteFile.hpp"
#include <unistd.h>
///opt/homebrew/Cellar/sfml/2.6.0
///clang++ -std=c++20 point.cpp WriteFile.cpp BaseAnt.cpp ClassAnt.cpp AntColony.cpp  draw.cpp main.cpp -I/opt/homebrew/Cellar/sfml/2.6.0/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.0/lib/ -lsfml-graphics -lsfml-window -lsfml-system
#define N 900
#define M 600

static bool lock_click = false;
static bool enter_click = false;
static size_t iter = 0;

void startAlg();
void clearAlg();
void test(){
    vecPoints.push_back(make_shared<Point>(179, 216));
    vecPoints.push_back(make_shared<Point>(381, 72));
    vecPoints.push_back(make_shared<Point>(377, 303));
    vecPoints.push_back(make_shared<Point>(630, 173));
    vecPoints.push_back(make_shared<Point>(503, 346));
    vecPoints.push_back(make_shared<Point>(700, 227));
    vecPoints.push_back(make_shared<Point>(585, 59));
    vecPoints.push_back(make_shared<Point>(413, 213));
    vecPoints.push_back(make_shared<Point>(184, 416));
    vecPoints.push_back(make_shared<Point>(696, 404));
    vecPoints.push_back(make_shared<Point>(739, 250));
    vecPoints.push_back(make_shared<Point>(781, 71));
    vecPoints.push_back(make_shared<Point>(168, 84));
    vecPoints.push_back(make_shared<Point>(98, 269));
    vecPoints.push_back(make_shared<Point>(99, 476));
    vecPoints.push_back(make_shared<Point>(430, 487));
    vecPoints.push_back(make_shared<Point>(690, 550));
}
AntColony colony;

int main() {
    srand(time_t(nullptr));
    sf::RenderWindow window(sf::VideoMode(N, M), "AntAlg");
    test();
    while (window.isOpen()) {
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
//                        test();
                        startAlg();
                    } else {
                        clearAlg();
                    }
                }
                if (event.key.code == sf::Keyboard::S){
                    File file;
                    file.save();
                }
                if (event.key.code == sf::Keyboard::R){
//                    string temp;
                    
//                    cout << "Read name save (Q - close): ";
//                    cin >> temp;
//                    if (temp == "Q") { continue;}
                    File file;
                    file.read();
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
        
        // Display
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
}


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
