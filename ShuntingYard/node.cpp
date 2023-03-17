#include "node.h"
#include <iostream>

using namespace std;

Node::Node(char newVal)
{
  val = newVal;
  next = NULL;
}
Node::~Node()
{
}
Node* Node::getNext()
{
  return next;
}
void Node::setNext(Node* newnext)
{
  next = newnext;
}
char Node::getVal()
{
  return val;
}
