#include <iostream>
#include "treenode.h"
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

void print(treenode* tree, int space);
void add(treenode* &tree, treenode* &head, int input);
void fixtree(treenode* &node, treenode* &head);
int main()
{
  
  int input;
  treenode* tree = NULL;
  bool alive = true;
  while(alive)
    {
      char command[10];
      cout << "ADD, PRINT, DEL, GEN, SERIES, QUIT" << endl;

      cin >> command;
      if(strcmp(command, "ADD") == 0)
	{
	  
	  cin >> input;
	  add(tree, tree, input);
	}
      /*
      else if(strcmp(command, "SERIES") == 0)
	{
	  cout << "How many numbers you want to gen: " << endl;
	  cin >> input;
	  for (int i = 1; i < input + 1; i ++)
	    {
	      
	      add(tree, tree, tree, i);
	    }
	}
            else if(strcmp(command, "GEN") == 0)
	{
	  int num = 0;
	  cout << "Getting from text..." << endl;
	  ifstream nums("1-1000.txt");
	   for(int i = 0; i < 1000; i++)
	     {
	       //go through textfile and add nums
	       nums >> num;
	       
	       //add and sort
	       add(tree, tree, tree, num);

	       
	     }
	   nums.close();
	   nums.open("1-1000.txt");						  
	}
      */
      else if(strcmp(command, "PRINT") == 0)
	{
	  if(tree != NULL)
	    {
	      print(tree, 0);
	    }
	  else
	    {
	      cout << "tree is empty" << endl;
	    }
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
void fixtree(treenode* &node, treenode* & head)
{
  //if it is a leaf or head

  if(node->getP()->getCol() == 0)
    {
      //if parent is black it is fine
    }
  //grandparent will always not be head
  else if(node->getP()->getCol() == 1)
    {
      if(node->getP()->getP()->getL() == node->getP())
	{
	  //case 1: black uncle
	  if(node->getP()->getP()->getR()->getCol() == 1)
	    {
	      node->getP()->getP()->setCol(1);
	      node->getP()->getP()->getL()->setCol(0);
	      node->getP()->getP()->getR()->setCol(0);
	      
	    }
	}
    }
  head->setCol(0);

  
}
void add(treenode* &tree, treenode* &head, int input)
{
  //if empty list make new treenode with input
  treenode* newnode = new treenode(input);
  if(head == NULL)
    {
      head = new treenode(input);
      head->setCol(0);
    }
  // if tree num is <= to input go down right if its not null
  else if(tree->getR() != NULL && tree->getNum() <= input)
    {
      treenode* temp = tree->getR();
      add(temp, head, input);
     
    }
  //if input < tree num go left if its not null
  else if ( tree->getL() != NULL && tree->getNum() > input)
    {
      treenode* temp = tree->getL();
      add(temp, head, input);
    }
  else
    {
      //else if right is null and input > current int set input in right leaf
      if(tree->getR() == NULL && tree->getNum() <= input)
        {
          tree->setR(newnode);
	  treenode* node = tree->getR();
	  node->setP(tree);
	  fixtree(node, head);
        }

    
      else if(tree->getL() == NULL && tree->getNum() > input)
	{
	  tree->setL(newnode);
	  treenode* node = tree->getL();
	  node->setP(tree);
	  fixtree(node, head);
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
  cout << tree->getNum();
  if(tree->getCol() == 0)
    {
      cout << "B" << endl;
    }
  else
    {
      cout << "R" << endl;
    }
  
  print(tree->getL(), space);
}
