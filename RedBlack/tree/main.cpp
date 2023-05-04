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
void LRotate(treenode* &parent, treenode* &child, treenode* &head);
void RRotate(treenode* &parent, treenode* &child, treenode* &head);
void LRRotate(treenode* &node);
void RLRotate(treenode* &anode);
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
	      cout << tree->getNum();
	      tree = tree->getP();
	    }
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
void fixtree(treenode* &node, treenode* &head)
{
  if(node == head)
    {
      node->setCol(0);
    }
  else{
    //case 1: black parent
    if(node->getP()->getCol() == 0)
      {
	//if parent is black it is fine
      }
    //red parent
    else if(node->getP()->getCol() == 1)
      {
	//if parent is left uncle is right
	if(node->getP()->getP()->getL() == node->getP())
	  {
	    //case 2: red uncle
	    if(node->getP()->getP()->getR() != NULL)
	      {
		if(node->getP()->getP()->getR()->getCol() == 1)
		  {
		    //grand parent becomes red and parent and uncle becomes black then call gparent recursivley
		    node->getP()->getP()->setCol(1);
		    node->getP()->getP()->getL()->setCol(0);
		    node->getP()->getP()->getR()->setCol(0);
		    treenode* GrandParent = node->getP()->getP();
		    fixtree(GrandParent, head);
		    
		  }
	      }
	    //case 3: black uncle
	    else //if(node->getP()->getP()->getR()->getCol() == 0)
	      {
		cout << "YE" << endl;
		treenode* parent = node->getP();
		//parent left node right
		if(node->getP()->getR() == node)
		  {
		    cout << "LR" << endl;
		    LRotate(parent, node, head);
		    parent = node->getP();
		  
		    
		    print(head, 0);
		    node = node->getP();
		    node->setCol(node->getP()->getCol());
		    node->getP()->setCol(1);
		    RRotate(parent, node, head);
		    
		  }
		//parent left node left
		else
		  {
		    
		    cout << "LL" << endl;
		    node->setCol(node->getP()->getCol());
                    node->getP()->setCol(1);
		    cout << "E" << endl;
		    print(head, 0);
		    cout << parent->getNum() << endl;
                    RRotate(parent, node, head);
		    head = parent;
		    print(head, 0);
		    head->getR()->setCol(1);
		    
		    
		  }
		
		
	      }
	  }
	//parent right uncle left
	else
	  {
	  }
      }
  }
  head->setCol(0);
}
void LRotate(treenode* &parent, treenode* &child, treenode* &head)
{
  /*
    result:
    
       GP
      /  \
     U    P
    /    / \
        x   C
	   / \
	  y   z
       GP
      /  \
     U    C
         / \
	P   z
       / \
      x	  y
	    
   */
  parent->setR(child->getL());
  child->setL(parent);
  child->setP(parent->getP());
  parent->setP(child);

}
void RRotate(treenode* &parent, treenode* &child, treenode* &head)
{
    /*
    result:
        GGP
       /					\
      GP
     /						\
    P
   /
  C  
       GGP
      /  
     P    
    / \
   C   GP   
   */
  
  treenode* holder = parent->getR();
  if(parent->getP()->getP() != NULL)
    {
      //left left
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
      
    }
}
void LRRotate(treenode* &node);
void RLRotate(treenode* &anode);

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
  else
    {
      cout << "R" << endl;
    }
  
  print(tree->getL(), space);
}
