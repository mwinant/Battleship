/**
 * @file input_processing.cpp
 * @author Quinton Sampsel 
 * @brief Functions that handle user input processing for the battleship game
 * @date 2023-03-21
 */

 #include "battleship.h"

/**
 * @brief Checks if guess is on the board and checks if there is an open board space
 * 
 * @param board 
 * @param row 
 * @param col 
 * @return true for a valid guess
 * @return false 
 */
bool valid_guess(const char board[NUM_ROWS][NUM_COLS], int row, int col)
{
    //row -=1;
    if (row<1 || row>NUM_ROWS || col<0 || col >NUM_COLS-1) {
        return false;
    }
    //check for open board space
    if (board[row-1][col] != OPEN_BOARD_SPACE) {
        return false;
    }
    return true;
}
/**
 * @brief Checks if the charcter at the location the player guesses matches a ship symbol
 * 
 * @param board 
 * @param row 
 * @param col 
 * @return true for a hit
 * @return false 
 */
bool hit(const char board[NUM_ROWS][NUM_COLS], int row, int col )
{
    row -=1;
    for (int i=0; i<NUM_SHIPS; i++) {
        if (board[row][col] ==SHIP_SYMBOLS[i]) {  
            return true;
        }
    }
    return false;
}
/**
 * @brief Checks in the 4 directions from the location of the hit to the edge of the board 
          to look for a surviving ship symbol that matches the ship hit 
 * 
 * @param board 
 * @param row 
 * @param col 
 * @param ship 
 * @return true 
 * @return false when there is a ship symbol remaining matching the ship that was hit
 */
int sink(const char board[NUM_ROWS][NUM_COLS], char shipIcons[NUM_SHIPS]) 
{
    for(int i = 0; i < NUM_SHIPS; i++){
        for(int row = 0; row < NUM_ROWS; row++){
            for(int col = 0; col < NUM_COLS; col++){
                if(board[row][col] == shipIcons[i]){
                    goto SKIP;
                }
            }
        }
        shipIcons[i] = '*';
        return i;
        SKIP: continue;
    }
    return -1;
}
/**
 * @brief Update the two boards that are of concern during a turn
 * 
 * @param ships 
 * @param guesses 
 * @param impact 
 * @param row 
 * @param col 
 */
void update_boards(char ships[NUM_ROWS][NUM_COLS], char guesses[NUM_ROWS][NUM_COLS], 
                  char impact, int row, int col) 
{ 
    row-=1;
    ships[row][col] = impact;
    guesses[row][col] = impact;
}
/**
 * @brief Convert chars to ints. The columns on the boards will be entered as characters and they are converted 
            here to ints so they are easier to work with.
 * 
 * @param c 
 * @return int 
 */
int char_to_int(char c) 
{
    char lc = tolower(c);       //convert character to lower for consitency
    int c_int = lc - 'a';       // use ASCII values to turn char into int that can be used as index for arry (a=0)
    return c_int;
}
/**
 * @brief Gets called if player selects manual placement
 * 
 * @param player1_ships 
 */
void manual_placement(char player1_ships[NUM_ROWS][NUM_COLS])
{
    int r1=0, c1_int=0;
    char c1='a';

    for (int i=0; i<NUM_SHIPS; i++) {
        bool correct = false;
        do {
            char direction;
            cout << "Would you like your "<<SHIP_NAMES[i]<<" placed horizontally or vertically?(h/v)";
            cin >> direction;
            if(direction=='h'||direction=='H'||direction=='v'||direction=='V'){
                cout<<"Enter a coordinate for your "<<SHIP_NAMES[i]<<" ("<<SHIP_SIZES[i]<<" spaces, left to right if horizontal and top to bottom if vertical): ";
                cin>>r1>>c1;
                if(cin.fail()){                     //runs if either input is invalid (if first input is invalid, second input is used 
                    cout << "Invalid\n";            //for start of next line, which would likely be invalid. this doesnt really matter
                    cin.clear();                    //, but it'd probably be cleaner with a getline function and some delim stuff.)
                    cin.sync();
                    cin.ignore();
                    //correct = false;
                } else {                            //runs if input is invalid
                    c1_int = char_to_int(c1);       //convert character so it can be used as index in array
                    char name = SHIP_SYMBOLS[i];
                    int size = SHIP_SIZES[i];
                    correct = ship_placement(player1_ships, r1, c1_int, direction, name, size);
                    if(correct==false){
                        cout << "Invalid Placement, please try again\n";
                    }
                }
            } else { //runs if direction is invalid
                cout << "Invalid direction, please try again\n";
            }
        } while (correct != true);  
            displayBoard(player1_ships); //displays where ship is placed
    }
}