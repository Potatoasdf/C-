#include <cstring>
#include <iostream>
#include "node.h"
using namespace std;
void add(Node** &hash, int size);
//void rehash()
void print(Node** &hash, int size);
//void del(Node* &head, int input, Node* &temp);
void gpaAvg(Node** hash, int size, int count, float total);
int main() 
{
  int size = 101;
  Node** hash = new Node*[size];
  bool alive = true;
  //while alive
  while (alive)
    {
      //get input
      char input[10];
      cout << "Enter ADD, PRINT, DEL, AVG, or QUIT: " << endl;
      cin >> input;
      //if input is QUIT then stop program
      if( strcmp(input, "QUIT") == 0)
      {
        alive = false;
      }
      //if input is ADD start void add
      else if(strcmp(input, "ADD") == 0)
      {

	add(hash, size);
	
      }
      
      //if input is PRINT start void print
      else if( strcmp(input, "PRINT") == 0)
      {
        print(hash, size);
      }
      /*
      //if input is DELETE start void delete
      else if( strcmp(input, "DEL") == 0)
      {
	int input;
	cout << "ID" << endl;
	cin >> input;
        del(head, input, head);
      }
      */
      // return avg gpa
      else if(strcmp(input, "AVG") == 0)
      {
	int count = 0;
	float total = 0;
	if(hash == NULL)
	  {
	    cout << "no students" << endl;
	  }
	else
	  {
	    gpaAvg(hash, size, count, total);
	  }
      }
      
      //if input isnt good
      else
      {
        cout << "Please enter an actual input!" << endl;
      }
      
    }
}
//ascii is wrong
void add(Node** &hash, int size)
{
  int count = 1;
  Student* newstudent = new Student();
  newstudent->getInputs();
  newstudent->print();
  if(hash[newstudent->acsii(size)] == NULL)
    {
      hash[newstudent->acsii(size)] = new Node(newstudent);
      hash[newstudent->acsii(size)]->getStudent()->print();
    }
  else
    {
      Node* newnode = new Node(newstudent);
      cout << "IN" << endl;
      Node* temp = hash[newnode->getStudent()->acsii(size)];
      cout << "C" << endl;
      while (temp->getNext() != NULL)
	{
	  cout << "A" << endl;
	  temp = temp->getNext();
	  cout << "B" << endl;
	  count++;
	}
      
      temp->setNext(newnode);
      cout << "C" << endl;
    }

}




void print(Node** &hash, int size)
{
  for(int i = 0; i < size; i++)
    {
      if(hash[i] != NULL)
	{
	  Node* temp = hash[i];
	  while( temp != NULL)
	    { 
	      temp->getStudent()->print();
	      temp = temp->getNext();
	    }
	}
    }
}
/*
void del(Node* &head, int input, Node* &temp)
{
  //if list empty
  if(head == NULL)
    {
      cout << "you need students" << endl;
    }

  // first student
  else if(head->getStudent()->returnID() == input)
    {
      Node* holder = head;
      temp = head->getNext();
      holder->~Node();
      head = temp;
    }
  //end of list
  else if(temp->getNext() == NULL)
    {
      cout << "No more students" << endl;
    }

  // del if student has id, delete student then replace with student ahead
  else if(temp->getNext()->getStudent()->returnID() == input)
    {
      Node* holder = temp->getNext()->getNext();
      temp->getNext()->~Node();
      temp->setNext(holder);
    }
  //recurse by going to next student
  else
    {
      Node* holder = temp->getNext();
      del(head, input, holder);
    }
}
// get total of all gpa then divide by number of nodes
*/
void gpaAvg(Node** hash, int size, int count, float total)
{
  for (int i = 0; i < size; i++)
    {
      while (hash[i] != NULL)
	{
	  total += hash[i]->getStudent()->returnGPA();
	  count++;
	  hash[i] = hash[i]->getNext();
	}
    }
  cout << float((int)(((total/count)*100)+0.5))/100 << endl;

}

