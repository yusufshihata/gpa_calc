cmake_minimum_required(VERSION 3.25)

project(GPACalc)

set(CMAKE CXX STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/includes)

set(SOURCE src/main.cpp)

add_executable(GPACalc ${SOURCE})

