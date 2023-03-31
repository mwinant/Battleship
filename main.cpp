/**
 * @file main.cpp
 * @author Wade, Quinton, Mickayla
 * @brief 
 * @date 2023-03-22
 */

#include <cctype>
#include <iostream>
#include "battleship.h"
using namespace std;

int main() 
{   
    //Game board arrays
    char player1_ships[NUM_ROWS][NUM_COLS];
    char player1_guesses[NUM_ROWS][NUM_COLS];
    char player2_ships[NUM_ROWS][NUM_COLS];
    char player2_guesses[NUM_ROWS][NUM_COLS]; 
    
    int row;  //player guesses for a location
    char col;

    //Main Game Loop
    while (true) {
        //initialized boards
        initializeBoard(player1_ships);
        initializeBoard(player1_guesses);
        initializeBoard(player2_ships);
        initializeBoard(player2_guesses);

        welcomeScreen(); //Welcomes Player and Displays Rules

        //TODO: Set ships on the boards with manual or auto option

        int col_int = 0;
        while (true) {          //loop so player can continue if they get a hit
            displayBoard(player1_guesses);
            do {
                //ask Player1 for guess
                cout<<"Enter Guess(row, col): ";
                cin>>row>>col;
                char lcol = tolower(col);
                col_int = lcol - 'a';         //convert character so it can be used as index in array
            } while (!valid_guess(player2_ships, row, col_int));

            if (hit(player2_ships, row, col_int)) {
                cout<<"That is a hit.";
                //get the ship type that was just hit for use in checking for a sink
                char ship_type = player2_ships[row-1][col_int-1];
                update_boards(player2_ships, player1_guesses, HIT, row, col_int);
                displayBoard(player1_guesses);
                if (sink(player2_ships, row, col_int, ship_type)) {
                    //tell player they sunk the corresponding ship
                    //TODO:Function that converts ship symbol to ship type or better way
                    cout<<"You sunk their "<<"TODO"<<endl;
                }
                continue;  //allows player1 do go again if they hit
            } else {
                update_boards(player2_ships, player1_guesses, MISS, row, col_int);
                displayBoard(player1_guesses);
                cout<<"That is a miss.\n";
                break;
            }
        }
        
        
        
        break; //temp to avoid infinite loop;
    }

    return 0;
}