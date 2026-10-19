cmake_minimum_required(VERSION 3.16)

option(RISE_OF_MONSTERS_SIMULATION_BUILD_TESTS off)

project(rise-of-monsters-simulation LANGUAGES CXX VERSION 0.1)

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
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS rise-of-monsters-simulation
    EXPORT rise-of-monsters-simulation
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include)
install(EXPORT rise-of-monsters-simulation
    FILE rise-of-monsters-simulation-targets.cmake
    DESTINATION lib/cmake/rise-of-monsters-simulation
)
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/rise-of-monsters-simulation-config-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMinorVersion
)
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/rise-of-monsters-simulation-config.cmake"
    INSTALL_DESTINATION lib/cmake/rise-of-monsters-simulation
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/rise-of-monsters-simulation-config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/rise-of-monsters-simulation-config-version.cmake"
    DESTINATION lib/cmake/rise-of-monsters-simulation
)

if(RISE_OF_MONSTERS_SIMULATION_BUILD_TESTS)
    add_subdirectory(test)
endif()
