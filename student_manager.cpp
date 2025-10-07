#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students++] = Student(name, id, midterm, final);
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);
    if (idx >= 0) {
        for (int i = idx; i < num_of_students - 1; i++) {
            students[i] = students[i + 1];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int idx = findStudentByID(student.getID());
    if (idx >= 0) {
        students[idx] = student;
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getID() == id) {
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    int maxScore = students[0] .getRecord().getMidterm();
    int idx = 0;

    for (int i = 1; i < num_of_students; i++) {
        if (students[i].getRecord().getMidterm() > maxScore) {
            maxScore = students[i].getRecord().getMidterm();
            idx = i;
        }
    }
    return idx;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    int maxScore = students[0] .getRecord().getFinal();
    int idx = 0;

    for (int i = 1; i < num_of_students; i++) {
        if (students[i].getRecord().getFinal() > maxScore) {
            maxScore = students[i].getRecord().getFinal();
            idx = i;
        }
    }
    return idx;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    int maxScore = students[0] .getRecord().getMidterm() + students[0] .getRecord().getFinal();
    int idx = 0;

    for (int i = 1; i < num_of_students; i++) {
        if (students[i].getRecord().getMidterm() + students[i].getRecord().getFinal()> maxScore) {
            maxScore = students[i].getRecord().getMidterm() + students[i] .getRecord().getFinal();
            idx = i;
        }
    }
    return idx;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float total = 0.0f;

    for (int i = 0; i < num_of_students; i++) {
        total += students[i].getRecord().getMidterm();
    }
    return total / num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float total = 0.0f;

    for (int i = 0; i < num_of_students; i++) {
        total += students[i].getRecord().getFinal();
    }
    return total / num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float total = 0.0f;

    for (int i = 0; i < num_of_students; i++) {
        total += (students[i].getRecord().getMidterm() + students[i].getRecord().getFinal());
    }
    return total / num_of_students;
}

