#pragma once

#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <string>

static bool run = true;

class MainMenu {
public:
    static void ui();
    static void addCourseUi();
    static void addStudentUi();
    static void getCourseInfoUi();
    static void getStudentInfoUi();
    static void addStudentCourseUi();
    static void addStudentCourseGradeUi();
    static void controlUi();
};

void MainMenu::ui() {
    std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "Welcome to the Artificial Intelligence Faculty Student Database\n";
    std::cout << "1. Add Course.\n";
    std::cout << "2. Add Student.\n";
    std::cout << "3. Add Course to Student.\n";
    std::cout << "4. Add Course Grade to Student.\n";
    std::cout << "5. Get Course Info.\n";
    std::cout << "6. Get Student Info.\n";
    std::cout << "7. Exit the database.\n";
    std::cout << "\nPress the number of the process you need to do (1-7).\n";
    std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void MainMenu::addCourseUi() {
    CourseFactory::CreateCourse();
}

void MainMenu::addStudentUi() {
    StudentFactory::CreateStudent();
}

void MainMenu::getStudentInfoUi() {
    int id;

    std::cout << "Enter the student's id: ";
    std::cin >> id;

    Student student = StudentFactory::findStudent(id);


    std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
    
    student.displayStudentInfo();
    
    std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void MainMenu::getCourseInfoUi() {
    int id;

    std::cout << "Enter the course's id: ";
    std::cin >> id;

    Course course = CourseFactory::findCourse(id);

    std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";

    course.showCourseInfo();

    std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void MainMenu::addStudentCourseUi() {
    int id;

    std::cout << "Please Input the student's id: ";
    std::cin >> id;

    Student *student = &StudentFactory::findStudent(id);

    for (int i = 0; i < numCourses; ++i) {
        std::cout << courses[i].getCourseId() << ". " << courses[i].getName() << std::endl;
    }

    int idx;

    std::cout << std::endl << "Please Enter the id of the course you want to add: ";
    std::cin >> idx;

    student->addCourse(idx);
}

void MainMenu::addStudentCourseGradeUi() {
    int id;

    std::cout << "Please Enter the student's id: ";
    std::cin >> id;

    Student& student = StudentFactory::findStudent(id);

    student.showStudentCourses();

    int idx;

    std::cout << "Please Enter the id of the course you need to add the grade for: ";
    std::cin >> idx;

    double grade;

    std::cout << "Please Enter the grade for this course: ";
    std::cin >> grade;

    student.addCourseGrade(idx, grade);
}

void MainMenu::controlUi() {
    int choice;

    std::cin >> choice;

    if (choice == 1) {
        MainMenu::addCourseUi();
    } else if (choice == 2) {
        MainMenu::addStudentUi();
    } else if (choice == 3) {
        MainMenu::addStudentCourseUi();
    } else if (choice == 4) {
        MainMenu::addStudentCourseGradeUi();
    } else if (choice == 5) {
        MainMenu::getCourseInfoUi();
    } else if (choice == 6) {
        MainMenu::getStudentInfoUi();
    } else if (choice == 7) {
        run = false;
    } else {
        std::cout << "Invalid Operation.\n";
    }
}

#endif

