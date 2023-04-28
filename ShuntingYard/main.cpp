/*
  ShuntingYard
  By: Aidan Gao
  Last Edited: 4/18/23
 */

#include <iostream>
#include <cstring>
#include <vector>

#include "node.h"
#include "treenode.h"

using namespace std;

void postorder(treenode* tree);
void preorder(treenode* tree);
void inorder(treenode* tree);

void InfixPostfix(char* input, int i, Node* &queue, Node* &stack);
void PostfixTree(treenode* &tree, Node* &queue);

void enqueue(char var, Node* &queue);
void dequeue(Node* &queue);
void push(char exp, Node* &head);
Node* pop(Node* &stack);
char peek(Node* stack);
int order(char exp);

int main()
{
  Node* queue = NULL;
  Node* stack = NULL;
  char* input = new char[80];
  cout << "Give expression with only numbers, ^, *, /, +, and - (no negation e.g -2) " << endl;
  cin.getline(input, 80);
  InfixPostfix(input, 0, queue, stack);
  treenode* tree = NULL;
  treenode* child = NULL;
  PostfixTree(tree, queue);
  
  bool alive = true;
  char comm[10];
  while (alive)
    {
      cout << " " << endl;
      cout << "type PRE, POST, IN, QUIT" << endl;
      cin >> comm;
      if(strcmp(comm, "PRE") == 0)
	{
	  preorder(tree);
	}
      else if(strcmp(comm, "POST") == 0)
	{
	  postorder(tree);
	}
      else if(strcmp(comm, "IN") == 0)
	{
	  inorder(tree);
	}
      else if(strcmp(comm, "QUIT") == 0)
	{
	  alive = false;
	}
      else
	{
	  cout << "not a possible input" << endl;
	}
    }
  
  return 0;
  
}

void inorder(treenode* tree)
{
  //traverse through tree
  if(tree != NULL){
    //when the parent is an expression put in parentheses and get its children 
    if(!isdigit(tree->getVar()))
      {
	cout << "(";
      }
    inorder(tree->getL());
    cout << tree->getVar();
    inorder(tree->getR());
    //if child dont are all numbers
    if(!isdigit(tree->getVar()))
      {
	cout << ")";
      }
  }

}

//traverse through the treenode and only cout when you cant go down anymore
void postorder(treenode* tree)
{
  if (tree != NULL)
    {
      
      postorder(tree->getL());
      postorder(tree->getR());
      cout << tree->getVar() << " ";

    }
}
//same as post order but you cout before traversing
void preorder(treenode* tree){
  if(tree != NULL){
    cout << tree->getVar() << " ";
    preorder(tree->getL());
    preorder(tree->getR());
  }
  
}


void InfixPostfix(char* input, int i, Node* &queue, Node* &stack)
{
  //if input is a num enqueue it
  if(isdigit(input[i]))
    {
      enqueue(input[i], queue);
    }
  //else if to get rid of spaces
  else if(input[i] != ' ')
    {
      
      // if ) than enqueue all the expressions from the stack between ( and )
      if(input[i] == ')')
	{ 
	  while(peek(stack) != '(')
	    {
	      enqueue(peek(pop(stack)), queue);
	    }
	  pop(stack);
	}
      else
	{
	  //if the current var is a expression and in the stack and >= order of operation than the input than enqueue it into the queue, also if stacsk not empty and input isnt (
	  while(stack != NULL && (order(peek(stack)) > order(input[i]) || order(peek(stack)) == order(input[i])) && input[i] != '(')
	    {
	      enqueue(peek(pop(stack)), queue); 
	    }
	}
      if(input[i] != ')')
	{
	  push(input[i], stack);
	}
    }
  //keep repeating func until goes through all indexes
  if(strlen(input) -1 > i)
    {
      InfixPostfix(input, i += 1, queue, stack);
    }
  //after take everything from the stack and put in queue
  else
    {
      while(stack != NULL)
	{
	  enqueue(peek(pop(stack)), queue);
	}
    }
}

void PostfixTree(treenode* &tree, Node* &queue)
{
  //vector holds stuff
  vector<treenode*> holder;
  while(queue != NULL)
    {
      //if its a digit put in vector
      if(isdigit(queue->getVal()))
	{
	
          holder.push_back(new treenode(queue->getVal()));
	  dequeue(queue);
	}
      else
	{
	  //if expression than put 2 things in the vector into the l and r treenodes
	  treenode*  newtreenode = new treenode(queue->getVal());
	  dequeue(queue);
	  newtreenode->setR(holder.back());
	  holder.pop_back();
	  newtreenode->setL(holder.back());
	  holder.pop_back();
	  holder.push_back(newtreenode);
	}
  }
  //make tree at top
  tree = holder[0];  
      
  
  
}



void dequeue(Node* &queue)
{
  // go to next node in queue and delete former head
  Node* head = queue->getNext();
  queue->setNext(NULL);
  delete queue;
  queue = head;
}

void enqueue(char var, Node* &queue)
{
  Node* newNode = new Node(var);
  //if empty queue make queue newnode
  if (queue == NULL)
    {
      queue = newNode;
    }
  else
    {
      Node* currentNode = queue;
      //else go to the root and add the num
      while (currentNode->getNext() != NULL)
	{
	  currentNode = currentNode->getNext();
	}
      currentNode->setNext(newNode);
    }
}

void push(char exp, Node* &head)
{
  Node* newnode = new Node(exp);
  //add stack to newnodes next Node
  Node* holder = head;
  newnode->setNext(holder);
  head = newnode;
    
}

Node* pop(Node* &stack)
{
  // seperate moved from the stack and return it
  Node* head = stack->getNext();
  Node* moved = stack;
  moved->setNext(NULL);
  stack = head;

  return moved;
}

char peek(Node* stack)
{
  //give char val
  return stack->getVal();
}

int order(char exp)
{
  //order of operations
  if(exp == '+' || exp == '-')
    {
      return 1;
    }
  else if(exp == '*' || exp == '/')
    {
      return 2;
    }
  else if(exp == '^')
    {
      return 3;
    }
  return 0;
}
