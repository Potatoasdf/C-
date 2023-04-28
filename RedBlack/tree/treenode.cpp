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
treenode* treenode:: getP()
{
  return parent;
}
void treenode::setP(treenode* newP)
{
  parent = newP;
}

int treenode::getNum()
{
  return num;
}
void treenode:: setNum(int input)
{
  num = input;
}
void treenode:: setCol(int newcolor)
{
  color = newcolor;
}
int treenode:: getCol()
{
  return color;
}
