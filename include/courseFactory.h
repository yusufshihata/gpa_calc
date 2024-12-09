#pragma once

#ifndef COURSEFACTORY_H
#define COURSEFACTORY_H

#include <iostream>
#include <string>

class CourseFactory {
public:
    static void CreateCourse();
    static Course& findCourse(int id);
};

void CourseFactory::CreateCourse() {

    std::string courseName;
    int id, hours, highest;
    char kind = 'A';

    id = numCourses;

    std::cout << "Course Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, courseName);

    std::cout << "Course Credit Hours: ";
    std::cin >> hours;

    while (toupper(kind) != 'P' && toupper(kind) != 'T' && toupper(kind) != 'H') {
        std::cout << "Subject Type (P - H - T): ";
        std::cin >> kind;
    }

    std::cout << "Final Grade: ";
    std::cin >> highest;


    Course course = Course(id, courseName, hours, kind, highest);

    courses.push_back(course);

    std::cout << "Course added successfully.\n";

    ++numCourses;
}

Course& CourseFactory::findCourse(int id) {
    return courses[id];
}

#endif
