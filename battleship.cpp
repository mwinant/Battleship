#include "battleship.h"

//FUNCTIONS

/**
 * @brief Displays welcome screen and rules to user
 * 
 */
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
/**
 * @brief initializes game board
 * 
 * @param array 
 */
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
/**
 * @brief adds rows and column names to board
 * 
 * @param array2 
 */
void displayBoard(char array2[][NUM_COLS])
{
    cout << "   ";
    for(char a='A'; a<='J'; a++)
    {
        cout << a << " " ;
    }
    cout << endl;
        for(int i=0; i<10; i++)
        {
            cout << setw(2) << i+1 << " "; //displays columns
            for (int x=0; x<10; x++)
            {
                cout << array2[i][x] << " ";
            }
            cout << endl;
    }


}
/**
 * @brief takes coordinate and places ships in corresponding places, but
 *        first detects if the ships will intersect.
 * 
 * @param ships array that ships will be placed on
 * @param row row ship will be placed on
 * @param col column ship will be placed on
 * @param direction which direction to build out the rest of ship
 * @param ship ship character to replace '-'
 * @param size how many spaces will be modified from row/column
 * @return true for an intersection
 * @return false for no intersections
 */
bool ship_placement(char ships[NUM_ROWS][NUM_COLS], int row, int col, char direction, char ship, int size) 
{
    //checks to see if there are any intersections
    if(direction == 'h'||direction == 'H'){                     //horizontal check
        if(NUM_COLS-(col+size)>=0&&row>=0&&row<=NUM_ROWS){
            for(int i = 0; i<size; i++){
                int column = col+i;
                if(ships[row-1][column]!='-'){
                    return false;
                }
            }
        }
    } else if(direction == 'v'||direction == 'V'){              //vertical check
        if(NUM_ROWS-(row+size)>=0&&col>=0&&col<=NUM_COLS-1){
            for(int i = 0; i<size; i++){
                int r = row+i-1;
                if(ships[r][col]!='-'){
                    return false;
                }
            }
        }
    }

    //places ships if there are no intersections
    if(direction == 'h'||direction == 'H'){                     //horizontal placement
        if(NUM_COLS-(col+size)>=0&&row>=0&&row<=NUM_ROWS){
            for(int i = 0; i<size; i++){
                int column = col+i;
                ships[row-1][column]=ship;
            }
            return true;
        }
    } else if(direction == 'v'||direction == 'V'){              //vertical placement
        if(NUM_ROWS-(row+size-1)>=0&&col>=0&&col<=NUM_COLS-1){
            for(int i = 0; i<size; i++){
                int r = row-1+i;
                ships[r][col]=ship;
            }
            return true;
        }
    }
    return false;

}
/**
 * @brief Places ships randomly on the board, us
 * 
 * @param arr array to be modified with placed ships
 */
void randomPlacement (char arr[NUM_ROWS][NUM_COLS]){
    for (int i=0; i<NUM_SHIPS; i++){
        bool valid;
        do{
            char name = SHIP_SYMBOLS[i];
            char size = SHIP_SIZES[i];
            int direction = rand()%3;
            if(direction == 1){
                char dir = 'h';
                int col = rand()%10; //random column
                int row = rand()%(10-size)+1; //random row
                valid = ship_placement(arr, row, col, dir, name, size); //places random column and row using ship placement function
            } else if (direction == 0) {
                char dir = 'v';
                int col = rand()%(10-size);
                int row = rand()%10+1;
                valid = ship_placement(arr, row, col, dir, name, size);
            } else {
                valid = false;
            }
        } while (valid!=true);  
    }
}

void shipSymbolsToCheck(char array [NUM_SHIPS]){
    for(int i = 0; i < NUM_SHIPS; i++){
        array [i] = SHIP_SYMBOLS[i];
    }
}