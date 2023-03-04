#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void print(int* heap, int location, int space);
void sort(int* &heap, int count);
int layer(int count);

int main()
{
  
  int* heap = new int[200];
  for (int i = 0; i < 200; i++)
    {
      heap[i] = 0;
    }
  bool alive = true;
  while(alive)
    {
      char input[10];
      cout << "ADD, GEN, DEL, CLEAR, PRINT, QUIT" << endl;
      cin >> input;
      //get input and find size of heap before sorting
      if(strcmp(input, "ADD") == 0)
	{
	  int intput;
	  cin >> intput;
	  int count = 0;
	  while(heap[count] != 0)
	    {
	      cout << heap[count] << endl;
	      count++;
	      
	    }
	  heap[count] = intput;
	  cout << "Count: ";
	  cout << count << endl;
	  cout << "Layer: ";
	  cout << layer(count) << endl;
	  sort(heap, count);
	}
      else if(strcmp(input, "PRINT") == 0)
	{
	  print(heap, 0, 0);
	}
      else
	{
	  cout << "pls give actually input" << endl;
	}
    }
  
  return 0;
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

// stolen from my brothers code
void print(int* heap, int location, int space)
{
  if(heap[location] == 0)
    {
      return;
    }
  space += 10;

  print(heap, location*2 + 1, space);

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
  int layer = 0;
  while (count > layer)
    {
      layer++;
      count = count -layer;
    }
  return layer;
}
