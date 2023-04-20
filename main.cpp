/**
 * @file main.cpp
 * @author Wade, Quinton, Mikayla
 * @brief 
 * @date 2023-03-22
 */

#include <cctype>
#include <ctime>
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

    ofstream file;
    file.open("battleship.log", std::ofstream::out | std::ofstream::trunc); //reset file state
    file.close();


    welcomeScreen(); //Welcomes Player and Displays Rules
    
    srand(time(0)); 

    char choice;

    //TODO: If the user mixes up the char and int input there is a problem
    bool placement = true;
    do{
        cout<<"Manual ship placement? (y/n): ";
        cin>>choice;
        if (choice == 'y') {
            displayBoard(player1_ships);
            manual_placement(player1_ships);
            
        } else if (choice == 'n') {
            //auto ship placement
            randomPlacement(player1_ships);
            cout<<"\nHere are your ships.\n";
            displayBoard(player1_ships);
        } else {
            cout << "Invalid input, please try again\n";
            placement = false;
        }
    } while (placement==false);
    randomPlacement(player2_ships);    //creates player 2 board

    //TODO - remove this when main loop is totally finished
    //displayBoard(player2_ships); //here to troubleshoot main game
      
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
            player_turn(player1_guesses,player2_ships, player, p2Ships, p2ShipIcons, player1_ships);
            
            player++;
        }
        //PLAYER 2
        else 
        {
            //cout<<endl<< "It is Player 2's turn.\n\n";
            
            player_turn(player2_guesses, player1_ships, player, p1Ships, p1ShipIcons, player1_ships);
           
            player--;
        }
        
    
        system("clear");
    }
    return 0;
}