//Project: TicTacToeee
//By: Aidan Gao
//Last worked on: 10/13/2022 
#include <iostream>
#include <cstring>
using namespace std;

void printboard(char board[3][3]);
bool checkTie(char board[3][3]);
bool checkXWin(char board[3][3]);
bool checkOWin(char board[3][3]);

int main()
  {
    char board[3][3];
    char input[3];
    bool stillplaying = true;
    char turn = 'X';
    int xwins = 0;
    int owins = 0;
    char a;
  
  
    //clear board
    for(int i = 0; i < 3; i++ )
      {
        for(int j = 0; j < 3; j++ )
          {
            board[i][j] = ' ';
          }
  
      }
  
    while(stillplaying == true)
      {
        // checking if the inputs are good
        printboard(board); 
        cout << "Please enter a letter followed by a number:" << endl;
        cin >> input;
        if(strlen(input) != 2)
          {
            cout << "Not the right amount of characters!" << endl;
          }
        else if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c' )
          {
            cout << "1st char needs to be a, b, c" << endl;
          }
        else if (input[1] != '1' && input[1] != '2' && input[1] != '3')
          {
            cout << "2nd char needs to be 1, 2, 3!" << endl;
          }
        else
          {
            //if good then check if the tile is claimed if it isnt than place letter than go to next turn
            if ( board[(int)(input[0]) - 97][(int)(input[1]) - 49] != 'O' &&
                 board[(int)(input[0]) - 97][(int)(input[1]) - 49] != 'X')
              {
                board[(int)(input[0]) - 97][input[1] - 49] = turn;
                cout << input[1] << endl;
                cout << (int)(input[1]) << endl;
                cout << (int)(input[0]) - 97 << ',' << (input[1] - 49) << endl;
                cout << board[(int)(input[0]) - 97][input[1] - 49] << endl;
                if ( turn == 'X')
                  {
                    turn = 'O';
                    cout << turn << endl;
                  }
                else if ( turn == 'O')
                  {
                    turn = 'X';
                    cout << turn << endl;
                  }
              }
            else
              {
                cout << "Tile has already been claimed!" << endl;
              }
            //check win for x and o if win than ask to play again if a then clear board and start over else end game
            if(checkXWin(board) == true)
              {
                xwins++;
                cout << "X wins! " << endl << "X has won " << xwins << " times!" << endl << "O has won " << owins << " times!" << endl << "Type a to play again!" << endl;
                cin >> a;
                if ( a == 'a') 
                  {
                    
                    for(int i = 0; i < 3; i++ )
                      {
                        for(int j = 0; j < 3; j++ )
                          {
                            board[i][j] = ' ';
                          }
                
                      }
                    
                  }
                else 
                  {
                     stillplaying = false; 
                  }
              }
            if(checkOWin(board) == true)
              {
                owins++;
                cout << "O wins! " << endl << "X has won " << xwins << " times!" << endl << "O has won " << owins << " times!" << endl << "Type a to play again!" << endl;
                cin >> a;
                if ( a == 'a') 
                  {
                    
                    for(int i = 0; i < 3; i++ )
                      {
                        for(int j = 0; j < 3; j++ )
                          {
                            board[i][j] = ' ';
                          }
                  
                      }
                    
                  }
                else 
                  {
                     stillplaying = false; 
                  }
              }
            //checktie is bassically the same
            if (checkTie(board) == true) 
              {
              
                cout << "Tie!" << endl << "type a to play again!" << endl;
                cin >> a;
                if ( a == 'a') 
                  {
                    for(int i = 0; i < 3; i++ )
                      {
                        for(int j = 0; j < 3; j++ )
                          {
                            board[i][j] = ' ';
                          }
                  
                      }
                    
                  }
                else 
                  {
                     stillplaying = false; 
                  }
              }
          }
      }
    return 0;
  }
  // prints board layer by layer
void printboard(char board[3][3])
{
  char letter;
  char output[7];
  cout << "\t1\t2\t3" << endl;
  for ( int row = 0; row < 3; row++)
    {
      letter = (char)('a' + row);
      for ( int col = 0; col < 3; col++)
        {
          output[(col * 2)] = board[row][col];
          output[(col * 2) + 1] = '\t';
        }
      cout << letter << '\t' << output << endl;
    }
}

//checks if board is filled if it is then true else false
bool checkTie(char board[3][3])
{
  int count = 0;
  for(int i = 0; i < 3; i++ )
    {
      for(int j = 0; j < 3; j++ )
        {
          if(board[i][j] != ' ')
            {
              count++;
            }
        }

    }
  if(count == 9)
    {
      return true;
    }
  else
    {
      return false;
    }

}
// im lazy therefore you get 2 check wins
// copied from java
bool checkXWin(char board[3][3])
{
  if (board[0][0] == 'X' &&board[0][1] == 'X' &&board[0][2] == 'X')
    {
      return true;
    }
  if (board[1][0] == 'X' &&board[1][1] == 'X' &&board[1][2] == 'X')
    {
      return true;
    }
  if (board[2][0] == 'X' &&board[2][1] == 'X' &&board[2][2] == 'X')
    {
      return true;
    }
  if (board[0][0] == 'X' &&board[1][0] == 'X' &&board[2][0] == 'X')
    {
      return true;
  }
  if (board[0][1] == 'X' &&board[1][1] == 'X' &&board[2][1] == 'X')
    {
      return true;
  }
  if (board[0][2] == 'X' &&board[1][2] == 'X' &&board[2][2] == 'X')
    {
    return true;
    }
  if (board[0][0] == 'X' &&board[1][1] == 'X' &&board[2][2] == 'X')
    {
    return true;
    }
  if (board[0][2] == 'X' &&board[1][1] == 'X' &&board[2][0] == 'X')
    {
      return true;
    }

  return false;
}
bool checkOWin(char board[3][3])
{
  if (board[0][0] == 'O' &&board[0][1] == 'O' &&board[0][2] == 'O')
    {
      return true;
    }
  if (board[1][0] == 'O' &&board[1][1] == 'O' &&board[1][2] == 'O')
    {
      return true;
    }
  if (board[2][0] == 'O' &&board[2][1] == 'O' &&board[2][2] == 'O')
    {
      return true;
    }
  if (board[0][0] == 'O' &&board[1][0] == 'O' &&board[2][0] == 'O')
    {
      return true;
  }
  if (board[0][1] == 'O' &&board[1][1] == 'O' &&board[2][1] == 'O')
    {
      return true;
  }
  if (board[0][2] == 'O' &&board[1][2] == 'O' &&board[2][2] == 'O')
    {
    return true;
    }
  if (board[0][0] == 'O' &&board[1][1] == 'O' &&board[2][2] == 'O')
    {
    return true;
    }
  if (board[0][2] == 'O' &&board[1][1] == 'O' &&board[2][0] == 'O')
    {
      return true;
    }

  return false;
}

