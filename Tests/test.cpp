#include "battleship.h"
bool sink(const char board[NUM_ROWS][NUM_COLS], char shipIcons[NUM_SHIPS], int numShips) 
{
    int numOfShips = numShips;
    for(int i = 0; i < numOfShips; i++){
        cout << "Checking for " << shipIcons[i];
        for(int row = 0; row < NUM_ROWS; row++){
            for(int col = 0; col < NUM_COLS; col++){
                if(board[row][col] == shipIcons[i]){
                    cout << "iconFound\n";
                    goto SKIP;
                }
            }
        }
        shipIcons[i] = '*';
        return true;
        SKIP: cout<<"its found\n";
    }
    return false;
}

int main(){

    int numShips = 5;
    char p1ShipIcons[NUM_SHIPS] = {'c', 'b', 'r', 's', 'D'};
    char player1_ships[NUM_ROWS][NUM_COLS];
    initializeBoard(player1_ships);
        randomPlacement(player1_ships);    //creates player 2 board

    bool check = sink(player1_ships, p1ShipIcons, numShips);
    if (!check){
        cout << "False!!!|||";
    } else {
        cout << "TRUE!!!!|||";
    }
    return 0;
}

