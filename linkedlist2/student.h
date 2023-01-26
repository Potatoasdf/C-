#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;
class Student
{
  public:
    Student();
    ~Student();
    void getInputs();
    float returnGPA();
    int returnID();
    void print();
    char* first;
    char* last;
    int id;
    float gpa;
};


#endif
