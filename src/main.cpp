#include <iostream>
#include <vector>
#include <math.h>
#include <string>

#include "course.h"
#include "student.h"
#include "studentFactory.h"
#include "courseFactory.h"
#include "mainmenu.h"

int main() {
    while (run) {
        MainMenu::ui();

        MainMenu::controlUi();
    }

    return 0;
}
