#include <iostream>
#include "treeNode.h"

treenode::treenode(char input)
{
  //constructor
  var = input;
  right = NULL;
  left = NULL;
}
treenode::~treenode()
{

}
treenode* treenode::getR()
{
  //returns right node
  return right;
}
void treenode::setR(treenode* newR)
{
  //give right node new val
  right = newR;
}
treenode* treenode::getL()
{
  //returns left node
  return left;
}
void treenode::setL(treenode* newL)
{
  //give left node new val
  left = newL;
}
char treenode::getVar()
{
  //return var
  return var;
}
