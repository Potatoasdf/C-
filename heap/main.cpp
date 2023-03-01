#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void print(int* heap, int layer, int index, int numCount);
void sort(int* heap, int count, int layer);
void sortSwitch(int* heap, int i, int layer, int top, int last);
int main()
{
  int layer = 0;
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
      
      if(strcmp(input, "ADD") == 0)
	{
	  int intput;
	  cin >> intput;
	  int count = 1;
	  while(heap[count] != 0)
	    {
	      cout << heap[count] << endl;
	      count++;
	      
	    }
	  heap[count] = intput;

	  if (2*(pow(2, layer)) == count)
	    {
	      layer++;
	    }
	  
	  sort(heap, count, layer);
	}
      else if(strcmp(input, "PRINT") == 0)
	{
	  print(heap, layer, 0, 1);
	}
      else
	{
	  cout << "pls give actually input" << endl;
	}
    }
  
  return 0;
}
void print(int* heap, int layer, int index, int numCount)
{
  for(int i = 0; i < 200; i++)
    {
      if(heap[i] != 0)
	{
	  cout << heap[i] << " ";
	}
    }
  cout << '\n';
  
  
}
void sort(int* heap, int count, int layer)
{
  for (int i = pow(2, layer); i <= count; i++)
    {
      sortSwitch(heap, i, layer, layer, i);
	
    }
}
void sortSwitch(int* heap, int i, int layer, int top, int last)
{
  cout << i << endl;
  cout << "You are on layer:" << layer << endl;
  if(layer == 1)
    {
      if(heap[1] < heap[i])
	{
	  int holder = heap[i];
	  heap[i] = heap[1];
	  heap[1] = holder;

	  print(heap, 0, 0, 0);
	  sortSwitch(heap, last, top, top, last);
	}
    }
  else if(i > 1)
    {
      if(heap[int(round((i-1)/2))] < heap[i])
	{
	  int holder = heap[i];
	  heap[i] = heap[int(round((i-1)/2))];
	  heap[int(round((i-1)/2))] = holder;
	  print(heap, 0, 0, 0);
	  
	  sortSwitch(heap, int(round((i-1)/2)), layer - 1, top, last);
	}
    }
  else
    {
      
    }
}
