# COMP-120-capu-project1
Tic-Tac-Toe vs. the Computer

A terminal tic-tac-toe game written in C for COMP120 Project 1.

How to Play

First, you play as O and go first. Then The computer plays as X.

You enter a number from 0 to 8 to choose an empty square.

The computer randomly chooses an empty square.

If you get three matching symbols in a row, column, or diagonal you will win.

If the board is full and nobody wins, the game is a draw.

After each game, enter y to play again or q to quit.

To play you have to Compile with GCC using:

gcc -std=c11 -Wall -Wextra -pedantic tic_tac_toe.c -o tic_tac_toe 

After that run in terminal then Windows PowerShell:

.\tic_tac_toe.exe



Program Structure is a board is stored in a 1-dimensional char array with nine elements.

init_board: clears the board.

display_board: displays the board and available square numbers.

is_winner: checks the rows, columns, and diagonals.

other_player: switches between O and X.

get_human_move: asks for a valid move.

get_computer_move: randomly chooses an empty square.

take_turn: places the current player's symbol.

play_game: runs one game and reports the result.

play_again: asks whether to play another game.

The program uses bool, arrays, functions, and for, while, and do...while loops. It uses rand for computer moves and calls srand once at the start of main.

The program rejects invalid choices, including numbers outside 0–8, letters, multiple-character inputs, and occupied squares.

