#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

using namespace std;

class Node {
 public:
  Node(int newNum);
  ~Node();
  Node* getRight();
  Node* getLeft();
  int getNum();
  void setRight(Node* newRight);
  void setLeft(Node* newLeft);
 private:
  int num;
  Node* left;
  Node* right;
};
#endif
