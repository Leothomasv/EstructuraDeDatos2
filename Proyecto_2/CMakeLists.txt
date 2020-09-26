cmake_minimum_required(VERSION 3.8)
project(Proyecto_2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp CSV.cpp pbPlots.cpp supportLib.cpp)
