#pragma once

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#define MAX_STUDENTS 400

class Course {
private:
    int id;
    std::string courseName;
    int hours;
    int highest;
    char kind;
    double studentsGrade[MAX_STUDENTS];
public:
    Course(int id, std::string courseName, int hours, char kind, int highest);
    std::string getName();
    int getHours();
    int getCourseId();
    char getKind();
    int getHighestGrade();
    void showCourseInfo();
};

std::string Course::getName() {
    return this->courseName;
}

int Course::getHours() {
    return this->hours;
}

int Course::getCourseId() {
    return this->id;
}

int Course::getHighestGrade() {
    return this->highest;
}

char Course::getKind() {
    return this->kind;
}

static std::vector<Course> courses;
static int numCourses = 0;

Course::Course(int id, std::string courseName, int hours, char kind, int highest) {
    this->id = id;
    this->courseName = courseName;
    this->hours = hours;
    this->kind = kind;
    this->highest = highest;
}

void Course::showCourseInfo() {
    const int tableWidth = 65;
    std::string s(1, this->kind);
    
    std::cout << "| " << std::setw(tableWidth - 1) << std::left << "Course Id: " + std::to_string(this->id) << "|\n";
    std::cout << "| " << std::setw(tableWidth - 1) << std::left << "Course Name: " + this->courseName << "|\n";
    std::cout << "| " << std::setw(tableWidth - 1) << std::left << "Number of Credit hours for this course: " + std::to_string(this->hours) << "|\n";
    std::cout << "| " << std::setw(tableWidth - 1) << std::left << "Type of Course: " + s << "|\n";
    std::cout << "| " << std::setw(tableWidth - 1) << std::left << "The highest final grade: " + std::to_string(this->highest) << "|\n";
}

#endif

