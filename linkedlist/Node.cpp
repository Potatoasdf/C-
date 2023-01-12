#include "Node.h"
using namespace std;

Node::Node(Student* newstudent) 
{
  next = NULL;
  student = newstudent;
  
}
Node::~Node()
{
  next = NULL;
  student = NULL;
  cout << "E" << endl;
  
}
Node* Node::getNext()
{
  return next;
}
void Node::setNext(Node* newnext)
{
  next = newnext;
}
Student* Node::getStudent()
{
  return student;
}
