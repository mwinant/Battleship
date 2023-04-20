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
int sink(const char board[NUM_ROWS][NUM_COLS], char shipIcons[NUM_SHIPS]);
void update_boards(char ships[NUM_ROWS][NUM_COLS], char guesses[NUM_ROWS][NUM_COLS], 
                   char impact, int row, int col);
void welcomeScreen();
void initializeBoard(char array[][NUM_COLS]);
void displayBoard(char array2[][NUM_COLS]); //need to add showShips parameter when we get further along in the program
bool ship_placement(char ships[NUM_ROWS][NUM_COLS], int row, int col, char direction, char ship, int size);
void randomPlacement (char arr[NUM_ROWS][NUM_COLS]);
int char_to_int(char c);
int selectWhoStartsFirst();
char generateRandomCol();
int generateRandomRow();
void player_turn(char guesses[NUM_ROWS][NUM_COLS], char ships[NUM_ROWS][NUM_COLS], int player, int &remaining_ships, char remaining_ship_icons[NUM_SHIPS]);
void hit_result(char ships[NUM_ROWS][NUM_COLS], char remaining_ship_icons[NUM_SHIPS], int &remaining_ships, int player);
void manual_placement(char player1_ships[NUM_ROWS][NUM_COLS]);
void outputTurnFile(ofstream& file, int row, char col, int player, string hit);
void sinkToFile(ofstream& file, int sink);
void outputStats(ofstream& file);
void get_col_and_row(int &r1, char &c1);


struct Statistics {
    int p1ShipsSank ;
    int p2ShipsSank ;
    double p1HitPercentage ;
    double p2HitPercentage ;
    int p1Hit ;
    int p2Hit ;
    int p1Total ;
    int p2Total ;

    Statistics()  //constructor with initialization list to initialize variables
    : p1ShipsSank(0), p2ShipsSank(0), p1HitPercentage(0), p2HitPercentage(0), p1Hit(0), p2Hit(0), p1Total(0), p2Total(0)
    {
    }
};

#endif