#include "battleship.h"

//FUNCTIONS
void welcomeScreen()
{
    cout << "***** Welcome to Battleship! *****\n\n";
    cout << "Object of the game: Be the first to sink all five of your opponent's ships!\n\n";
    cout << "Rules of the Game: \n";
    cout << "1. This is a two player game.\n";
    cout << "2. Player1 is you and Player2 is the computer.\n";
    cout << "3. During yor turn, enter the letter-number coordinate that you would like to target.\n";
    cout << "   a. The program will display if it is a HIT or MISS.\n";
    cout << "   b. If it is a HIT, you can enter a new target, otherwise, your turn is over. \n";
    cout << "4. The game ends when all five of an opponents ships are sunk.\n";
    cout << "Have fun!\n\n";

}
void initializeBoard(char array[][NUM_COLS])
{
      // create a blank board   
    for (int x=0; x<10; x++) 
    {
        for (int y=0; y<10; y++) 
        {
          array[x][y] = OPEN_BOARD_SPACE;
        }     
    }  

}
void displayBoard(char array2[][NUM_COLS])
{
    cout << "  ";
    for(char a='A'; a<='J'; a++)
    {
        cout << a << " " ;
    }
    cout << endl;
        for(int i=0; i<10; i++)
        {
            cout << i << " "; //displays columns
            for (int x=0; x<10; x++)
            {
                cout << array2[i][x] << " ";
            }
            cout << endl;
    }


}
void ship_placement(char ships[NUM_ROWS][NUM_COLS], int r1, int c1, int r2, int c2, char ship) 
{
    if (r2-r1 > 0) {
        for (int y=r1; y<=r2; y++) {
            ships[y][c1] = ship;
        }  
    } else if (r2-r1 <0) {         
        for (int y=r1; y>=r2; y--) {
            ships[y][c1] = ship;
        }  
    } else if (c2-c1 >0) {
        for (int x=c1; x<=c2; x++) {
            ships[r1][x] = ship;
        }  
    }else if (c2-c1 <0) {          
        for (int x=c1; x>=c2; x--) {
            ships[r1][x] = ship;
        }  
    }
}
