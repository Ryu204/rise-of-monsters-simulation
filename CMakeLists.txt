cmake_minimum_required(VERSION 3.16)

option(RISE_OF_MONSTERS_SIMULATION_BUILD_TESTS off)

project(rise-of-monsters-simulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

set(
    SOURCE_FILES
    include/rise_of_monsters_simulation.hpp
    include/rise_of_monsters_simulation/adder.hpp
    src/adder.cpp
)

add_library(rise-of-monsters-simulation ${SOURCE_FILES})

target_include_directories(
    rise-of-monsters-simulation
    PUBLIC
    include
)

if(RISE_OF_MONSTERS_SIMULATION_BUILD_TESTS)
    add_subdirectory(test)
endif()
