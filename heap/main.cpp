#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;

void print(int* heap, int location, int space);
void sort(int* &heap, int count);
void del(int* &heap, int count);
void gen(int* &heap, int &count);
void addAll(int* &heap, int &count);
int layer(int count);
int getCount(int* heap);

int main()
{
  int count = 0;
  int* heap = new int[2000];
  for (int i = 0; i < 2000; i++)
    {
      heap[i] = 0;
    }
  bool alive = true;
  char input[10];
  while(alive)
    {
      
      cout << "ADD, ADDALL, GEN, DEL, CLEAR, PRINT, QUIT" << endl;
      cin >> input;
      //get input and find size of heap before sorting
      if(strcmp(input, "ADD") == 0)
	{
	  cout << "Number: ";
	  int intput;
	  cin >> intput;
	  count = getCount(heap);
	  //goes through the root till it reaches the last num to get # of nums in list
	  heap[count] = intput;
	  sort(heap, count);
	}
      else if(strcmp(input, "ADDALL") == 0)
	{
	  count = getCount(heap);
	  addAll(heap, count);
	}

      else if(strcmp(input, "PRINT") == 0)
	{
	  count = getCount(heap);
	  sort(heap, count);
	  print(heap, 0, 0);
	}
      else if(strcmp(input, "GEN") == 0)
	{
	  
	  count = getCount(heap);
	  gen(heap, count);
	}
      else if(strcmp(input, "DEL") == 0)
	{
	  count = getCount(heap);
	  cout << "Deleting root..." << endl;
	  del(heap, count -1);


	}
      else if(strcmp(input, "CLEAR") == 0)
	{
	  count = getCount(heap);
	  //until heap is clear keep deleting the root
	  while(heap[0] != 0)
	    {
	      del(heap, count -1);
	    }
	}
      else if (strcmp(input, "QUIT") == 0)
	{
	  alive = false;
	}
      else
	{
	  cout << "pls give actually input" << endl;
	}
    }
  
  return 0;
}
  
void del(int* &heap, int count)
{
  //replace top node with bottom
  heap[0] = heap[count];
  //delete bottom node
  heap[count] = 0;
  sort(heap, count);
}
 
void sort(int* &heap, int count)
{
  //keep recursing if count > 0
  if(count > 0)
    {
      //if parent is smaller than child than swap places
      int holder = 0;
      int parent = int((count-1)/2);

      if(heap[parent] < heap[count])
	{
	  holder = heap[parent];
	  heap[parent] = heap[count];
	  heap[count] = holder;

	}
      //recursion
      sort(heap, count -1);
    }    
}

void gen(int* &heap, int &count)
{
  //get amount of # wanted than returns that amount of random nums
  int input;
  cout << "How many numbers do you want to generate?" << endl;
  cin >> input;
  srand(time(NULL));
  int num;
  //randomizer
  ifstream nums("1-1000.txt");
  for(int i = 0; i < input; i++)
    {
      int random = rand()%1000;
      for(int j = 0; j < 1000; j++)
	{
	  if(random == j)
	    {
	      nums >> num;
	    }
	  else if(j < random)
	    {
	      nums >> num;
	    }
	}
    
  
      //add and sort
      heap[i + count] = num;
      sort(heap, count + i);
      nums.close();
      nums.open("1-1000.txt");
    }
}
  
  


// stolen from my brothers code
void print(int* heap, int location, int space)
{
  //keep adding space till empty index
  if(heap[location] == 0)
    {
      return;
    }
  space += 10;

  print(heap, location*2 + 1, space);
  //print space than heap index
  cout << "\n" <<endl;
  for(int i = 10; i < space;i++)
    {
      cout << " ";
    }
  cout << heap[location] << "\n";
  print(heap, location*2 + 2, space);
}

int layer(int count)
{
  //if count is less than layer increase layer by 1 and minus the difference
  int layer = 0;
  while (count > layer)
    {
      layer++;
      count = count -layer;
    }
  return layer;
}

int getCount(int* heap)
{
  //goes to end of heap and returns index
  int val = 0;
  while (heap[val] != 0)
    {
      val++;
    }
  return val;
}
void addAll(int* &heap, int &count)
{
  int num;
  ifstream nums("1-1000.txt");
  for(int i = 0; i < 1000; i++)
    {
      //go through textfile and add nums
      nums >> num;
      //add and sort
      heap[i + count] = num;
      sort(heap, count + i);
    }
  nums.close();
  nums.open("1-1000.txt");
    
}
