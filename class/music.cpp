#include <vector>
#include <iostream>
#include <cstring>
#include "music.h"
using namespace std;

music::music (){
  strcpy(identifier , "mu");
  getYear(year);
  getTitle(title);
  getDuration(duration);  
  getPublisher(publisher);
  getArtist(artist);
}
char* music::returnArtist()
{
  return artist;
}
