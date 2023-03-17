#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void InfixPostfix(char* input, int i, Node* &queue, Node* &stack);
void enqueue(char num, Node* &root);
void push(char exp, Node* &head);



int main()
{
  Node* queue = NULL;
  Node* stack = NULL;
  char* input = new char[80];
  cin.getline(input, 80);
  cout << strlen(input) << endl;
  InfixPostfix(input, 0, queue, stack);

  return 0;
  
}

void InfixPostfix(char* input, int i, Node* &queue, Node* &stack)
{
  if(isdigit(input[i]))
    {
      enqueue(input[i], queue);
    }
  else if(input[i] != ' ')
    {
      push(input[i], stack);
    }
  if(strlen(input) >= i)
    {
      InfixPostfix(input, i += 1, queue, stack);
    }
}

void enqueue(char num, Node* &root)
{
  Node* newNode = new Node(num);
  //if empty queue
  if (root == NULL)
    {
      root = newNode;
    }
  else
    {
      Node* currentNode = root;
      //else go to the root and add the num
      while (currentNode->getNext() != NULL)
	{
	  currentNode = currentNode->getNext();
	}
      currentNode->setNext(newNode);
      root = newNode;
    }
  cout << root->getVal() << endl;
}

void push(char exp, Node* &head)
{
  //if stack is empty
  Node* newnode = new Node(exp);
  if(head == NULL)
    {
      head = newnode;
    }
  //else add stack to newnodes next
  else
    {
      Node* holder = head;
      newnode->setNext(holder);
      head = newnode;
    }
  cout << head->getVal() << endl;;
}
