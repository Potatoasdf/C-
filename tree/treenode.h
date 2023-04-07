#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>

using namespace std;

class treenode
{
 public:
  treenode(int setnum);
  ~treenode();
  treenode* getR();
  void setR(treenode* newR);
  treenode* getL();
  void setL(treenode* newL);
  int getNum();
 private:
  int num;
  treenode* right;
  treenode* left;
};

#endif
