#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

// Global variables and arrays useful in the program
const int NUM_ROWS = 10;  // number of rows of the battleship game board
const int NUM_COLS = 10;  // number of columns of the battleship game board
const int NUM_SHIPS = 5;  // number of ships in the battelship game
const char HIT = '*';     //character to represent hits with
const char MISS = 'm';    //character to represent misses with
const char OPEN_BOARD_SPACE = '-';

// Each of the ships information in 3 arrays (parallel arrays)
const string SHIP_NAMES[] = {"carrier", "battleship", "cruiser", "submarine", "destroyer"};
const char SHIP_SYMBOLS[] = {'c', 'b', 'r', 's', 'd'};
const int SHIP_SIZES[] = {5, 4, 3, 3, 2};

//Function Prototypes
bool valid_guess(const char board[NUM_ROWS][NUM_COLS], int row, int col);
bool hit(const char board[NUM_ROWS][NUM_COLS], int row, int col );
bool sink(const char board[NUM_ROWS][NUM_COLS], int row, int col, char ship);
void update_boards(char ships[NUM_ROWS][NUM_COLS], char guesses[NUM_ROWS][NUM_COLS], 
                   char impact, int row, int col);
void welcomeScreen();
void initializeBoard(char array[][NUM_COLS]);
void displayBoard(char array2[][NUM_COLS]); //need to add showShips parameter when we get further along in the program
bool ship_placement(char ships[NUM_ROWS][NUM_COLS], int row, int col, char direction, char ship, int size);
void randomPlacement (char arr[NUM_ROWS][NUM_COLS]);
int char_to_int(char c);
int selectWhoStartsFirst();
void playerTurn(int player);


#endif