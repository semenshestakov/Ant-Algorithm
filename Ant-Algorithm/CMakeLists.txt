cmake_minimum_required(VERSION 3.12)

project(YourProjectName)

set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")


# Add your source files
set(SOURCE_FILES
    ClassUtils.hpp
    LogUtils.hpp
    Math/Utils.cpp
    Math/Utils.hpp
    Math/point/Point.cpp
    Math/point/Point.hpp
    Math/AntMathColony/AntColony.hpp
    Math/AntMathColony/AntColony.cpp
    Math/AntMathColony/ClassAnt.cpp
    Math/AntMathColony/ClassAnt.hpp
    Math/AntMathColony/ColonyUtils.hpp
    Math/BaseAlgorithm.hpp
    Math/BrutForce/BrutForce.cpp
    Math/BrutForce/BrutForce.hpp
    Math/WriteSystem/WriteFile.cpp
    Math/WriteSystem/WriteFile.hpp
    Graphics/DrawConstans.hpp
    Graphics/Drawer/draw.cpp
    Graphics/Drawer/draw.hpp
    Graphics/Drawer/objects/DrawPoint.cpp
    Graphics/Drawer/objects/DrawPoint.hpp
    Graphics/Window.hpp
    Graphics/Window.cpp
    Systems/AlgorithmSystem.cpp
    Systems/AlgorithmSystem.hpp
    Systems/PointsSystem.cpp
    Systems/PointsSystem.hpp
    main.cpp
)

# Specify include directories
include_directories(/opt/homebrew/Cellar/sfml/2.6.0/include/)

# Specify library directories
link_directories(/opt/homebrew/Cellar/sfml/2.6.0/lib/)

# Add executable
add_executable(main ${SOURCE_FILES})

# Link libraries
target_link_libraries(main sfml-graphics sfml-window sfml-system)
