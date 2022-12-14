#ifndef ROOMS_H
#define ROOMS_H
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

class rooms
{
public:
  
  rooms();
  vector<char*> itemsheld;
  int right;
  int left;
  int layer;
  char* description;
  
  
};

#endif
