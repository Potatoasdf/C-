#include <vector>
#include <iostream>
#include <cstring>
#include "videogame.h"
using namespace std;

videogame::videogame ()
{
  strcpy(identifier , "vg");
  getYear(year);
  getTitle(title);
  getRating(rating);
  getPublisher(publisher);
}
videogame::~videogame ()
{
  
}
