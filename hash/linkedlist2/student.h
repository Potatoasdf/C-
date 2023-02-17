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
  void returnInputs(char* newfirst, char* newlast, int newid, float newgpa);
  float returnGPA();
  int returnID();
  int acsii(int size);
  void print();
  char* first;
  char* last;
  int id;
  float gpa;
  int hashNum;
};


#endif
