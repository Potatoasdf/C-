#include <iostream>
#include "Node.h"
using namespace std;

void add(Node* &head, int &input, Student* newstudent);
void print(Node* next, Node* &head);
int main() 
{
  //vars and inputs
  Student *newstudent;
  Node* head = NULL;
  int input = 0;
  add(head, input, newstudent);
  input++;
  add(head, input, newstudent);
  input++;
  add(head, input, newstudent);
  input++;
  print(head, head);
  head->getNext()->setNext(NULL);
  delete head->getNext()->getNext();
  print(head, head);
}

void add(Node* &head, int &input, Student* newstudent)
{
  //add a new node
  Node *newnode = head;
  newstudent = new Student();
  // if node is NULL create a new node and give it input
  if(newnode == NULL)
  {
    head = new Node(newstudent);
    head->getStudent()->check(input);
    cout << head->getStudent()->getCheck() << endl;
  }
  else
  {//if node != NULL then go through each node till the next node is NULL
    while(newnode->getNext()!= NULL)
    {
      newnode = newnode->getNext();
    }
    //give node input and create the next node
    newnode->setNext(new Node(newstudent));
    newnode->getNext()->getStudent()->check(input);
    cout << newnode->getNext()->getStudent()->getCheck() << endl;

    
  }
  
}
void print(Node* next, Node* &head)
{
  if(next == head)
  {
    cout << "List" << endl;

  }
  if(next != NULL)
  {
    //print the num in the node then move to the next node
    cout << next->getStudent()->getCheck() << endl;
    print(next->getNext(), head);
  }
}
