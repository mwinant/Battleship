/**
 * @file main.cpp
 * @author Wade, Quinton, Mickayla
 * @brief 
 * @date 2023-03-22
 */

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
    
    int row, col;  //player guesses for a location

    welcomeScreen(); //Welcomes Player and Displays Rules
    char board[NUM_ROWS][NUM_COLS];
    initializeBoard(board);
    displayBoard(board);

    //Main Game Loop
    while (1) {


        do {
            //ask Player1 for guess
            cout<<"Test"<<endl;

        } while (!valid_move(player2_ships, row, col));


        if (hit(player2_ships, row, col)) {
            char ship_type = player2_ships[row-1][col-1];
            update_boards(player2_ships, player1_guesses, HIT);
            if (sink(player2_ships, row, col, ship_type)) {
                //tell player they sunk the corresponding ship
            }
            //continue;  //allows player1 do go again if they hit but won't work for P2
        } else {
            update_boards(player2_ships, player1_guesses, MISS);
        }

        
        
        
        break; //temp to avoid infinite loop;
    }

    return 0;
}