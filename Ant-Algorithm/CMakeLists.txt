cmake_minimum_required(VERSION 3.15)

project(YourProjectName)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/cmake/SFML")
set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/SFML")


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Math
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics/Drawer
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics/Drawer/objects
    ${CMAKE_CURRENT_SOURCE_DIR}/Systems
    ${CMAKE_CURRENT_SOURCE_DIR}/SFML/include
)

file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.cxx" "*.cc" "*.c")
file(GLOB_RECURSE HEADER_FILES "*.hpp" "*.hxx" "*.h")

add_executable(main ${SOURCE_FILES} ${HEADER_FILES})

find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Window System)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(main PUBLIC SFML::Graphics SFML::Window SFML::System)
else()
    message(FATAL_ERROR "SFML not found. Please install SFML.")
endif()

install(TARGETS main DESTINATION bin)
install(FILES ${HEADER_FILES} DESTINATION include/YourProjectName)
