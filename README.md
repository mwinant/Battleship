# Battleship

## Overview

C++ program that simulates the game of [Battleship](http://en.wikipedia.org/wiki/Battleship_(game)). Battleship is a two-player Navy game. The objective of the game is to sink all ships in your enemy's fleet. The Player to sink his/her enemy's fleet first wins.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src="https://sc01.alicdn.com/kf/HTB1A.E9e5LaK1RjSZFxq6ymPFXa3.jpg" width="350" />

Try playing the online version of the game here https://www.battleshiponline.org/

Both players' fleets consist of 5 ships that are hidden from the enemy. Each ship may be differentiated by its "size" (besides the Cruiser and Submarine) or number of cells it expands on the game board:
1. Carrier has 5 cells
2. Battleship has 4 cells
3. Cruiser has 3 cells
4. Submarine has 3 cells
5. Destroyer has 2 cells.
The program should be built such that the user is Player1 and the computer is Player2. 

For more information about the rules of Battleship visit: [Rules of Battleship](https://www.hasbro.com/common/instruct/Battleship.PDF).

## Program Details

- [ ] **Two boards** (2-dimensional arrays of chars) exist within the game. 
    * Each 2-dimensional array should be 10 X 10. 
    * One represents Player1's board and one represents Player2's board. 
- [ ] At the beginning of the game, each Players' game board should be initialized to all dashes `-` indicating that no ships have been placed on either board.
- [ ] Before the game starts, Player1 should have the option to either:
    - [ ] manually place each of the 5 ships in his/her fleet or 
    - [ ] to have them randomly placed on the board. 
    - If Player1 decides to place the ships manually, then he/she should be prompted to place the Carrier first, Battleship second, Cruiser third, Submarine fourth, and the Destroyer last. 
    - **Note:** Ships cannot be placed diagonally on the board, they can *only be placed vertically or horizontally* (you don't need to check for this); 
    - [ ] **Validate** if the user tries to place a ship outside the boundaries of the board or on top of a ship that has already been placed.

Each cell on the board that contains part of the ship must be indicated by 
* `c` for Carrier, 
* `b` for Battleship, 
* `r` for Cruiser, 
* `s` for Submarine, or 
* `d` for Destroyer. 

For example, if the Carrier was placed then the board should contain 5 `c` for each cell on the board that has a piece of the Carrier, etc. 

### Sample Run
The following sample session demonstrates how your program should work (user input is shown in bold).
<pre>
***** Welcome to Battleship! *****

Rules of the Game:
1. This is a two player game.
2. Player1 is you and Player2 is the computer.
3. Etc. (You need to list the rest of the rules here.)

Hit enter to start the game!

<Enter>

<clear the screen>

Please select from the following menu:
1. Enter positions of ships manually.
2. Allow the program to randomly select positions of ships.

Menu choice: 1

Please enter start row and column to place the Carrier: <strong>0 2</strong>
Place it in [0] horizontal or [1] vertical: <strong>0</strong>

Please enter start row and column to place the Battleship: <strong>3 4</strong>
Place it in [0] horizontal or [1] vertical: <strong>1</strong>

Etc......

Player2 (Computer's) board has been generated.

Player1 has been randomly selected to go first.

Player1's Board:

    0 1 2 3 4 5 6 7 8 9
0   - - c c c c c - - -
1   d d - - - - - - - -
2   - - - - - - - - - s
3   - - - - b - - - - s
4   - - - - b - - - - s
5   - - - - b - - - - -
6   - - - - b - - - - -
7   - - - r r r - - - -
8   - - - - - - - - - -
9   - - - - - - - - - -

Player2's Board:

   0 1 2 3 4 5 6 7 8 9
0  - - - - - - - - - -
1  - - - - - - - - - -
2  - - - - - - - - - -
3  - - - - - - - - - -
4  - - - - - - - - - -
5  - - - - - - - - - -
6  - - - - - - - - - -
7  - - - - - - - - - -
8  - - - - - - - - - -
9  - - - - - - - - - -

Enter a target: <strong>2 3</strong>

(clear screen)

2,3 is a hit!

Player1's Board:

   0 1 2 3 4 5 6 7 8 9
0  - - c c c c c - - -
1  d d - - - - - - - -
2  - - - - - - - - - s
3  - - - - b - - - - s
4  - - - - b - - - - s
5  - - - - b - - - - -
6  - - - - b - - - - -
7  - - - r r r - - - -
8  - - - - - - - - - -
9  - - - - - - - - - -

Player2's Board:

   0 1 2 3 4 5 6 7 8 9
0  - - - - - - - - - -
1  - - - - - - - - - -
2  - - - * - - - - - -
3  - - - - - - - - - -
4  - - - - - - - - - -
5  - - - - - - - - - -
6  - - - - - - - - - -
7  - - - - - - - - - -
8  - - - - - - - - - -
9  - - - - - - - - - -

Player2 selects: <strong>9 9</strong>

9,9 is a miss!

Hit enter to continue!

Enter

(clear screen)

Player1's Board:

   0 1 2 3 4 5 6 7 8 9
0  - - c c c c c - - -
1  d d - - - - - - - -
2  - - - - - - - - - s
3  - - - - b - - - - s
4  - - - - b - - - - s
5  - - - - b - - - - -
6  - - - - b - - - - -
7  - - - r r r - - - -
8  - - - - - - - - - -
9  - - - - - - - - - m

Player2's Board:

   0 1 2 3 4 5 6 7 8 9
0  - - - - - - - - - -
1  - - - - - - - - - -
2  - - - * - - - - - -
3  - - - - - - - - - -
4  - - - - - - - - - -
5  - - - - - - - - - -
6  - - - - - - - - - -
7  - - - - - - - - - -
8  - - - - - - - - - -
9  - - - - - - - - - -

(etc…)

Player1 Wins!

Statistics outputted to logfile successfully!
</pre>
