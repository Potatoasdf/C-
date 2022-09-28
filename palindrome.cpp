//palindrome by Aidan Gao
//Last worked on: 9/28/22

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char input[80];
  cin.get(input, 80);
  cin.get();
  int count = 0;
  char lowercase;
  int editlen = 0;
  //lowercasing capital letters and
  //replacing non letter characters with ' '
  // edit len is to find how many ' ' there are
  while (input[count])
    {
      lowercase = input[count];
      input[count] = tolower(lowercase);
      if(!isalpha(input[count])) {
	  input[count] = ' ';
	  editlen++;
	}
      count++;
    }
  // index is used to add stuff to pali
  int index = strlen(input) - 1 - editlen;
  int inputLen = strlen(input);
  char copy[inputLen - editlen];
  char pali[inputLen - editlen];
  count = 0;
  
  //go through input and if the character
  //is not a ' ' than add it to copy and
  //pali with pali going from top to
  //bottom and copy being bottom to top
  for (int i = 0; i < inputLen; i++) {
    if ( input[i] != ' ') {
      copy[count] = input[i];
      pali[index] = input[i];
      count++;
      index--;
    }
  
  }
  copy[count] = '\0';
  pali[count] = '\0';
  // compare the two and if they are
  //equal then they are palindrome
  //if the arent then not my problem
  if (strcmp(pali, copy) == 0) {
    cout << "This is a palindrome!" << endl;
  }
  else {
    cout << "this is not a palindrome!" << endl;
    
  }
  
  return 0;
}
