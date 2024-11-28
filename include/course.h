#pragma once

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <iostream>

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
    int getKind();
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

int Course::getKind() {
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
    std::cout << "Course Id: " << this->id << "\n";
    std::cout << "Course name: " << this->courseName << "\n";
    std::cout << "Number of hours: " << this->hours << "\n";
    std::cout << "Type of Subject: " << this->kind << "\n";
    std::cout << "The highest final grade: " << this->highest << "\n";
}

#endif

