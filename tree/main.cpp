#include <iostream>
#include "treenode.h"
#include <cstring>
#include <cmath>

using namespace std;

void print(treenode* tree, int space);
void add(treenode* &tree, treenode* &head, int input);
void search(treenode* tree, treenode* head, int input);
void del(treenode* &tree, treenode* &head, int input);


int main()
{
  int input;
  treenode* tree = NULL;
  bool alive = true;
  while(alive)
    {
      char command[10];
      cout << "ADD, PRINT, DEL, SEARCH, GEN, SERIES, QUIT" << endl;
      cin >> command;
      if(strcmp(command, "ADD") == 0)
	{
	  
	  cin >> input;
	  add(tree, tree, input);
	}
      else if(strcmp(command, "PRINT") == 0)
	{
	  print(tree, 0);
	}
      else if(strcmp(command, "SEARCH") == 0)
	{
	  cin >> input;
	  search(tree, tree, input);
	}
      else if(strcmp(command, "QUIT") == 0)
	{
	  alive = false;
	}
      else
	{
	  cout << "please use an actual command" << endl;
	}
    }
  return 0;
}
void del(treenode* &tree, treenode* &head, int input)
{
  if(head == NULL)
    {
      
    }
}
void search(treenode* tree, treenode* head, int input)
{
  //if empty tree
  if(head == NULL)
    {
      cout << "Tree is empty!" << endl;
    }
  // if input is bigger than current int and can still go down right
  else if(tree->getNum() < input && tree->getR() != NULL)
    {
      search(tree->getR(), head, input);
    }
  // if input is less than current int and can still go down left
  else if(tree->getNum() > input && tree->getL() != NULL)
    {
      search(tree->getL(), head, input);
    }
  //if current int and input are equal
  else if(tree->getNum() == input)
    {
      cout << input <<" is in the tree" << endl;
    }
  //else its not in the tree
  else
    {
      cout << "number does not exist in the tree" << endl;
    }
}
void add(treenode* &tree, treenode* &head, int input)
{
  //if empty list make new treenode with input
  treenode* newnode = new treenode(input);
  if(head == NULL)
    {
      cout << "head" << endl;
      head = new treenode(input);
    }
  // if tree num is <= to input go down right if its not null
  else if(tree->getR() != NULL && tree->getNum() <= input)
    {
          cout << "going R" << endl;
          treenode* temp = tree->getR();
          add(temp, head, input);
     
    }
  //if input < tree num go left if its not null
  else if ( tree->getL() != NULL && tree->getNum() > input)
    {
      cout << "going L" << endl;
      treenode* temp = tree->getL();
      add(temp, head, input);
      
    }
  
  else
    {
      //else if right is null and input > current int set input in right leaf
      cout << "IN" << endl;
      if(tree->getR() == NULL && tree->getNum() <= input)
        {
          cout << "R" << endl;
          tree->setR(newnode);
        }

    
      else
	{
	  //if left is null and current int < input set input in left leaf
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

  cout << "\n" << endl;
  for(int i = 10; i < space;i++)
    {
      cout << " ";
    }
  cout << tree->getNum() << endl;
  print(tree->getL(), space);
}
