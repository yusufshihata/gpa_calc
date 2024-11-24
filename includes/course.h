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
    double studentsGrade[MAX_STUDENTS];
public:
    Course(int id, std::string courseName, int hours, int highest);
    std::string getName();
    int getHours();
    int getCourseId();
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

static std::vector<Course> courses;
static int numCourses = 0;

Course::Course(int id, std::string courseName, int hours, int highest) {
    this->id = id;
    this->courseName = courseName;
    this->hours = hours;
    this->highest = highest;
}

void Course::showCourseInfo() {
    std::cout << "Course Id: " << this->id << "\n";
    std::cout << "Course name: " << this->courseName << "\n";
    std::cout << "Number of hours: " << this->hours << "\n";
    std::cout << "The highest final grade: " << this->highest << "\n";
}

#endif
