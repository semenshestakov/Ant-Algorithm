cmake_minimum_required(VERSION 3.15)

project(YourProjectName)
add_executable(my_app main.cpp)

# Укажите C++ стандарт
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавьте опции компиляции (например, оптимизацию)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

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
    /opt/homebrew/Cellar/sfml/3.0.0/include/
)

# Создайте список исходных файлов
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

# Добавьте исполняемый файл
add_executable(main ${SOURCE_FILES} ${HEADER_FILES})

# Укажите библиотеки для линковки
find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(my_app PUBLIC sfml-graphics sfml-window sfml-system)
else()
    message(FATAL_ERROR "SFML not found. Please install SFML.")
endif()

# Укажите правила установки (если нужно)
install(TARGETS main DESTINATION bin)
install(FILES ${HEADER_FILES} DESTINATION include/YourProjectName)
