#include <iostream>
#include "student.h"
using namespace std;
Student::Student()
{
}
Student::~Student()
{

}
void Student::getInputs()
{
  first = new char[80];
  last = new char[80];
  cout << "First name: ";
  cin >> first;
  cout << "Last name: ";
  cin >> last;
  cout << "Id: ";
  cin >> id;
  cout << "GPA: ";
  cin >> gpa;
  gpa = float((int)(gpa*100+0.5))/100;
}
float Student::returnGPA()
{
  return float((int)(gpa*100+0.5)/100);
}
int Student::returnID()
{
  return id;
}
void Student::print()
{
  cout << first << endl;
  cout << last << endl;
  cout << id << endl;
  cout << gpa << endl;
  cout << "---------" << endl;
  
}
