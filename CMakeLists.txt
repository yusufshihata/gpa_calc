cmake_minimum_required(VERSION 3.25)

project(GPACalc)

set(CMAKE CXX STANDARD 17)

set(SOURCES src/main.cpp src/student.h ${YOUR_DIRECTORY}/course.h)

add_executable(GPACalc ${SOURCES})

