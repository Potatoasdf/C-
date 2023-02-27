#include <iostream>
#include "node.h"

using namespace std;
void add (Node** &heap);
void sort(Node** &heap);

int main()
{
  int count = 0;
  Node** heap = new Node*[200];
  for( int i = 0; i < 200; i++)
    {
      heap[i] = NULL;
    }
  bool alive = true;
  while (alive)
    {
      //get input
      char input[10];
      cout << "Enter ADD, PRINT, DELETE, or QUIT: " << endl;
      cin >> input;
      //if input is QUIT then stop program
      if( strcmp(input, "QUIT") == 0)
      {
        alive = false;
      }
      //if input is ADD start void add
      else if(strcmp(input, "ADD") == 0)
      {
	add(heap);
        
      }
      //if input is PRINT start void print
      else if( strcmp(input, "PRINT") == 0)
      {
        
      }
      //if input is DELETE start void delete
      else if( strcmp(input, "DELETE") == 0)
      {
        
      }
      //if input isnt good
      else
      {
        cout << "Please enter an actual input!" << endl;
      }
    }

}
void add(Node** &heap)
{
  
  int input;
  cin >> input;

  Node* newnode = new Node(input);
  int count = 0;
  while(heap[count] != NULL)
    {
      count++;
    }
  heap[count] = newnode;
  sort(heap);

}
void sort(Node** &heap)
{

}
