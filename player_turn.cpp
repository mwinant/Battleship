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
    int player2turn = 0;
    int firstRow = 0;
    int firstCol = 0;
    Statistics stats;


    while (true) {          //loop so player can continue if they get a hit
        cout << endl << endl;
        if (player==1) {
            displayBoard(guesses);
            do {
                //ask Player1 for guess
                cout<<"Enter Guess(row col)\n";
                get_col_and_row(row, col);
                col_int = char_to_int(col);      //convert character so it can be used as index in array
                stats.p1Total++;
            } while (!valid_guess(guesses, row, col_int));
        } else {
            //player 2 guesses
            do {
                if (player2turn>1) { //if there has been more than one correct hit
                    if (firstRow==row) {
                        int pickSide = rand()%2; //randomly selects a side to hit
                        if(pickSide == 1 && col_int < 8 && col_int > 1){
                            col_int = col_int+(col_int-firstCol);
                        } else if (col_int == 1) {
                            col_int = firstCol+(firstCol-col_int);
                        }
                        row = firstRow;
                    } else {
                        int pickSide = rand()%2;
                        if(pickSide == 1 && row < 8 && row > 1){
                            row = row+(row-firstRow);
                        } else if (row == 1) {
                            row = firstRow+(firstRow-row);
                        }
                        col_int = firstCol;
                    }
                    player2turn++;
                } else if (player2turn>0) {
                    firstRow = row;
                    firstCol = col_int;
                    int rowOrCol = rand()%3; //randomly selects whether to pick different row or column
                    if (rowOrCol == 0) {
                        int side = rand()%3;
                        if(side != 1&&row>1){ //randomly selects side to hit
                            row = row-1; 
                        } else {
                            row = row+1;
                        }
                        col_int = firstCol;
                    } else {
                        int side = rand()%2;
                        if(side != 1&&col_int>1){ //randomly selects side to hit
                            col_int = col_int-1; 
                        } else {
                            col_int = col_int+1;
                        }
                        row = firstRow;
                    }
                    player2turn++;
                } else {
                row = generateRandomRow();
                col = generateRandomCol();
                col_int = char_to_int(col);
                player2turn++;
                }
                stats.p2Total++;
            } while(!valid_guess(guesses, row, col_int));
            cout<< "Player 2 guessed " << row << " "<< col << ".\n";
        }

        if (hit(ships, row, col_int)) {
            cout<<"That is a hit. Guess again.\n";
            ofstream file;
            outputTurnFile(file, row, col, player, "Hit");
            if (player == 1){
                stats.p1Hit++;
            } else {
                stats.p2Hit++;
            }
            //get the ship type that was just hit for use in checking for a sink
            //char ship_type = ships[row-1][col_int-1];
            update_boards(ships, guesses, HIT, row, col_int);
            cout<<endl;
            displayBoard(guesses);
            
            hit_result(ships, remaining_ship_icons, remaining_ships, player);

            continue;  //allows player1 do go again if they hit
        } else {
            ofstream file;
            outputTurnFile(file, row, col, player, "Miss");
            update_boards(ships, guesses, MISS, row, col_int);
            cout<<endl;
            displayBoard(guesses);
            cout<<"\nThat is a miss.\n"; 
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
void hit_result(char ships[NUM_ROWS][NUM_COLS], char remaining_ship_icons[NUM_SHIPS], int &remaining_ships, int player)
{
    Statistics stats;
    int sunk = sink(ships, remaining_ship_icons);

    if (sunk>-1) {
        ofstream file;
        //tell player they sunk the corresponding ship
        //TODO:Function that converts ship symbol to ship type or better way
        cout<<"You sunk their "<<SHIP_NAMES[sunk]<<endl;
        remaining_ships--;
        sinkToFile(file, sunk);
        if(player == 1){
            stats.p1ShipsSank++;
        } else {
            stats.p2ShipsSank++;
        }
    }
    if(remaining_ships==0){
        cout << "\nCongratulations! You win! You're a 5-Star Admiral!\n";
        stats.p1HitPercentage = 100.00*(static_cast<double>(stats.p1Hit)/static_cast<double>(stats.p1Total));
        stats.p2HitPercentage = 100.00*(static_cast<double>(stats.p2Hit)/static_cast<double>(stats.p2Total));
        ofstream file;
        outputStats(file);
        exit(1);
    }
}