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
    if (row<1 || row>NUM_ROWS || col<0 || col >NUM_COLS) {
        return false;
    }
    //check for open board space
    if (board[row-1][col-1] != OPEN_BOARD_SPACE) {
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
        if (board[row][col] ==SHIP_SYMBOLS[i]||board[row][col] =='*') {
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
bool sink(const char board[NUM_ROWS][NUM_COLS], int row, int col, char ship) 
{
    row -=1;
    /*
    check right, left, up, and down from the guess and return true
    if there are no charcters matching 'ship'
    */
    while (col<NUM_COLS) {
        if (board[row][col++] == ship) {
            return false;
        }
    }
    while (col>0) {
        if (board[row][col--] == ship) {
            return false;
        }
    }
    while (row<NUM_ROWS) {
        if (board[row++][col] == ship) {
            return false;
        }
    }
    while (row>0) {
        if (board[row--][col] == ship) {
            return false;
        }
    }
    return true;
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