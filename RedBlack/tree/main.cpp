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
void LLRotate(treenode* &parent, treenode* &child, treenode* &head);
void LRRotate(treenode* &parent, treenode* &child, treenode* &head);
void RRRotate(treenode* &parent, treenode* &child, treenode* &head);
void RLRotate(treenode* &parent, treenode* &child, treenode* &head);
void toHead(treenode* &head);

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
	  while (tree->getP() != NULL)
	    {
	      tree = tree->getP();
	    }
	}
      else if(strcmp(command, "SERIES") == 0)
	{
	  cout << "How many numbers you want to gen: " << endl;
	  cin >> input;
	  for (int i = 1; i < input + 1; i ++)
	    {
	      
	      add(tree, tree, i);
	      while (tree->getP() != NULL)
		{
		  tree = tree->getP();
		}
	      print(tree, 0);
	      cout << "ITS A BARRIER" << endl;
	      cout << "ITS A BARRIER" << endl;
	       
	    }
	}
	/*
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

void fixtree(treenode* &node, treenode* &head)
{
  if(node == head)
    {
      cout <<"HERE" << endl;
      node->setCol(0);
    }
  //case 1: black parent
  else if(node->getP()->getCol() == 0)
    {
      cout << "GOOD" << endl;
      //if parent is black it is fine
    }
    //red parent
  else if(node->getP()->getCol() == 1)
    {//if parent is left uncle is right
      cout << "R" << endl;
      if(node->getP()->getP()->getL() == node->getP())
	{
	  if(node->getP()->getP()->getR()->getCol() == 1)
	    {
	      //case 2: Red Uncle
              //grand parent becomes red and parent and uncle becomes black then call gparent recursivley
              node->getP()->getP()->setCol(1);
              node->getP()->getP()->getL()->setCol(0);
              node->getP()->getP()->getR()->setCol(0);
              treenode* GrandParent = node->getP()->getP();
              fixtree(GrandParent, head);
	      cout << "HOW" << endl;
	    }
          //case 3: black uncle	
	  else if(node->getP()->getP()->getR() == NULL || node->getP()->getP()->getR()->getCol() == 0)
	    {
	      treenode* parent = node->getP();
	      //parent left node right
	      if(node->getP()->getR() == node)
		{
		  LLRotate(parent, node, head);
		  fixtree(parent, head);
		}
	      //parent left node left
	      else
		{
		  LRRotate(parent, node, head); 
		}
	    }
	}
      //parent right uncle left
      else
	{
	  if (node->getP()->getP()->getL()->getCol() == 1)
            {
              //case 2: Red Uncle
              //grand parent becomes red and parent and uncle becomes black then call gparent recursivley
              node->getP()->getP()->setCol(1);
              node->getP()->getP()->getL()->setCol(0);
              node->getP()->getP()->getR()->setCol(0);
              treenode* GrandParent = node->getP()->getP();
              fixtree(GrandParent, head);
	      
	    }
	  //case 3: black uncle
	  cout << "RL" << endl;
	  if(node->getP()->getP()->getL() == NULL || node->getP()->getP()->getL()->getCol() == 0)
	    {
	      treenode* parent = node->getP();
	      //parent right node left
	      if(node->getP()->getL() == node)
		{
		  cout << "RL" << endl;
		  RRRotate(parent, node, head);
		  fixtree(parent, head);
		}
	      //parent right node right
	      else
		{
		  cout << "RR" << endl;
		  RLRotate(parent, node, head);
		}
	    }
	}
      treenode* parent = node->getP();
      toHead(head);
      fixtree(parent, head);
    }
  else
    {
      head->setCol(0);
    }
  
  
}

void toHead(treenode* &head)
{
  while(head->getP() != NULL)
    {
      head = head->getP();
    }
}
void LLRotate(treenode* &parent, treenode* &child, treenode* &head)
{
  /*
    result:
    
     GP     
    /						\
   P
    \
     C

        GP
       /  
      C    
     /
    P
   */
      // GP is right child of P P is child of GGP and GP gets P former R child
  parent->setR(child->getL());
  child->setP(parent->getP());
  child->getP()->setL(child);
  parent->setP(child);
  child->setL(parent);
  
}
void LRRotate(treenode* &parent, treenode* &child, treenode* &head)
{
    /*				\
      GP
     /						\
    P
   /
  C
     P    
    / \
   C   GP   
   */
  parent->getP()->setCol(1);
  parent->setCol(0);
  treenode* holder = parent->getR();
  if(parent->getP()->getP() != NULL)
    {
      // GP is right child of P P is child of GGP and GP gets P former R child
      parent->setR(parent->getP());
      parent->setP(parent->getP()->getP());
      parent->getP()->setL(parent);
      
      parent->getR()->setP(parent);
      parent->getR()->setL(holder);
    }
  //head condition
  else
    {
      /*
	bassically makes P the head and GP the R child of P
       */
      parent->setR(parent->getP());
      parent->setP(NULL);
      parent->getR()->setP(parent);
      parent->getR()->setL(holder);
      head = parent;
    }
  
}
void RRRotate(treenode* &parent, treenode* &child, treenode* &head)
{
    /*
    result:

     GP
       \                                          \
        P
       /
      C

      GP
        \
         C
          \
           P
   */
      // GP is right child of P P is child of GGP and GP gets P former R child
  parent->setL(child->getR());
  child->setP(parent->getP());
  child->getP()->setR(child);
  parent->setP(child);
  child->setR(parent);


}

void RLRotate(treenode* &parent, treenode* &child, treenode* &head)
{
  /*
        RResult:
    GP
      \
       P
        \
         C
      P
     / \
    GP  C


   */
  parent->getP()->setCol(1);
  parent->setCol(0);
  treenode* holder = parent->getL();
  if(parent->getP()->getP() != NULL)
    {
      // GP is right child of P P is child of GGP and GP gets P former R child
      parent->setL(parent->getP());
      parent->setP(parent->getP()->getP());
      parent->getP()->setR(parent);

      parent->getL()->setP(parent);
      parent->getL()->setR(holder);
    }
  //head condition
  else
    {
      /*
        bassically makes P the head and GP the R child of P
       */
      parent->setL(parent->getP());
      parent->setP(NULL);
      parent->getL()->setP(parent);
      parent->getL()->setR(holder);
      head = parent;
    }

}

void add(treenode* &tree, treenode* &head, int input)
{
  //if empty list make new treenode with input
  treenode* newnode = new treenode(input);
  if(head == NULL)
    {
      head = new treenode(input);
      head->setP(NULL);
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
  else if(tree->getCol() == 1)
    {
      cout << "R" << endl;
    }
  
  print(tree->getL(), space);
}
