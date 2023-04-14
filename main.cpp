/**
 * @file main.cpp
 * @author Wade, Quinton, Mikayla
 * @brief 
 * @date 2023-03-22
 */

#include <cctype>
#include <iostream>
#include "battleship.h"
using namespace std;

int main() 
{  
    /* 
    //ship number counts and icon arrays to validate if ships have sunk
    int p1Ships = 5;
    int p2Ships = 5;
    char p1ShipIcons[NUM_SHIPS] = {'c', 'b', 'r', 's', 'd'};
    char p2ShipIcons[NUM_SHIPS] = {'c', 'b', 'r', 's', 'd'};
    */

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

    //TODO: If the user mixes up the char and int input there is a problem
    bool placement = true;
    do{
        cout<<"Manual ship placement? (y/n): ";
        cin>>choice;
        if (choice == 'y') {
            displayBoard(player1_ships);
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
                            cout << "invalid\n";            //for start of next line, which would likely be invalid. this doesnt really matter
                            cin.clear();                    //, but it'd probably be cleaner with a getline function and some delim stuff.)
                            cin.sync();
                            cin.ignore();
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
                } while (correct!=true);  
                displayBoard(player1_ships); //displays where ship is placed
            }
        } else if (choice == 'n') {
            //auto ship placement
            randomPlacement(player1_ships);
            displayBoard(player1_ships);
        } else {
            cout << "Invalid input, please try again\n";
            placement = false;
        }
    } while (placement==false);
    randomPlacement(player2_ships);    //creates player 2 board

    //TODO - remove this when main loop is totally finished
    displayBoard(player2_ships); //here to troubleshoot main game
      
    //ship number counts and icon arrays to validate if ships have sunk
    int p1Ships = 5;
    int p2Ships = 5;
    char p1ShipIcons[NUM_SHIPS] = {'c', 'b', 'r', 's', 'd'};
    char p2ShipIcons[NUM_SHIPS] = {'c', 'b', 'r', 's', 'd'};

    int player = selectWhoStartsFirst();

    //Main Game Loop
    while (true) 
    {

        //PLAYER 1
        if (player==1)
        {
            player_turn(player1_guesses,player2_ships, player, p2Ships, p2ShipIcons);
            
            player++;
        }
        //PLAYER 2
        else 
        {
            cout<<endl<< "It is Player2's turn.\n";

            player_turn(player2_guesses, player1_ships, player, p1Ships, p1ShipIcons);
           
            player--;
        }
        
    
    }
    system("clear");
    return 0;
}