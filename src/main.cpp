#include <iostream>
#include <vector>
#include <math.h>
#include <string>

#include "course.h"
#include "student.h"

#define MAX_STUDENTS 400
#define MAX_COURSES 40


bool run = true;

class CourseFactory {
public:
    static void CreateCourse();
    static Course& findCourse(int id);
};

void CourseFactory::CreateCourse() {

    std::string courseName;
    int id, hours, highest;

    id = numCourses;

    std::cout << "Course Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, courseName);

    std::cout << "Course Credit Hours: ";
    std::cin >> hours;

    std::cout << "Final Grade: ";
    std::cin >> highest;

    Course course = Course(id, courseName, hours, highest);

    courses.push_back(course);

    std::cout << "Course added successfully.\n";

    ++numCourses;
}

Course& CourseFactory::findCourse(int id) {
    return courses[id];
}

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

class MainMenu {
public:
    void ui();
    void addCourseUi();
    void addStudentUi();
    void getCourseInfoUi();
    void getStudentInfoUi();
    void addStudentCourseUi();
    void addStudentCourseGradeUi();
    void controlUi();
    ~MainMenu() {}
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
    MainMenu menu;

    std::cin >> choice;

    if (choice == 1) {
        menu.addCourseUi();
    } else if (choice == 2) {
        menu.addStudentUi();
    } else if (choice == 3) {
        menu.addStudentCourseUi();
    } else if (choice == 4) {
        menu.addStudentCourseGradeUi();
    } else if (choice == 5) {
        menu.getCourseInfoUi();
    } else if (choice == 6) {
        menu.getStudentInfoUi();
    } else if (choice == 7) {
        run = false;
    } else {
        std::cout << "Invalid Operation.\n";
    }
}

int main() {
    MainMenu menu;

    while (run) {
        menu.ui();

        menu.controlUi();
    }

    return 0;
}
