//Aidan Gao
//Guessing game
//Last edited: 9/14/22
#include <iostream>

using namespace std;

int main()
{
  bool stillplaying = true;
  char answer;
  int input = 101;
  srand(time(NULL));
  int randint = rand() % 100;
  int count = 0;
  // while you still want to play keep going
  while (stillplaying == true)
    {
      // get input and keep track of turns
      cout << "give an int please: ";
      cin >> input;
      count++;
      cout << input << endl;
      
      if (input == randint)
	{
	  // if equal say amount of attempts and ask if you want to play again
	  cout << "You win!" << endl << "It took " << count << " attempts!" << endl;
	  cout << "Type a to play again!: ";
	  cin >> answer;
	  // if yes then reset random num and turns
	  if ( answer == 'a' )
	    {
	      srand(time(NULL));
	      randint = rand() % 100;
	    }
	  // if no then stop while loop
	  else
	    {
	      stillplaying = false;
	    }
	}
      else
	{
	  // if guess isnt equal to rand int
	  if( input > randint )
	    {
	      //if too high
	      cout << "Too high!!" << endl;
	    }
	  else
	    {
	      // if too low
	      cout << "Too low!!" << endl;
	    }
	}
    }
}

