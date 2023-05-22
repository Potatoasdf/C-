/*
  Red-Black Tree
  By: Aidan Gao
  Last Worked On: 5/8/2023
 */
#include <iostream>
#include "treenode.h"
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

void print(treenode* tree, int space);
void add(treenode* &tree, treenode* &head, int input);
void search(treenode* tree, treenode* head, int input);
void delsearch(treenode* &tree, treenode* &prev, int input, treenode* &head);
void del(treenode* &tree, int input, treenode*& head);
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
      cout << "ADD, PRINT, DEL, GEN, SERIES, SEARCH, QUIT" << endl;
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
      else if(strcmp(command, "DEL") == 0)
	{
	  if (tree != NULL)
	    {
	      cin >> input;
	      delsearch(tree, tree , input, tree);
	    }
	  else
	    {
	      cout << "EMPTY TREE" << endl;
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
	    }
	}
      else if(strcmp(command, "SEARCH") == 0)
	{
	  cin >> input;
	  search(tree, tree, input);
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
	       add(tree, tree, num);
	       while (tree->getP() != NULL)
		 {
		   tree = tree->getP();
		 }
	     }
	   nums.close();
	   nums.open("1-1000.txt");						  
	}
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

void del(treenode* &tree, int input, treenode* &head)
{//prob doesnt work
  treenode* parent = tree->getP();
  //head condition
  if(tree->getR() == NULL & tree->getL() == NULL)
    {//just head
      if(head == tree)
	{
	  delete head;
	  head = NULL;
	}
      delete tree;
    }
  else if(tree->getR() == NULL && tree->getL() != NULL)
    {//left child
      treenode* temp = tree->getL();
      if(tree->getP()->getL() == parent)
	{
	  tree->getP()->setL(temp);
	}
      else
	{
	  tree->getP()->setR(temp);
	}
      temp->setP(parent);
      delete tree;
      tree = temp;
      
    }
  else if(tree->getR() != NULL && tree->getL() == NULL)
    {//right child
      treenode* temp = tree->getR();
      if(tree->getP()->getL() == parent)
        {
          tree->getP()->setL(temp);
        }
      else
        {
          tree->getP()->setR(temp);
        }

      temp->setP(parent);
      delete tree;
      tree = temp;
    }
  else
    {//both
      
      cout << tree->getNum() << endl;
      bool check = false;
      //go right then left till you cant
      treenode* temp = tree->getR();
      cout << temp->getP()->getR()->getR() << endl;
      while(temp->getL() != NULL)
	{
	  temp = temp->getL();
	  check = true;
	}
      //get value
      tree->setNum(temp->getNum());
      //detach temp 
      if(check)
	{
	  temp->getP()->setL(NULL);
	}
      else
	{
	  
	  temp->getP()->setR(temp->getR());
	}
      print(head, 0);
      delete temp;
      temp = NULL;
    }
}

void delsearch(treenode* &tree, treenode* &prev, int input, treenode* &head)
{
    // if input is bigger than current int and can still go down right
  if(tree->getR() != NULL && tree->getNum() < input)
    {
      treenode* rightnode = tree->getR();
      delsearch(rightnode, tree, input, head);
    }
  // if input is less than current int and can still go down left
  else if(tree->getL() != NULL && tree->getNum() > input)
    {
      treenode* leftnode = tree->getL();
      delsearch(leftnode, tree, input, head);
    }
  //if current int and input are equal
  else if(tree->getNum() == input)
    {
      del(tree, input , head);
    }
  //else its not in the tree
  else
    {
      cout << "number does not exist in the tree" << endl;
    }
}

void fixtree(treenode* &node, treenode* &head)
{
  if(node == head)
    {//if node is head than just set to black
      node->setCol(0);
    }
  //case 1: black parent
  else if(node->getP()->getCol() == 0 || node->getCol() == 0)
    {//If black parent than everything is fine
      return;
    }
  //red parent
  else if(node->getP()->getCol() == 1)
    {
      //if parent is left uncle is right
      if(node->getP()->getP()->getL() == node->getP())
	{
	  if(node->getP()->getP()->getR() != NULL && node->getP()->getP()->getR()->getCol() != 0)
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
	  else
	    {
	      treenode* parent = node->getP();
	      //parent left node right
	      if(node->getP()->getR() == node)
		{
		  cout << "LL" << endl;
		  LLRotate(parent, node, head);
		  fixtree(parent, head);
		}
	      //parent left node left
	      else
		{
		  cout << "LR" << endl;
		  LRRotate(parent, node, head); 
		}
	    }
	}
      //parent right uncle left
      else if(node->getP()->getP()->getR() == node->getP())
	{
	  if (node->getP()->getP()->getL() != NULL && node->getP()->getP()->getL()->getCol() != 0)
            {//case 2: Red Uncle, grand parent becomes red and parent and uncle becomes black then call gparent recursivley
	      node->getP()->getP()->setCol(1);
              node->getP()->getP()->getL()->setCol(0);
              node->getP()->getP()->getR()->setCol(0);
              treenode* GrandParent = node->getP()->getP();
              fixtree(GrandParent, head);
	    }
	  //case 3: black uncle
	  else
	    {
	      treenode* parent = node->getP();
	      //parent right node left
	      if(node->getP()->getL() == node)
		{//rotate to the R and call fix tree recursivley with parent it will then probably do a RLRotation
		  cout << "RR" << endl;
		  RRRotate(parent, node, head);
		  fixtree(parent, head);
		}
	      //parent right node right
	      else
		{
		  cout << "RL" << endl;
		  RLRotate(parent, node, head);
		}
	    }
	}
      if(node->getP() != NULL)
	{//recursive for parent
	  treenode* parent = node->getP();
	  fixtree(parent, head);
	}
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
    /
   x
        GP
       /  
      C    
     /
    P
     \
      x
   */
  parent->setR(child->getL());
  child->setP(parent->getP());
  child->getP()->setL(child);
  parent->setP(child);
  child->setL(parent);
  
}
void LRRotate(treenode* &parent, treenode* &child, treenode* &head)
{
  /*						\
      GP
     /						\
    P
   / \
  C   x
     P    
    / \
   C   GP
      /
     x 
   */
  parent->getP()->setCol(1);
  parent->setCol(0);
  treenode* holder = parent->getR();
  if(parent->getP()->getP() != NULL)
    {
      if(parent->getP()->getP()->getR() == parent->getP())
	{
          //  GGP
          // /   \
          //     GP
          parent->setR(parent->getP());
          parent->setP(parent->getP()->getP());
          parent->getP()->setR(parent);

          parent->getR()->setP(parent);
          parent->getR()->setL(holder);
        }
      else
        {
          //   GGP
          //  /   \
          // GP
          parent->setR(parent->getP());
          parent->setP(parent->getP()->getP());
          parent->getP()->setL(parent);

          parent->getR()->setP(parent);
          parent->getR()->setL(holder);
	  
        }
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
      if(holder != NULL)
        {
          holder->setP(parent->getR());
        }
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
       \
        x
      GP
        \
         C
          \
           P
	  /
	 x
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
      / \
     x   C
      P
     / \
    GP  C
     \
      x
   */
  parent->getP()->setCol(1);
  parent->setCol(0);
  treenode* holder = parent->getL();
  if(parent->getP()->getP() != NULL)
    {
      if(parent->getP()->getP()->getR() == parent->getP())
	{
	  cout << "E" << endl;
	  //  GGP
	  // /   \
	  //     GP 
	  parent->setL(parent->getP());
	  parent->setP(parent->getP()->getP());
	  parent->getP()->setR(parent);
	  
	  parent->getL()->setP(parent);
	  parent->getL()->setR(holder);
	  
	}
      else
	{
	  //   GGP
	  //  /   \
	  // GP
	  parent->setL(parent->getP());
          parent->setP(parent->getP()->getP());
          parent->getP()->setL(parent);

          parent->getL()->setP(parent);
          parent->getL()->setR(holder);
	}
    }
  //head condition
  else
    {
      cout << "H" << endl;
      /*
        bassically makes P the head and GP the L child of P
       */
      parent->setL(parent->getP());
      parent->setP(NULL);
      parent->getL()->setP(parent);
      parent->getL()->setR(holder);
      if(holder != NULL)
	{
	  holder->setP(parent->getL());
	}
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
      treenode* temp = tree;
      //else if right is null and input > current int set input in right leaf
      if(tree->getR() == NULL && tree->getNum() <= input)
        {
          tree->setR(newnode);
	  newnode->setP(tree);
	  fixtree(newnode, head);
        }

    
      else if(tree->getL() == NULL && tree->getNum() > input)
	{
	  tree->setL(newnode);
	  newnode->setP(tree);
	  fixtree(newnode, head);
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
      cout << "BP" << tree->getP() << endl;
    }
  else if(tree->getCol() == 1)
    {
      cout << "RP" << tree->getP() <<endl;
    }
  
  print(tree->getL(), space);
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
