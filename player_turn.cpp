#include "battleship.h"

/**
 * @brief Controls what happens during a turn for both players
 * 
 * @param guesses       arrays relevant to each players turn are passed as parameters
 * @param ships 
 * @param player 
 * @param remaining_ships 
 * @param remaining_ship_icons 
 */
void player_turn(char guesses[NUM_ROWS][NUM_COLS], char ships[NUM_ROWS][NUM_COLS], int player, int &remaining_ships, char remaining_ship_icons[NUM_SHIPS])
{
    int row;  //player guesses for a location
    char col;
    int col_int = 0;

    displayBoard(guesses);
    while (true) {          //loop so player can continue if they get a hit
        cout << endl << endl;
        if (player==1) {
            do {
                //ask Player1 for guess
                cout<<"Enter Guess(row col): ";
                cin>>row>>col;
                col_int = char_to_int(col);      //convert character so it can be used as index in array
            } while (!valid_guess(guesses, row, col_int));
        } else {
            //player 2 guesses
            do {
                row = generateRandomRow();
                col = generateRandomCol();
                col_int = char_to_int(col);
            } while(!valid_guess(guesses, row, col_int));

        }

        if (hit(ships, row, col_int)) {
            cout<<"That is a hit.\n";
            //get the ship type that was just hit for use in checking for a sink
            //char ship_type = ships[row-1][col_int-1];
            update_boards(ships, guesses, HIT, row, col_int);
            displayBoard(guesses);
            
            hit_result(ships, remaining_ship_icons, remaining_ships);

            continue;  //allows player1 do go again if they hit
        } else {
            update_boards(ships, guesses, MISS, row, col_int);
            displayBoard(guesses);
            cout<<"That is a miss.\n"; 
            break;
        }
    }

}
/**
 * @brief Gets called if there is a hit, and checks for sink and win
 * 
 * @param ships 
 * @param remaining_ship_icons 
 * @param remaining_ships 
 */
void hit_result(char ships[NUM_ROWS][NUM_COLS], char remaining_ship_icons[NUM_SHIPS], int &remaining_ships)
{
    
    int sunk = sink(ships, remaining_ship_icons);

    if (sunk>-1) {
        //tell player they sunk the corresponding ship
        //TODO:Function that converts ship symbol to ship type or better way
        cout<<"You sunk their "<<SHIP_NAMES[sunk]<<endl;
        remaining_ships--;
    }
    if(remaining_ships==0){
        cout << "\nCongratulations! You win! You're a 5-Star Admiral!\n";
        exit(1);
    }
}