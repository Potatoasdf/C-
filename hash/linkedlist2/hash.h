#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

class hash
{
 public:
  Hash(int size);
  ~Hash();
  insertItem(int size);
  deleteItem(int size);
  node* table[size];
  int sizesort;
  
  
};
#endif
