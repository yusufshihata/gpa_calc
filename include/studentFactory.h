#pragma once

#ifndef STUDENTFACTORY_H
#define STUDENTFACTORY_H

#include <iostream>
#include <string>

class StudentFactory {
public:
    static void CreateStudent();
    static Student& findStudent(int id);
};

void StudentFactory::CreateStudent() {
    std::string studentName;
    int id, level;

    id = numStudents;

    std::cout << "Student Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, studentName);

    std::cout << "Student Level: ";
    std::cin >> level;

    Student student = Student(id, studentName, level);

    students.push_back(student);

    std::cout << "Student added successfully.\n";
}

Student& StudentFactory::findStudent(int id) {
    return students[id];
}

#endif
