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
    
    srand(time(0)); 

    int r1=0, c1_int=0;
    char c1='a', choice;

    //TODO: Set ships on the board with auto option and set player 2 ships
    //TODO: If the user mixes up the char and int input there is a problem
    cout<<"Manual ship placement? (y/n): ";
    cin>>choice;
    if (choice == 'y') {
        displayBoard(player1_ships);
        for (int i=0; i<NUM_SHIPS; i++) {
            bool correct = false;
            do {
                char direction;
                cout << "Would you like your carrier placed horizontally or vertically?(h/v)";
                cin >> direction;
                cout<<"Enter a coordinate for your "<<SHIP_NAMES[i]<<" ("<<SHIP_SIZES[i]<<" spaces, left to right if horizontal and top to bottom if vertical): ";
                cin>>r1>>c1;
                c1_int = char_to_int(c1);       //convert character so it can be used as index in array
                char name = SHIP_SYMBOLS[i];
                int size = SHIP_SIZES[i];
                correct = ship_placement(player1_ships, r1, c1_int, direction, name, size);
                if(correct==false){
                    cout << "Invalid Placement, please try again\n";
                }
            } while (correct!=true);  
            displayBoard(player1_ships);
        }
    } else {
        //auto ship placement
        randomPlacement(player1_ships);
        displayBoard(player1_ships);
    }
    randomPlacement(player2_ships);    //creates player 2 board
    displayBoard(player2_ships); //here to troubleshoot main game
    
    //Main Game Loop
    while (true) {

        int row;  //player guesses for a location
        char col;
        int col_int = 0;
        while (true) {          //loop so player can continue if they get a hit
            cout << endl << endl;
            displayBoard(player1_guesses);
            do {
                //ask Player1 for guess
                cout<<"Enter Guess(row, col): ";
                cin>>row>>col;
                col_int = char_to_int(col);      //convert character so it can be used as index in array
            } while (!valid_guess(player2_ships, row-1, col_int));

            if (hit(player2_ships, row-1, col_int)) {
                cout<<"That is a hit./n";
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
            }
        }
        
        
        
        break; //temp to avoid infinite loop;
        system("clear");
    }

    return 0;
}