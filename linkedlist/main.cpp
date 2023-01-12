#include <iostream>
#include "Node.h"
using namespace std;
int main()
{
  Node* node1 = NULL;
  Node* node = NULL;
  Student* newstudent = new Student();
  //constructor
  node = new Node(newstudent);
  //check uses getStudent to get to check function and then check if it worked
  int a = node -> getStudent() -> check();
  if( a == 1)
    {
      cout << "works" << endl;
    }
  //uses getNext to make node equal to next
  node = node -> getNext();
  cout << "a" << endl;
  node -> setNext(node1);
  
  
  //destructor
  delete node;
}
