#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Course.h"
#include <iostream>

class Student {
private:
    int id;
    std::string name;
    int level;
    int registeredHours = 0;
    int allowedHours = 12;
    std::vector<int> registeredCoursesIds;
    std::vector<double> grades;
    double gpa;
public:
    Student() {}
    Student(int id, std::string name, int level): id(id), name(name), level(level) {}
    Student(int id, std::string name, int level, std::vector<int> registeredCoursesIds): id(id), name(name), level(level), registeredCoursesIds(registeredCoursesIds) {}
    int getId();
    void addCourse(int course_id);
    float calculateSubjectGPA(int course_id);
    void calculateGPA();
    void showStudentCourses();
    void displayStudentInfo();
    void addCourseGrade(int course_id, double grade);
    void setName();
    void setLevel();
};

std::vector<Student> students;
int numStudents = 0;

int Student::getId() {
    return this->id;
}

void Student::showStudentCourses() {
    std::cout << "Student Courses: \n";
    for (auto courseId: this->registeredCoursesIds) {
        std::cout << courseId << ". " << courses[courseId].getName() << "\n";
    }
}

void Student::displayStudentInfo() {
    std::cout << "Student Id: " << this->id << "\n" << "Student Name: " << this->name << "\n" << "Student GPA: " << this->gpa << "\n" << "Registered Courses: ";
    for (auto course_id: this->registeredCoursesIds) {
        std::cout << courses[course_id].getName() << ", ";
    }
    std::cout << "\n" << "Registered Hours: " << this->registeredHours << "\n";
}

void Student::addCourse(int course_id) {
    if (course_id > numCourses) {
        std::cout << "Course doesn't Exist.\n";
       return ;
    }

    int updatedHours = this->registeredHours + courses[course_id].getHours();

    if (updatedHours < this->allowedHours) {
        this->registeredHours = updatedHours;
        this->registeredCoursesIds.push_back(course_id);
        std::cout << "Course Registered Successfully\n";
        return ;
    }

    std::cout << "You Can't Register this Course (More than Allowed Credit Hours).\n";
}

float Student::calculateSubjectGPA(int course_id) {
    float percentage = this->grades[course_id] / courses[course_id].getHighestGrade();
    double gpa;

    if (percentage >= 0.96) {
        gpa = 4.0;
    } else if (percentage < 0.96 && percentage >= 0.92) {
        gpa = 3.7;
    } else if (percentage < 0.92 && percentage >= 0.88) {
        gpa = 3.4;
    } else if (percentage < 0.88 && percentage >= 0.84) {
        gpa = 3.2;
    } else if (percentage < 0.84 && percentage >= 0.80) {
        gpa = 3.0;
    } else if (percentage < 0.80 && percentage >= 0.76) {
        gpa = 2.8;
    } else if (percentage < 0.76 && percentage >= 0.72) {
        gpa = 2.6;
    } else if (percentage < 0.72 && percentage >= 0.68) {
        gpa = 2.4;
    } else if (percentage < 0.68 && percentage >= 0.64) {
        gpa = 2.2;
    } else if (percentage < 0.64 && percentage >= 0.60) {
        gpa = 2.0;
    } else if (percentage < 0.60 && percentage >= 0.55) {
        gpa = 1.5;
    } else if (percentage < 0.55 && percentage >= 0.50) {
        gpa = 1.0;
    } else {
        gpa = 0.0;
    }

    if (gpa > 3) { this->allowedHours = 21; }
    else if (gpa < 3 && gpa > 2) { this->allowedHours = 18; }
    else if (gpa < 2 && gpa > 1) { this->allowedHours = 15; }
    else { this->allowedHours = 12; }

    return gpa;
}

void Student::addCourseGrade(int course_id, double grade) {
    this->grades.push_back(grade);
    this->calculateGPA();
}

void Student::calculateGPA() {
    double sum = 0;

    for (auto id: this->registeredCoursesIds) {
        sum += this->calculateSubjectGPA(id) * courses[id].getHours();
    }

    this->gpa = sum / (double) this->registeredHours;
}

void Student::setName() {
    std::string name;

    std::cout << "Please Enter the new name: ";
    std::cin >> name;

    this->name = name;
}

void Student::setLevel() {
    int level;

    std::cout << "Please Enter the new level: ";
    std::cin >> level;

    this->level = level;
}

#endif