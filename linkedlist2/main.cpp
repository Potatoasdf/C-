#include <iostream>
#include "node.h"
using namespace std;
void add(Node* &head);
void print(Node* head);
void del(Node* &head);
void gpaAvg(Node* head);
int main() 
{
  Node* head = NULL;
  bool alive = true;
  //while alive
  while (alive)
    {
      //get input
      char input[10];
      cout << "Enter ADD, PRINT, DELETE, AVG, or QUIT: " << endl;
      cin >> input;
      //if input is QUIT then stop program
      if( strcmp(input, "QUIT") == 0)
      {
        alive = false;
      }
      //if input is ADD start void add
      else if(strcmp(input, "ADD") == 0)
      {
        add(head);
      }
      //if input is PRINT start void print
      else if( strcmp(input, "PRINT") == 0)
      {
        print(head);
      }
      //if input is DELETE start void delete
      else if( strcmp(input, "DELETE") == 0)
      {
        del(head);
      }
        //return avg gpa
      else if(strcmp(input, "AVG") == 0)
      {
        gpaAvg(head);
      }
      //if input isnt good
      else
      {
        cout << "Please enter an actual input!" << endl;
      }
      
    }
}
void add(Node* &head)
{  
  Node *newnode = head;
  Student* newstudent = new Student();
  // if node is NULL create a new node and give it input
  if(newnode == NULL)
  {
    head = new Node(newstudent);
    head->getStudent()->getInputs();
    head->getStudent()->print();
  }
  else
  {
    cout << "e" << endl;
    bool cont = true;
    Node* temp = head;
    newnode = new Node(newstudent);
    newnode->getStudent()->getInputs();
    newnode->getStudent()->print();
    while (cont == true)
      {
	if (temp->getNext() == NULL)
        {
          if(temp->getStudent()->returnID() < newnode->getStudent()->returnID())
	    {
	      temp->setNext(newnode);
	    }
	  else
	    {
	      head = newnode;
	      head ->setNext(temp);
	    }
          cont = false;

        }
      

	else if (temp->getNext()->getStudent()->returnID() > newnode->getStudent()->returnID())
	{
	  
	  newnode->setNext(temp->getNext());
	  temp->setNext(newnode);
	  cont = false;
	}
	else
	{
	  temp = temp->getNext();
	}
	
      }  
  }
}
void print(Node* head)
{
  while(head != NULL)
    {
      //print stuff then go to next node
      head->getStudent()->print();
      head = head->getNext();
    }
}
void del(Node* &head)
{
  Student* copy = new Student();
  Node* prev = new Node(copy);
  prev = head;
  Node* current = prev->getNext();
  int input;
  if(head != NULL)
    {
      cout << "ID: " << endl;
      cin >> input;
      if(prev->getStudent()->returnID() == input)
      {
	prev = prev->getNext();
	delete head;
	head = prev;
	 
      }
      while(current != NULL)
      {
	if(prev->getNext()->getStudent()->returnID() == input)
	  {
	    
	    prev->setNext(prev->getNext()->getNext());
	    delete current;
	    
	  }
	else
	  {
	    prev = prev->getNext();
	    current = prev->getNext();
	  }

	
      }
      
    }
  else
    {
      cout << "You need stuff to delete stuff" << endl;
    }
}
// get total of all gpa then divide by number of nodes
void gpaAvg(Node* head)
{
  float total = 0;
  int count = 0;
  while (head != NULL)
    {
      //add gpa to total, increase total students then go to next node
      total += head->getStudent()->returnGPA();
      count++;
      head = head->getNext();
      
    }
  cout << total/count << endl;
}
