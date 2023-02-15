#include <cstring>
#include <iostream>
#include "node.h"
using namespace std;
void add(Node** &hash, int size);
void rehash(Node** &hash, int &size);
void print(Node** &hash, int size);
void del(Node** &hash, int size);
void gpaAvg(Node** &hash, int size, int count, float total);
int main() 
{
  int size = 101;
  Node** hash = new Node*[size];
  for (int i = 0; i< size; i++)
    {
      hash[i] = NULL;
      
    }
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
      
      //if input is DELETE start void delete
      else if( strcmp(input, "DEL") == 0)
      {

        del(hash, size);
      }
      
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
  int count = 0;
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
      count++;
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
  if (count == 4)
    {
      cout << "here" << endl;
      rehash(hash, size);
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

void del(Node** &hash, int size)
{
  bool confirm = false;
  if (hash != NULL)
    {
      
      int input;
      cout << "ID: " << endl;
      cin >> input;
      for ( int i = 0; i < size; i++)
	{
	  if (hash[i] != NULL)
	    {
	    }
	}
    }
  else
    {
      cout << "You need inputs to delete!" << endl;
    }
}
// get total of all gpa then divide by number of nodes

void gpaAvg(Node** &hash, int size, int count, float total)
{
  for (int i = 0; i < size; i++)
    {
      Node* temp = hash[i];
      while (temp != NULL)
	{
	  total += temp->getStudent()->returnGPA();
	  cout << total << endl;
	  count++;
	  temp = temp->getNext();
	}
    }
  cout << float((int)(((total/count)*100)+0.5))/100 << endl;

}

void rehash(Node** &hash, int &size)
{
  
  size = size * 2;
  Node** temp = new Node*[size];
  for (int i = 0; i < size; i++)
    {
      temp[i] = NULL;
    }
  for (int i = 0; i < (size/2); i++)
    {
      if(hash[i] != NULL)
	{
	  Node* current = hash[i];
	  while(current != NULL)
	    {
	      if(temp[current->getStudent()->acsii(size)] == NULL)
		{
		  cout << "BLAP" << endl;
		  temp[current->getStudent()->acsii(size)] = current;
		}
	      else
		{
		  cout << "SMTHG" << endl;
		  Node* endNode = temp[current->getStudent()->acsii(size)];
                  cout << "HM" << endl;
		  while (endNode->getNext() != NULL)
		    {
		      
		      endNode = endNode->getNext();
		      cout << "yey" << endl;
		    }
		  endNode->setNext(current);
		  cout << "HM" << endl;
		}
	      current = current->getNext();
	    }
	}
    }
  cout << "WOW" << endl;
  delete[] hash;
  hash = temp;
  
}
