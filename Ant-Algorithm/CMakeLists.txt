cmake_minimum_required(VERSION 3.12)

# Явное указание пути к clang
set(CMAKE_C_COMPILER /Library/Developer/CommandLineTools/usr/bin/clang)
set(CMAKE_CXX_COMPILER /Library/Developer/CommandLineTools/usr/bin/clang++)

project(Ant-Algorithm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -O3")

# Пути к заголовочным файлам SFML
include_directories(/opt/homebrew/Cellar/sfml/2.6.0/include/)

add_executable(main main.cpp point.cpp ClassAnt.cpp draw.cpp)

# Пути к библиотекам SFML
target_link_libraries(main PRIVATE /opt/homebrew/Cellar/sfml/2.6.0/lib/libsfml-graphics.dylib
                                     /opt/homebrew/Cellar/sfml/2.6.0/lib/libsfml-window.dylib
                                     /opt/homebrew/Cellar/sfml/2.6.0/lib/libsfml-system.dylib)
