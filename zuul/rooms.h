#ifndef ROOMS_H
#define ROOMS_H
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class rooms
{
 public:
  struct items
  {
    char item[80];
    
  };
  rooms();
  int right;
  int left;
  int layer;
  char description[80];
  
  
};

#endif
