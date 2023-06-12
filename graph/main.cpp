#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

struct vertex
{
  char label;
  int id;
  
};

void addV(vector<vertex*> &holder, int &count);
void addE(vector<vertex*> &holder, int** adjacencyTable);
bool compare(vector<vertex*> holder, char input, int &i);

void delE(vector<vertex*> &holder, int** adjacencyTable);
void delV(vector<vertex*> &holder, int** adjacencyTable);

void print(vector<vertex*> holder, int** adjacencyTable);
int main()
{
  int size = 20;
  int count = 0;
  int* adjacencyTable[size];
  for(int i = 0; i < size; i++)
    {
      adjacencyTable[i] = new int[size];
      for(int j = 0; j < size; j++)
	{
	  if(i == j)
	    {
	      adjacencyTable[i][j] = 0;
	    }
	  else
	    {
	      adjacencyTable[i][j] = -1;
	    }
	}
    }
  vector<vertex*> holder;
  bool alive = true;
  //while alive
  while (alive)
    {
      
      
      cout << holder.size();
      //get input
      char input[10];
      cout << "Enter ADDV, ADDE, PRINT, DELE, DELV, or QUIT: " << endl;
      cin >> input;
      //if input is QUIT then stop program
      if( strcmp(input, "QUIT") == 0)
	{
	  alive = false;
	}
      else if(strcmp(input, "ADDV") == 0)
	{
	  addV(holder, count);
	}
      else if(strcmp(input, "ADDE") == 0)
	{
	  addE(holder, adjacencyTable);
	}
      else if( strcmp(input, "PRINT") == 0)
	{
	  print(holder, adjacencyTable);
	}
      else if( strcmp(input, "DELE") == 0)
	{
	  delE(holder, adjacencyTable);
	}
      else if(strcmp(input, "DELV") == 0)
	{
	  delV(holder, adjacencyTable);
	}
      //if input isnt good
      else
	{
	  cout << "Please enter an actual input!" << endl;
	}
    }
  return 0;
}
void delV(vector<vertex*> &holder, int** adjacencyTable)
{
  char input;
  int countinput = 0;
  cout << "enter label" << endl;
  cin >> input;
  if(compare(holder, input, countinput) == true)
    {
      holder.erase(holder.begin()+countinput);
      for (int i = 0; i < 20; i++)
	{
	  adjacencyTable[i][countinput] = -1;
	  adjacencyTable[countinput][i] = -1;
	}
    }
  else
    {
      cout << "not a valid input" << endl;
    }
}

void delE(vector<vertex*> &holder, int** adjacencyTable)
{//get to inputs and their place on the adjacencytable
  char input;
  int countinput = 0;

  cout << "Give two labels" << endl;
  cin >> input;
  if(compare(holder, input, countinput) == true)
    {
      char input2;
      int countinput2 = 0;

      cin >> input2;
      if(compare(holder, input2, countinput2) == true)
        {
	  //set their values back to -1(default)
          adjacencyTable[countinput][countinput2] = -1;
          adjacencyTable[countinput2][countinput] = -1;
          cout << adjacencyTable[countinput][countinput2];
        }
      else
        {
          cout << "not a valid input" << endl;
        }
    }
  else
    {
    cout << "not a valid input" << endl;
    }

}

void addE(vector<vertex*> &holder, int** adjacencyTable)
{//get two inputs and their place on the adjacency table
  char input;
  int countinput = 0;
  
  cout << "Give two labels" << endl;
  cin >> input;
  if(compare(holder, input, countinput) == true)
    {
      char input2;
      int countinput2 = 0;

      cin >> input2;
      if(compare(holder, input2, countinput2) == true)
	{//put weight
	  cout << countinput << endl;
	  cout << countinput2 << endl;
	  cout << "what is the weight of the edge?" << endl;
	  int weight;
	  cin >> weight;
	  adjacencyTable[countinput][countinput2] = weight;
	  adjacencyTable[countinput2][countinput] = weight;
	  cout << adjacencyTable[countinput][countinput2];
	}
      else
	{
	  cout << "not a valid input" << endl;
	}
    }
  else
    {
      cout << "not a valid input" << endl;
    }
  
}
bool compare(vector<vertex*> holder, char input, int &i)
{// find if vertex exists in holder also get where it exists
  for (i = 0; i < holder.size(); i++)
    {
      if(holder[i]->label == input)
	{
	  return true;
	  break;
	}
    }
  return false;
    
}

void addV(vector<vertex*> &holder, int &count)
{
  vertex* newvertex = new vertex();
  cout << "Please label your vertex with a letter" << endl;
  cin >> newvertex->label;
  newvertex->id = count;
  count++;
  holder.push_back(newvertex);
  
  
}

void print(vector<vertex*> holder, int** adjacencyTable)
{
  for (int i = 0; i < holder.size(); i++)
    {
      cout << "E" << endl;
      cout << holder[i]->id << endl;
      cout << holder[i]->label << endl;
    }
  for (int i = 0; i < 20; i++)
    {
      for (int j = 0; j < 20; j++)
	{
	  cout << adjacencyTable[j][i] << " ";
	}
      cout << endl;
    }
}
