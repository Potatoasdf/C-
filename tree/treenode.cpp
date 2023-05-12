#include <iostream>
#include "treenode.h"

treenode::treenode(int setnum)
{
  num = setnum;
  right = NULL;
  left = NULL;
}
treenode::~treenode()
{
  right = NULL;
  left = NULL;
}
treenode* treenode::getR()
{
  return right;
}
void treenode::setR(treenode* newR)
{
  right = newR;
}
treenode* treenode::getL()
{
  return left;
}
void treenode::setL(treenode* newL)
{
  left = newL;
}
int treenode::getNum()
{
  return num;
}
void treenode:: setNum(int input)
{
  num = input;
}
