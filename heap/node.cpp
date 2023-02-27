#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(int newNum) {
  num = newNum;
  right = NULL;
  left = NULL;
}

Node::~Node() {
  delete num;
  right = NULL;
  left = NULL;
}

int Node::getNum() {
  return num;
}

void Node::setLeft(Node* newLeft) {
  left = newLeft;
}

void Node::setRight(Node* newRight) {
  right = newRight;
}
Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}
