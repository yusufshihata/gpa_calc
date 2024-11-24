cmake_minimum_required(VERSION 3.25)

project(GPACalc)

set(CMAKE CXX STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCE src/main.cpp)
set(HEADER_FILES ${CMAKE_SOURCE_DIR}/include/student.h ${CMAKE_SOURCE_DIR}/include/course.h)

add_executable(GPACalc ${SOURCE} ${HEADER_FILES})

