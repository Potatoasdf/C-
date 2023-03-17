#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void InfixPostfix(char* input, int i, Node* &queue, Node* &stack);
void enqueue(char var, Node* &queue);
void push(char exp, Node* &head);
Node* pop(Node* &stack);
char peek(Node* stack);
int order(char exp);

int main()
{
  Node* queue = NULL;
  Node* stack = NULL;
  char* input = new char[80];
  cin.getline(input, 80);
  cout << strlen(input) << endl;
  InfixPostfix(input, 0, queue, stack);
  cout << "QUEUE" << endl;
  while(queue != NULL)
    {
      cout << queue->getVal() << endl;
      queue = queue->getNext();
    }
  cout << "STACK" << endl;
  while(stack != NULL)
    {
      cout << peek(stack) << endl;
      stack = stack->getNext();
    }
  return 0;
  
}

void InfixPostfix(char* input, int i, Node* &queue, Node* &stack)
{
  //if input is a num
  if(isdigit(input[i]))
    {
      cout << "Queue: " << input[i] << endl;
      enqueue(input[i], queue);
    }
  else if(input[i] != ' ')
    {
      cout << "Stack: " << input[i] << endl;
      //if stack isnt null
      if(stack != NULL)
	{
	  cout << "Prev: " << peek(stack) << endl;
	  // if ) than enqueue all the expressions in between ( and )
	  if(input[i] == ')')
	    {
	      cout << "BRACKETS" << endl;
	      
	      while(peek(stack) != '(')
		{
		  enqueue(peek(pop(stack)), queue);
		}
	      pop(stack);
	    }
	  //if the current expression in the stack has a higher order of operation than the input than enqueue it into the queue
	  else if(!isdigit(input[i]) && input[i] != ')' && peek(stack) != '(')
	    {
	      cout << "ORDER" << endl;
	      while((stack->getNext() !=NULL) && order(peek(stack)) > order(input[i]) || order(peek(stack)) == order(input[i]))
		{
		  enqueue(peek(pop(stack)), queue);
		}
	    }
	}
      //push if not a )
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

void enqueue(char var, Node* &queue)
{
  cout << "ENQUEUEING: " << endl;
  Node* newNode = new Node(var);
  //if empty queue
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
  cout << peek(queue) << endl;
}

void push(char exp, Node* &head)
{
  cout << "A" << endl;
  Node* newnode = new Node(exp);
  //add stack to newnodes next
  Node* holder = head;
  newnode->setNext(holder);
  head = newnode;
    
}

Node* pop(Node* &stack)
{
  // seperate moved Node from the stack and return it
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
  if(exp == '+' || exp == '-')
    {
      return 0;
    }
  else if(exp == '*' || exp == '/')
    {
      return 1;
    }
  else if(exp == '^')
    {
      return 2;
    }
  return 10000;
}
