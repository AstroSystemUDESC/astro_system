cmake_minimum_required(VERSION 4.2)
project(astro_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(astro_system main.cpp
        includes/positionStar.h
        stars/positionStar.cpp
        stars/calcPositionStar.cpp
        includes/menu.h
        menu/menu.cpp
        includes/moon.h
        moon/calcMoonPhase.cpp)
