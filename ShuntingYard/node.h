#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class Node {
 public:
  Node(char newVal);
  ~Node();
  Node* getNext();
  void setNext(Node* newNext);
  char getVal();
 private:
  char val;
  Node* next;
};
#endif
