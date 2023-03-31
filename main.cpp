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
    //initialized boards
    initializeBoard(player1_ships);
    initializeBoard(player1_guesses);
    initializeBoard(player2_ships);
    initializeBoard(player2_guesses);

    welcomeScreen(); //Welcomes Player and Displays Rules

    int r1=0, r2=0, c1_int=0, c2_int=0;
    char c1='a', c2='a', choice;

    //TODO: Set ships on the board with auto option and set player 2 ships
    //TODO: If the user mixes up the char and int input there is a problem
    cout<<"Manual ship placement? (y/n): ";
    cin>>choice;
    if (choice == 'y') {
        displayBoard(player1_ships);
        for (int i=0; i<NUM_SHIPS; i++) {
            bool valid_length = false;
            do {
                cout<<"Enter a start and stop coordinate for your "<<SHIP_NAMES[i]<<" ("<<SHIP_SIZES[i]<<" spaces): ";
                cin>> r1>>c1>>r2>>c2;
                c1_int = char_to_int(c1);       //convert character so it can be used as index in array
                c2_int = char_to_int(c2);
                //check for appropriate ship lengths
                if (abs(r2-r1) == SHIP_SIZES[i]-1) {
                    valid_length = true;
                } if (abs(c2_int-c1_int) == SHIP_SIZES[i]-1) {
                    if (valid_length==true) {   //disallows diagonal ship placments
                        valid_length = false;
                        cout<<"Ships can't be placed diagonally.\n";
                    } else
                        valid_length = true;
                }
            } while (!valid_guess(player1_ships, r1, c1_int) || !valid_guess(player1_ships, r2, c2_int) || !valid_length);  
            ship_placement(player1_ships, r1, c1_int, r2, c2_int, SHIP_SYMBOLS[i]);
            displayBoard(player1_ships);
        }
    } else {
        //auto ship placement
        for (int i=0; i<NUM_SHIPS; i++){
            //"randomly" get coordinates
            
            ship_placement(player1_ships, r1, c1, r2, c2, SHIP_SYMBOLS[i]);
        }
    }
    
    //Main Game Loop
    while (true) {

        int row;  //player guesses for a location
        char col;
        int col_int = 0;
        while (true) {          //loop so player can continue if they get a hit
            displayBoard(player1_guesses);
            do {
                //ask Player1 for guess
                cout<<"Enter Guess(row, col): ";
                cin>>row>>col;
                col_int = char_to_int(col);      //convert character so it can be used as index in array
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
        system("clear");
    }

    return 0;
}