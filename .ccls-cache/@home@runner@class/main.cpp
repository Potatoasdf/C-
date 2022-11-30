#include <vector>
#include <iostream>
#include <cstring>
#include "videogame.h"
#include "movie.h"
#include "music.h"
using namespace std;

void identify(vector<parent*> &storage, int number);

int main() 
{
  bool alive = true;
  vector<parent*> storage;

  //while alive
  while (alive)
    {
      //get input
      char input[10];
      cout << "Enter ADD, SEARCH, DELETE, or QUIT: " << endl;
      cin >> input;
      //if input is QUIT then stop program
      if( strcmp(input, "QUIT") == 0)
      {
        alive = false;
      }
      else if(strcmp(input, "ADD") == 0)
      {
        //make options than go to parent where
        //there will be 3 options music, movie and vg
        cout << "Enter MOVIE, MUSIC, or VIDEOGAME: " << endl;
        cin >> input;
        
        if (strcmp(input, "MOVIE") == 0)
        {
          movie* holder = new movie();
          storage.push_back(holder);
          }
          
        else if (strcmp(input, "MUSIC") == 0)
        {
          music* holder = new music();
          storage.push_back(holder);
        }
        
        else if (strcmp(input, "VIDEOGAME") == 0)
        {
          videogame* holder = new videogame();
          storage.push_back(holder);
        }
          
        else {
          cout << "Please enter an actual input!" << endl;
        }
      }
        //bassically just copied from my studenstlist delete function
      else if( strcmp(input, "SEARCH") == 0)
      {
        if (storage.size() != 0) 
        {
          //get input
          int checkYear;
          cout << "Year: " << endl;
          cin >> checkYear;
          //go through all the structs and find their yearss to compare with input
          for (int i = 0; i < storage.size(); i ++)
            {
              // print if possible
              if (checkYear == storage[i]->year)
              {
                int number = i;
                identify(storage, number);
              }
            }
        }
        else
        {
           cout << "Please give an actual input!" << endl;
        }
      }
      else if( strcmp(input, "DELETE") == 0)
      {
        if (storage.size() != 0) 
        {
          //get input
          int checkYear;
          cout << "Year: " << endl;
          cin >> checkYear;
          //go through all the structs and find their yearss to compare with input
          for (int i = 0; i < storage.size(); i ++)
            {
              // print if possible
              if (checkYear == storage[i]->year)
              {
                int number = i;
                identify(storage, number);
              }
              
            }
          cout << "Type YES if you want to delete these: " << endl;
          cin >> input;
          if (strcmp(input, "YES") == 0)
          {
            for (int i = 0; i < storage.size(); i ++)
              {
                if (checkYear == storage[i]->year)
                {
                  delete storage[i];

                }
                
              }
            
          }
        }
        else
        {
           cout << "Please give an actual input!" << endl;
        }      }
      //if input isnt good
      else
      {
        cout << "Please enter an actual input!" << endl;
      }
    }
  return 0;
}
void identify(vector<parent*> &storage, int number)
{
  cout << storage[number] -> year << endl;
  cout << storage[number] -> identifier << endl;
  if(strcmp(storage[number] -> identifier, "vg") == 0)
  {
    cout << storage[number] -> year << endl;
    cout << storage[number] -> title << endl;
    cout << storage[number] -> rating << endl;
    cout << storage[number] -> publisher << endl;
    
  }
  else if(strcmp(storage[number] -> identifier, "mu") == 0)
  {
    cout << storage[number] -> year << endl;
    cout << storage[number] -> title << endl;
    cout << storage[number] -> duration << endl;
    cout << storage[number] -> publisher << endl;
    cout << ((music*)storage[number]) -> returnArtist() << endl;
    
  }
  else if(strcmp(storage[number] -> identifier, "mo") == 0)
  {
    cout << storage[number] -> year << endl;
    cout << storage[number] -> title << endl;
    cout << storage[number] -> duration << endl;
    cout << storage[number] -> publisher << endl;
    cout << ((movie*)storage[number]) -> returnDirector() << endl;
    
  }
  else
  {
    cout << "If you got here you did something wrong" << endl;
  }
}
