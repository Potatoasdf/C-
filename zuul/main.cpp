#include <vector>
#include <iostream>
#include <cstring>
#include "items.h"
using namespace std;
//3  1  2
//4     5
//6     7
//8  9  10
//11    15
//12 13 14
//
//
int main ()
{

  items* inv = new items();
  strcpy(inv->gold, "gold");
  strcpy(inv->lapiz, "lapiz");
  strcpy(inv->emerald, "emerald");
  strcpy(inv->diamond, "diamond");
  strcpy(inv->iron, "iron");
  vector<char*> inv1;
  inv1.push_back(inv->gold);
  vector<rooms*> holder;
  rooms* r1 = new rooms();
  r1->right = 1;
  r1->layer = 1;
  r1->left = 1;
  r1->description = new char(3);
  r1->itemsheld.push_back(inv->gold);
  strcpy(r1->description,"hi");
  holder.push_back(r1);
  /*rooms* r2 = new rooms();
  r2->right = 1;
  r2->layer = 1;
  r2->left = 1;
  rooms* r3 = new rooms();
  r3->right = 1;
  r3->layer = 0;
  r3->left = 1;
  rooms* r4 = new rooms();
  r4->right = 0;
  r4->layer = 2;
  r4->left = 0;
  rooms* r5 = new rooms();
  r5->right = 0;
  r5->layer = 2;
  r5->left = 0;
  rooms* r6 = new rooms();
  r6->right = 0;
  r6->layer = 3;
  r6->left = 0;
  rooms* r7 = new rooms();
  r7->right = 0;
  r7->layer = 3;
  r7->left = 0;
  rooms* r8 = new rooms();
  r8->right = 1;
  r8->layer = 4;
  r8->left = 0;
  rooms* r9 = new rooms();
  r9->right = 1;
  r9->layer = 4;
  r9->left = 1;
  rooms* r10 = new rooms();
  r10->right = 0;
  r10->layer = 4;
  r10->left = 1;
  rooms* r11 = new rooms();
  r11->right = 0;
  r11->layer = 5;
  r11->left = 0;
  rooms* r12 = new rooms();
  r12->right = 1;
  r12->layer = 6;
  r12->left = 0;
  rooms* r13 = new rooms();
  r13->right = 1;
  r13->layer = 6;
  r13->left = 1;
  rooms* r14 = new rooms();
  r14->right = 0;
  r14->layer = 6;
  r14->left = 1;
  rooms* r15 = new rooms();
  r15->right = 0;
  r15->layer = 5;
  r15->left = 0;
  */
  return 0;
}
