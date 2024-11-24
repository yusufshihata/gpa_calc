#include <iostream>
#include <vector>
#include <math.h>
#include <string>

#define MAX_STUDENTS 400
#define MAX_COURSES 40


bool run = true;

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

std::vector<Course> courses;
int numCourses = 0;

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
