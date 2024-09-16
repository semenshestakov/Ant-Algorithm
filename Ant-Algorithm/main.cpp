#include <ctime>
#include <unistd.h>
#include "Graphics/Window.hpp"

///opt/homebrew/Cellar/sfml/2.6.0
///clang++ -std=c++20 point.cpp WriteFile.cpp BaseAnt.cpp ClassAnt.cpp AntColony.cpp  draw.cpp main.cpp -I/opt/homebrew/Cellar/sfml/2.6.0/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.0/lib/ -lsfml-graphics -lsfml-window -lsfml-system


Window window = {900, 600, "AntAlg"};

int main() {
    srand( time_t( nullptr ) );
    while ( window.isOpen() )
    {
        window.update();
    }
    
}

