#include <cstring>
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
  return gpa;
}
int Student::returnID()
{
  return id;
}
int Student::acsii(int size)
{
  for(int i = 0; i < strlen(first); i++)
    {
      hashNum += first[i];
    }
  for(int i = 0; i < strlen(last); i++)
    {
      hashNum += last[i];
    }
  return hashNum%size;

}
void Student::print()
{
  cout << first << endl;
  cout << last << endl;
  cout << id << endl;
  cout << gpa << endl;
  cout << "---------" << endl;
  
}
