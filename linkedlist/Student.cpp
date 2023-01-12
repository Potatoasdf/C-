#include "Student.h"
using namespace std;
Student::Student()
{
}
void Student::check(int num)
{
  exist = num;
}
int Student::getCheck()
{
  return exist;
}
