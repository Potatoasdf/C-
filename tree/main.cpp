#include <iostream>
#include "treenode.h"
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

void print(treenode* tree, int space);
void add(treenode* &tree, treenode* &head, int input);
void search(treenode* tree, treenode* head, int input);
void delsearch(treenode* &tree, treenode* &head, int input);
void del(treenode* &tree, treenode* &prev, int input);

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
      else if(strcmp(command, "GEN") == 0)
	{
	  
	  cout << "How many numbers you want to gen: " << endl;
	  cin >> input;
	  for (int i = 0; i < input; i++)
	    {
	      int randint = rand() % 1000;
	      add(tree, tree, randint);
	    }

							  
	}
      else if(strcmp(command, "DEL") == 0)
	{
	  cin >> input;
	  delsearch(tree, tree, input);
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

void delsearch(treenode* &tree, treenode* &head, int input)
{
  if(head == NULL)
    {
      cout << "Tree is empty!" << endl;
    }
    // if input is bigger than current int and can still go down right
  else if(tree->getR() != NULL && tree->getNum() < input)
    {
      cout << "R" << endl;
      treenode* rightnode = tree->getR();
      delsearch(rightnode, tree, input);
    }
  // if input is less than current int and can still go down left
  else if(tree->getL() != NULL && tree->getNum() > input)
    {
      cout << "L" << endl;
      treenode* leftnode = tree->getL();
      delsearch(leftnode, tree, input);
    }
  //if current int and input are equal
  else if(tree->getNum() == input)
    {
      del(tree, head, input);
    }
  //else its not in the tree
  else
    {
      cout << "number does not exist in the tree" << endl;
    }
}
void del(treenode* &tree, treenode* &prev, int input)
{
  treenode* temp = tree;
  //tree is left node of previous node
  if(prev->getL() == tree)
    {
      //no children of tree then set prev left node to null and delete tree
      if(tree->getL() == NULL && tree->getR() == NULL)
	{
	  prev->setL(NULL);
	  delete tree;
	}
      //if tree has left node only set prev left node to tree left node and then delete tree
      else if(tree->getL() != NULL && tree->getR() == NULL)
	{
	  prev->setL(tree->getL());
	  delete tree;
	}
      //right child only
      else if(tree->getR() != NULL && tree->getL() == NULL) 
	{
	  prev->setL(tree->getR());
	  delete tree;
	}
      // both children
      else
	{
	  cout << tree->getL()->getNum() << endl;
	  cout << "L both" << endl;
	  //go right then go left till you cant
	  treenode* temp = tree->getR();
	  //temp == 95 prev == 100 tree == 90
	  treenode* prevtemp = NULL;
	  while(temp->getL() != NULL)
	    {
	      prevtemp = temp;
	      temp = temp->getL();
	    }
	  
	  tree->setNum(temp->getNum());
	  if(prevtemp != NULL)
	    {
	      prevtemp->setL(NULL);
	    }
	  else
	    {
	      tree->setR(NULL);
	    }
	  delete temp;
	  
	}
      
      
    }
  
  if(prev->getR() == tree)
    {
      //no children of tree then set prev left node to null and delete tree
      if(tree->getL() == NULL && tree->getR() == NULL)
        {
          prev->setR(NULL);
          delete tree;
        }
      //if tree has left node only set prev left node to tree left node and then delete tree
      else if(tree->getL() != NULL && tree->getR() == NULL)
        {
          prev->setR(tree->getL());
          delete tree;
        }
      //right child only
      else if(tree->getR() != NULL && tree->getL() == NULL)
        {
          prev->setR(tree->getR());
          delete tree;
        }
      // both children
      else
        {
          cout << tree->getL()->getNum() << endl;
          cout << "L both" << endl;
          //go right then go left till you cant
          treenode* temp = tree->getR();
          //temp == 95 prev == 100 tree == 90
          treenode* prevtemp = NULL;
          while(temp->getL() != NULL)
            {
              prevtemp = temp;
              temp = temp->getL();
            }

          tree->setNum(temp->getNum());
          if(prevtemp != NULL)
            {
              prevtemp->setL(NULL);
            }
          else
            {
              tree->setR(NULL);
            }
          delete temp;
	}
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
