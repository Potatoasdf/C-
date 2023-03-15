#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include "node.h"
using namespace std;
void add(Node** &hash, int &size);
void rehash(Node** &hash, int &size);
void print(Node** &hash, int size);
void delExtra(Node** &hash, int size);
void del(Node* &head, int input, Node* &temp, Node** &hash, int size, int iteration, bool &confirm);
void gpaAvg(Node** &hash, int size, int count, float total);
void generateRand(int &studentID, Node** &hash, int &size);
int main() 
{
  int randID = 1;
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
      cout << "Enter ADD, PRINT, DEL, AVG, GEN, or QUIT: " << endl;
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

        delExtra(hash, size);
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

      else if (strcmp(input, "GEN") == 0)
	{
	  generateRand(randID, hash, size);
	}
       
      //if input isnt good
      else
      {
        cout << "Please enter an actual input!" << endl;
      }
     
    }
}
//ascii is wrong
void add(Node** &hash, int &size)
{
  int count = 0;
  Student* newstudent = new Student();
  newstudent->getInputs();
  newstudent->print();
  //finds the acsii of the student and puts it in the entry num if its the first student
  if(hash[newstudent->acsii(size)] == NULL)
    {
      hash[newstudent->acsii(size)] = new Node(newstudent);
      hash[newstudent->acsii(size)]->getStudent()->print();
    }
  else
    {
      // else iterate to the end of the entry and put the newnode there
      count++;
      Node* newnode = new Node(newstudent);
      Node* temp = hash[newnode->getStudent()->acsii(size)];
      while (temp->getNext() != NULL)
	{
	  temp = temp->getNext();
	  count++;
	}
      temp->setNext(newnode);
    }
  cout << count << endl;
  // if hash gets to crowded rehash
  if (count > 3)
    {
      
      rehash(hash, size);
    }

}




void print(Node** &hash, int size)
{
  // iterates through heap to find entrys that arent empty and then iterates through the entry and prints everything in the entry
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

// bassically copied from linkedlist2
void del(Node* &head, int input, Node* &temp, Node** &hash, int size, int iteration, bool &confirm)
{
  
  //if list empty
  if (head == NULL)
    {
      cout << "you need students" << endl;
    }
  // first student
  else if(head->getStudent()->returnID() == input)
    {
      Node* holder = head;
      temp = head->getNext();
      delete holder;
      head = temp;
      hash[iteration] = head;
      confirm = true;
      
    }
  // del if student has id, delete student then replace with student ahead
  else if (temp->getNext() != NULL)
    {
      if(temp->getNext()->getStudent()->returnID() == input)
	{
	  
	  Node* holder = temp->getNext()->getNext();
	  delete temp->getNext();
	  temp->setNext(holder);
	  hash[iteration] = temp;
	  confirm = true;
	}
    }
  //recurse by going to next student
  else if (temp->getNext() != NULL)
    {
      
      Node* holder = temp->getNext();
      del(head, input, holder, hash, size, iteration, confirm);
    }
  else
    {
      
    }
}

void delExtra(Node** &hash, int size)
{
  //gets id than finds the entrys that arent empty and then goes into recursive
  bool confirm = false;
  if (hash != NULL)
    {
      
      int input;
      cout << "ID: " << endl;
      cin >> input;
      for ( int i = 0; i < size; i++)
	{
	  if (confirm == true)
	    {
	      break;
	    }
	  
	  else if (hash[i] != NULL)
	    {
	      cout << "HERE" << endl;
	      Node* head = hash[i];
	      del(head, input, head, hash, size, i, confirm);
	    }
	}
      if (confirm == false)
	{
	  cout << "No Students with ID" << endl;
	}
    }
  else
    {
      cout << "You need inputs to delete!" << endl;
    }
}
// go through the entries and iterate through the entries to add up all the gpa values then average it out

void gpaAvg(Node** &hash, int size, int count, float total)
{
  for (int i = 0; i < size; i++)
    {
      Node* temp = hash[i];
      while (temp != NULL)
	{
	  total += temp->getStudent()->returnGPA();
	  
	  count++;
	  temp = temp->getNext();
	}
    }
  cout << float((int)(((total/count)*100)+0.5))/100 << endl;

}

void rehash(Node** &hash, int &size)
{
  // double size and make it into new hash
  size = size * 2;
  
  Node** temp = new Node*[size];
  for (int i = 0; i < size; i++)
    {
      temp[i] = NULL;
    }
  //go through hash entries until find one not empty
  for (int i = 0; i < (size/2); i++)
    {
      if(hash[i] != NULL)
	{
	  //go till end of entry 
	  Node* current = hash[i];
	  while(current != NULL)
	    {
	      // entry in temp is empty then add current to it
	      Node* tempCurrent = current;
	      if(temp[current->getStudent()->acsii(size)] == NULL)
		{
		  current = current->getNext();
                  tempCurrent->setNext(NULL);
		  temp[tempCurrent->getStudent()->acsii(size)] = tempCurrent;
	        }
	      // else go to the end of the temp entry and then add
	      else
		{
		  Node* endNode = temp[tempCurrent->getStudent()->acsii(size)];
		  while( endNode->getNext() != NULL)
		    {
		      endNode = endNode->getNext();
		    }
		  current = current->getNext();
                  tempCurrent->setNext(NULL);
		  endNode->setNext(tempCurrent);
		
		}
	      
	    }
	}
    }
  
  delete[] hash;
  hash = temp;
  
}
void generateRand(int &studentID, Node** &hash, int &size)
{
  
  int input;
  cout << "How many student do you want to make" << endl;
						    
  cin >> input;
  bool go = false;
  char* firstInput = new char[80];
  char* lastInput = new char[80];
  srand(time(NULL));
  //input file stream
  ifstream firstname("firstname.txt");
  ifstream lastname("lastname.txt");
  // getting input number of random names
  for ( int i = 0; i < input; i++)
    {
      int lastrand = rand()%20;
      cout << lastrand << endl;
      int firstrand = rand()%20;
      cout << firstrand << endl;
      Student* newstudent = new Student();
      for(int j = 0; j < 100; j++)
	{
	  if(firstrand == j)
	    {
	      firstname >> firstInput;
	    }
	  else if (j < firstrand)
	    {
	      firstname >> firstInput;
	    }
	  if(lastrand == j)
	    {
	      lastname >> lastInput;
	    }
	  else if (j < lastrand)
            {
              lastname >> lastInput;
            }

	}
      // putting them into students
      newstudent->returnInputs(firstInput, lastInput, studentID, float(float(rand()%5 + 1) + float(rand()%100) / 100));
      studentID++;
      newstudent->print();
      firstname.close();
      lastname.close();
      firstname.open("firstname.txt");
      lastname.open("lastname.txt");
      //cpy from add func
      int count = 0;
      if(hash[newstudent->acsii(size)] == NULL)
	{
	  hash[newstudent->acsii(size)] = new Node(newstudent);
	}
      else
	{
	  // else iterate to the end of the entry and put the newnode there
	  count++;
	  Node* newnode = new Node(newstudent); 
	  Node* temp = hash[newnode->getStudent()->acsii(size)];
	  while (temp->getNext() != NULL)
	    {
	      temp = temp->getNext();
	      count++;
	    }
	  temp->setNext(newnode);
	}
      
      // if hash gets to crowded rehash
      if (count == 3)
	{
	  rehash(hash, size);
	}
      
    }
}
