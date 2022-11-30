#include <vector>
#include <iostream>
#include <cstring>
#include "movie.h"
using namespace std;

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