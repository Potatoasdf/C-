#include <iostream>
#include "node.h"

using namespace std;

int main()
{
  Node** heap = new Node*[100];
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
