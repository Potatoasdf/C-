#include <vector>
#include <iostream>
#include <cstring>
#include "movie.h"
using namespace std;
//bassically just gets inputs, every child is bassically the same
movie::movie (){
  strcpy(identifier , "mo");
  getYear(year);
  getTitle(title);
  getDuration(duration);
  getPublisher(publisher);
  getDirector(director);
}
char* movie::returnDirector()
{
  return director;
}
