//Project: Zuul
//By: Aidan G
//lasted edited: 12/16/22

#include <vector>
#include <iostream>
#include <cstring>
#include "rooms.h"
using namespace std;
//3  1  2
//4     5
//6     7
//8  9  10
//11    15
//12 13 14
//this is the map
//gold in r15
//gun in r2
//eraser in r1
//lead in r3
//stone in r5
//I make a graph to navigate through the rooms
struct items
{
  char* name;
  int id;
};

int main ()
{

  //creating a bunch of stuff
  vector<rooms*> holder;
  vector<items*> Hitems;
 
  
  items* gold = new items();
  gold->name = new char[5];
  strcpy(gold->name, "gold");
  gold->id = 14;
  Hitems.push_back(gold);
  
  items* gun = new items();
  gun->name = new char[4];
  strcpy(gun->name, "gun");
  gun->id = 1;
  Hitems.push_back(gun);
  
  items* stone = new items();
  stone->name = new char[6];
  strcpy(stone->name, "stone");
  stone->id = 4;
  Hitems.push_back(stone);
  
  items* eraser = new items();
  eraser->name = new char[7];
  strcpy(eraser->name, "eraser");
  eraser->id = 0;
  Hitems.push_back(eraser);
  
  items* lead = new items();
  lead->name = new char[5];
  strcpy(lead->name, "lead");
  lead->id = 2;
  Hitems.push_back(lead);
  
  //r1
  rooms* r1 = new rooms();
  r1->x = 1;
  r1->y = 0;
  r1->description = new char[37];
  r1->id = 0;
  strcpy(r1->description,"You are in room1 the starting place:");
  holder.push_back(r1);
  
  //r2
  rooms* r2 = new rooms();
  r2->x = 2;
  r2->y = 0;
  r2->id = 1;
  r2->description = new char[19];
  strcpy(r2->description,"You are in: Hall 1");
  holder.push_back(r2);
  
  //r3
  rooms* r3 = new rooms();
  r3->x = 0;
  r3->y = 0;
  r3->id = 2;
  r3->description = new char[19];
  strcpy(r3->description,"You are in: Hall 2");
  holder.push_back(r3);

  //r4
  rooms* r4 = new rooms();
  r4->x = 0;
  r4->y = 1;
  r4->id = 3;
  r4->description = new char[48];
  strcpy(r4->description,"You are in spanish 2, the stuff of nightmares: ");
  holder.push_back(r4);

  //r5
  rooms* r5 = new rooms();
  r5->x = 2;
  r5->y = 1;
  r5->id = 4;
  r5->description = new char[69];
  strcpy(r5->description,"You are in the computer lab but half the people here aren't working:");
  holder.push_back(r5);
  
  //r6
  rooms* r6 = new rooms();
  r6->x = 0;
  r6->y = 2;
  r6->id = 5;
  r6->description = new char[34];
  strcpy(r6->description,"You are in the libary so shut up:");
  holder.push_back(r6);
  
  //r7
  rooms* r7 = new rooms();
  r7->x = 2;
  r7->y = 2;
  r7->id = 6;
  r7->description = new char[23];
  strcpy(r7->description,"You are in math class:");
  holder.push_back(r7);
  
  //r8
  rooms* r8 = new rooms();
  r8->x = 0;
  r8->y = 3;
  r8->id = 7;
  r8->description = new char[35];
  strcpy(r8->description,"You are in history class have fun!");
  holder.push_back(r8);

  //r9
  rooms* r9 = new rooms();
  r9->x = 1;
  r9->y = 3;
  r9->id = 8;
  r9->description = new char[50];
  strcpy(r9->description,"You are in the cafateria the best place to be in:");
  holder.push_back(r9);
  
  //r10
  rooms* r10 = new rooms();
  r10->x = 2;
  r10->y = 3;
  r10->id = 9;
  r10->description = new char[46];
  strcpy(r10->description,"You are in science class time to learn stuff:");
  holder.push_back(r10);
  
  //r11
  rooms* r11 = new rooms();
  r11->x = 0;
  r11->y = 4;
  r11->id = 10;
  r11->description = new char[37];
  strcpy(r11->description,"You are in: Hall 3 because i said so");
  holder.push_back(r11);

  //r12
  rooms* r12 = new rooms();
  r12->x = 0;
  r12->y = 5;
  r12->id = 11;
  r12->description = new char[27];
  strcpy(r12->description,"You are not in math class:");
  holder.push_back(r12);
  
  //r13
  rooms* r13 = new rooms();
  r13->x = 1;
  r13->y = 5;
  r13->id = 12;
  r13->description = new char[27];
  strcpy(r13->description,"You are in the auditorium:");
  holder.push_back(r13);
  
  //r14
  rooms* r14 = new rooms();
  r14->x = 2;
  r14->y = 5;
  r14->id = 13;
  r14->description = new char[14];
  strcpy(r14->description,"You are in: E");
  holder.push_back(r14);
  
  //r15
  rooms* r15 = new rooms();
  r15->x = 2;
  r15->y = 4;
  r15->id = 14;
  r15->description = new char[29];
  strcpy(r15->description,"You are in help I need names");
  holder.push_back(r15);
  
  bool alive = true;
  int Croom = 0;
  int Croom_holder = 0;
  int count = 0;
  bool canmove = true;
  //while alive
  while (alive)
    {
      if(canmove == false)
	{
	  cout << "you ran into a wall, get gud" << endl;
	}
      canmove = false;
      count++;
      //win condition
      if (count == 20)
	{
	  cout << "Instead of you getting bored of this game, the game got bored of you and it left, you win! I guess?" << endl;
	  alive = false;
	}
      
      Croom = Croom_holder;
      cout << holder[Croom]->description << endl;
      //print all items in the room
      cout << "Items in room:" << endl;
      for (int i = 0; i < Hitems.size(); i++)
        {
          if (Hitems[i]->id == holder[Croom]->id)
	    {
	      cout << Hitems[i]->name << endl;
	    }
        }
      /*iterates through the room vector and if the room is next to yours than
       it prints where you can go*/
      for (vector<rooms*> ::iterator it = holder.begin() ; it != holder.end(); it++)
        {

          if((*it)->y == holder[Croom]->y)
	    {
	      if ((*it)->x +1 == holder[Croom]->x)
		{
		  cout << "you can go left;" << endl;
		  
		  
		}
	      if ((*it)->x -1 == holder[Croom]->x)
		{
		  cout << "you can go right;" << endl;
		}
	      
	    }
          if((*it)->x == holder[Croom]->x) 
	    {
	      if ((*it)->y +1 == holder[Croom]->y)
		{
		  cout << "you can go up;" << endl;
		  
		}
	      if ((*it)->y -1 == holder[Croom]->y)
		{
		  cout << "you can go down;" << endl;
		  
		}
	      
	    }
        }
      
      //get input
      char input[10];
      cout << "Enter Q, L, R, U, D, Pickup, Drop, Inv: " << endl;
      cin >> input;
      /*the first 4 inputs are bassically the same so this is our only comment
	but bassically you iterate through the holder vector that has all the rooms
	and then you compare the the coordinates of the current room your in to all
	the others and if it fills the if condition then you can move to another room
	for example in this if statement it first compares the y coordinates of 
	the rooms and if they are the same then you see if the room is on the left
	of your room so you plus the room your currently trying to figure out is on
	your left so you +1 cause graphs, if all the conditions are fufiled then
	your allowed to move to the next room on the left, the next 3 are bassically
	the same but the deal with right up and down
*/
      if (strcmp(input,"L") == 0)
	{
	  for (vector<rooms*> ::iterator it = holder.begin() ; it != holder.end(); it++)
	    {
	      
	      if((*it)->y == holder[Croom]->y)
		{
		  if ((*it)->x +1 == holder[Croom]->x)
		    {
		      Croom_holder = (*it)->id;
		      canmove = true;
		      
		    }
		  
		}
	      
	    }
	  
	}
      //if input is R then move right
      else if (strcmp(input,"R") == 0)
	{
	  for (vector<rooms*> ::iterator it = holder.begin() ; it!= holder.end(); it++)
	    {
	      if((*it)->y == holder[Croom]->y)
		{
		  if ((*it)->x -1 == holder[Croom]->x)
		    {
		      Croom_holder = (*it)->id;
		      canmove = true;
		  
		    }
		  
		}
	    }                  
	  
	}
      
      //if input is D then move down
      else if (strcmp(input,"D") == 0)
	{
	  for (vector<rooms*> ::iterator it = holder.begin() ; it!= holder.end(); it++)
	    {
	      if((*it)->x == holder[Croom]->x)
		{
		  if ((*it)->y -1 == holder[Croom]->y)
		    {
		      Croom_holder = (*it)->id;
		      canmove = true;
		    }
		  
                }
	      
            }
	  
	}
        
      //if input is U then move down
      else if (strcmp(input,"U") == 0)
	{
	  for (vector<rooms*> ::iterator it = holder.begin() ; it!= holder.end(); it++)
	    {
	      if((*it)->x == holder[Croom]->x)
		{
		  if ((*it)->y +1 == holder[Croom]->y)
		    {
		      Croom_holder = (*it)->id;
		      canmove = true;
		    }
		}
	    }
	}
      //go through the Hitems vector and check each items id
      // if its 15 ( which is inv id ) then print the item
      else if (strcmp(input, "Inv") == 0)
	{
	  canmove = true;
	  for (int i = 0; i < Hitems.size(); i++)
            {
              if (Hitems[i]->id == 15)
                {
                  cout << Hitems[i]->name << endl;
		  
                }
            }

	}
      //checks all item for your id and if there is your id
      //then it asks for comformation before deleting
      else if (strcmp(input, "Drop") == 0)
	{
	  canmove = true;
	  for (int i = 0; i < Hitems.size(); i++)
            {
              if (Hitems[i]->id == 15)
                {
                  cout << "Type Y if you want to drop: " << Hitems[i]->name << endl;
                  cin >> input;
                  if (strcmp(input, "Y") == 0)
                    {
                      Hitems[i]->id = Croom;
		      
                    }
                }
            }
	}
      //checks the item ids that are = to room you are currently in
      //if there is ask to pick up and do if Y
      else if (strcmp(input, "Pickup") == 0)
	{
	  canmove = true;
	  for (int i = 0; i < Hitems.size(); i++)
	    {
	      if (Hitems[i]->id == holder[Croom]->id)
		{
		  cout << "Type Y if you want to pick up: " << Hitems[i]->name << endl;
		  cin >> input;
		  if (strcmp(input, "Y") == 0)
		    {
		      Hitems[i]->id = 15;
		    }  
		}
	    }
	}
        
      //if input is Q then quit
      else if ( strcmp(input, "Q") == 0)
	{
	  alive = false;
	}
      //if input isnt good
      else
	{
	  cout << "Please enter an actual input!" << endl;
	  canmove = true;
	}
    }
  return 0;
}
