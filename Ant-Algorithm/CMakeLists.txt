cmake_minimum_required(VERSION 3.12)

project(YourProjectName)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Add your source files
set(SOURCE_FILES
    point.cpp 
    WriteFile.cpp
    BaseAnt.cpp 
    ClassAnt.cpp 
    AntColony.cpp  
    draw.cpp 
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
