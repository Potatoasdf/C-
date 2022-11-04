/* 
Project: Student List
By: Aidan Gao
Last worked on: 11/5/2022
*/
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
struct student
{
  char firstname[80];
  char lastname[80];
  int id;
  float gpa;

};

void add(vector<student*> &holder);
void del(vector<student*> &holder);
void print(vector<student*> &holder);


int main() {
  vector<student*> holder;
  bool alive = true;
  //while alive
  while (alive)
    {
      //get input
      char input[10];  
      cout << "Enter ADD, PRINT, DELETE, or QUIT: " << endl;
      cin >> input;
      //if input is QUIT then stop program
      if( strcmp(input, "QUIT") == 0) 
      {
        alive = false;
      }
      //if input is ADD start void add
      else if(strcmp(input, "ADD") == 0)
      {
        add(holder);
      }
      //if input is PRINT start void print
      else if( strcmp(input, "PRINT") == 0)
      {
        print(holder);
      }
      //if input is DELETE start void delete
      else if( strcmp(input, "DELETE") == 0)
      {
        del(holder);
      }
      //if input isnt good
      else 
      {
        cout << "Please enter an actual input!" << endl;
      }
    }
  return 0;
}

void add(vector<student*> &holder)
{
  //gets all the inputs
  student* studentADD = new student();
  cout << "First name: " << endl;
  cin >> studentADD->firstname; 
  cout << "Last name: " << endl;
  cin >> studentADD->lastname; 
  cout << "ID: " << endl;
  cin >> studentADD->id; 
  cout << "GPA: " << endl;
  cin >> studentADD->gpa;
  //put in vector
  holder.push_back(studentADD);
}

void del(vector<student*> &holder)
{
  //check if there is something to delete
  if (holder.size() != 0) {
    //get input
    int checkID;
    cout << "ID: " << endl;
    cin >> checkID;
    //go through all the structs and find their ids to compare with input
    for (int i = 0; i < holder.size(); i ++)
      {
        // erase if possible
        if ( checkID == holder[i]->id)
        {
          holder.erase(holder.begin() + i);
        }
      }
    }
  else 
  {
     cout << "You need to have inputs to delete!" << endl;
  }
}

void print(vector<student*> &holder)
{
  //go through all the structs in vector
  for (vector<student*> ::iterator it = holder.begin() ; it != holder.end(); ++it)
    {
      cout << (*it)->firstname << endl;
      cout << (*it)->lastname << endl;
      cout << (*it)->id << endl;
      cout << (*it)->gpa << endl;

    }
}
