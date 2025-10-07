#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final) 
    : midterm(midterm), final(final)
{
/* TODO: Initializer list 사용해 초기화 해보기 */    
}

float StudentRecord::getTotal() const {
    /* TODO */
    return (midterm + final) / 2.0f;
}

void StudentRecord::updateScores(float midterm, float final) {
    /* TODO: this keyword 사용해 보기 */
    this->midterm = midterm;
    this->final = final;
}


/* Student */

Student::Student() 
    : name(""), id(0), record(0.0f, 0.0f)
{
/* TODO: Initializer list 사용해 초기화 해보기 */
}

Student::Student(const char *name, int id, float midterm, float final) 
    : name(name), id(id), record(midterm, final)
{
/* TODO: Initializer list 사용해 초기화 해보기 */
}

/* 학생 ID는 입력받을 필요가 없다. ID는 고유한 값이므로 변경하면 안되기 때문이다.
   만약 학생 ID를 변경해야 한다면, StudentManager 클래스에서 관리해야 한다. */
void Student::updateRecord(const char *name, float midterm, float final) {
    /* TODO */
    this->name = name;
    record.updateScores(midterm, final);
}

