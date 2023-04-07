#include <iostream>
#include "treenode.h"
#include <cstring>
#include <cmath>

using namespace std;

void print(treenode* tree, int space);
void add(treenode* &tree, treenode* &head, int input);

int main()
{
  treenode* tree = NULL;
  bool alive = true;
  while(alive)
    {
      int input;
      cin >> input;
      add(tree, tree, input);
  
      print(tree, 0);
    }
  return 0;
}
void add(treenode* &tree, treenode* &head, int input)
{
  treenode* newnode = new treenode(input);
  if(head == NULL)
    {
      cout << "head" << endl;
      head = new treenode(input);
    }
  else if(tree->getR() != NULL && tree->getNum() <= input)
    {
          cout << "going R" << endl;
          treenode* temp = tree->getR();
          add(temp, head, input);
     
    }
  
  else if ( tree->getL() != NULL && tree->getNum() > input)
    {
      cout << "going L" << endl;
      treenode* temp = tree->getL();
      add(temp, head, input);
      
    }
  
  else
    {
      cout << "IN" << endl;
      if(tree->getR() == NULL && tree->getNum() <= input)
        {
          cout << "R" << endl;
          tree->setR(newnode);
        }

    
      else
	{
	  if(tree->getL() == NULL && tree->getNum() > input)
	    {
	      cout << "L" << endl;
	      tree->setL(newnode);
	    }
	  
	}
    }

}
// taken from heap
void print(treenode* tree, int space)
{
  //keep adding space till empty index
  if(tree == NULL)
    {
      return;
    }
  space += 10;

  print(tree->getR(), space);
  //print space than heap index
  cout << "\n" << endl;
  for(int i = 10; i < space;i++)
    {
      cout << " ";
    }
  cout << tree->getNum() << endl;
  print(tree->getL(), space);
}
