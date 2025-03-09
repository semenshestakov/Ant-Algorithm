cmake_minimum_required(VERSION 3.15)

project(YourProjectName)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "{}")

# Укажите пути к include папкам
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Math
    ${CMAKE_CURRENT_SOURCE_DIR}/Math/AntMathColony
    ${CMAKE_CURRENT_SOURCE_DIR}/Math/BrutForce
    ${CMAKE_CURRENT_SOURCE_DIR}/Math/point
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics/Drawer
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics/Drawer/objects
    ${CMAKE_CURRENT_SOURCE_DIR}/Systems
    ${CMAKE_CURRENT_SOURCE_DIR}/SFML/include
)

file(GLOB_RECURSE SOURCE_FILES
    "*.cpp"
    "*.cxx"
    "*.cc"
    "*.c"
)
file(GLOB_RECURSE HEADER_FILES
    "*.hpp"
    "*.hxx"
    "*.h"
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/cmake/SFML")
set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/SFML")

add_executable(main ${SOURCE_FILES} ${HEADER_FILES})

find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Window System Network)
if (SFML_FOUND)
    target_link_libraries(main PUBLIC SFML::Graphics SFML::Window SFML::System SFML::Network)
else()
    message(FATAL_ERROR "SFML not found. Please install SFML.")
endif()


install(FILES ${HEADER_FILES} DESTINATION include/YourProjectName)
