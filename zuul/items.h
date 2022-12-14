#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <cstring>
#include "rooms.h"
using namespace std;

class items
{
 public:
  items();
  char* iron = new char(5);
  char* gold = new char(5);
  char* lapiz = new char(6);
  char* emerald = new char(8);
  char* diamond = new char(8);
};


#endif
