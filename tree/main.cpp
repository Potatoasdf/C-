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
void del(treenode* &tree, treenode* &prev, int input, treenode* &head);

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
      else if(strcmp(command, "SERIES") == 0)
	{
	  cout << "How many numbers you want to gen: " << endl;
	  cin >> input;
	  for (int i = 1; i < input + 1; i ++)
	    {
	      add(tree, tree, i);
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
	       add(tree, tree, num);

	       
	     }
	   nums.close();
	   nums.open("1-1000.txt");

	
							  
	}
      else if(strcmp(command, "DEL") == 0)
	{
	  if(tree != NULL)
	    {
	      cin >> input;
	      delsearch(tree, tree, input, tree);
	    }
	  else
	    {
	      cout << "tree is empty" << endl;
	    }
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
      else if(strcmp(command, "SEARCH") == 0)
	{
	  if(tree != NULL)
	    {
	      cin >> input;
	      search(tree, tree, input);
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
      del(tree, prev, input, head);
    }
  //else its not in the tree
  else
    {
      cout << "number does not exist in the tree" << endl;
    }
}
void del(treenode* &tree, treenode* &prev, int input, treenode* &head)
{
  treenode* temp = tree;
  if(head->getNum() == tree->getNum() && head->getR() == NULL && head->getL() == NULL)
    {
      head = NULL;
    }
  //tree is left node of previous node
  else if(prev->getL() == tree)
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
	  //go right then go left till you cant
	  treenode* temp = tree->getR();

	  treenode* prevtemp = NULL;
	  while(temp->getL() != NULL)
	    {
	      prevtemp = temp;
	      temp = temp->getL();
	    }
	  //replace tree num with temp num
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
  //if the prev nodes right chidl is tree do what was done before but with right
  else if(prev->getR() == tree)
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
         //go right then go left till you cant
          treenode* temp = tree->getR();
  
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
  //for head
  else
    {
      if(head->getL() == NULL && head->getR() == NULL)
        {
          delete head;
        }
      //if tree has left node only set prev left node to tree left node and then delete tree
      else if(head->getL() != NULL && head->getR() == NULL)
        {
          treenode* temp = head->getL();
          delete head;
          head = temp;
        }
      //right child only
      else if(head->getR() != NULL && head->getL() == NULL)
        {
          treenode* temp = head->getR();
          delete head;
          head = temp;

        }
      else
        {
          //go right then go left till you cant
          treenode* temp = head->getR();
          //temp == 95 prev == 100 tree == 90
          treenode* prevtemp = NULL;
          while(temp->getL() != NULL)
            {
              prevtemp = temp;
              temp = temp->getL();
            }

          head->setNum(temp->getNum());
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
      head = new treenode(input);
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
        }

    
      else
	{
	  //if left is null and current int < input set input in left leaf
	  if(tree->getL() == NULL && tree->getNum() > input)
	    {
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
