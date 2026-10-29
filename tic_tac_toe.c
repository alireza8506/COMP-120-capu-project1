#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void init_board(char board[]) {
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}


void display_board(char board[]) {
    char c[9];

    for (int i = 0; i < 9; i++) {
        c[i] = board[i];
        if (c[i] == ' ') {
            c[i] = '0' + i;
        }
    }

    printf("\n %c | %c | %c\n", c[0], c[1], c[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[3], c[4], c[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n\n", c[6], c[7], c[8]);
}

bool is_winner(char board[], char player) {
    
    if (board[0] == player && board[1] == player && board[2] == player) {
        return true;
    }
    if (board[3] == player && board[4] == player && board[5] == player) {
        return true;
    }
    if (board[6] == player && board[7] == player && board[8] == player) {
        return true;
    }

    
    if (board[0] == player && board[3] == player && board[6] == player) {
        return true;
    }
    if (board[1] == player && board[4] == player && board[7] == player) {
        return true;
    }
    if (board[2] == player && board[5] == player && board[8] == player) {
        return true;
    }

    
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }
    return false;
}

char other_player(char player) {
    if (player == 'O') {
        return 'X';
    }
    return 'O';
}


int get_human_move(char board[]) {
    char input[100];
    int move = 0;
    bool valid = false;

    while (!valid) {
        printf("Your turn (O). Enter a square number (0-8): ");
        if (scanf("%99s", input) != 1) {
            return -1;
        }

        if (input[0] < '0' || input[0] > '8' || input[1] != '\0') {
            printf("Please enter one digit from 0 to 8.\n");
        } else {
            move = input[0] - '0';
            if (board[move] != ' ') {
                printf("That square is already taken.\n");
            } else {
                valid = true;
            }
        }
    }
    return move;
}

int get_computer_move(char board[]) {
    int move;
    do {
        move = rand() % 9;
    } while (board[move] != ' ');
    return move;
}

bool take_turn(char board[], char player) {
    int move;

    if (player == 'O') {
        move = get_human_move(board);
    } else {
        move = get_computer_move(board);
        printf("Computer (X) chose square %d.\n", move);
    }
    if (move == -1) {
        return false;
    }
    board[move] = player;
    return true;
}

void play_game(void) {
    char board[9];
    char player = 'O';
    bool game_over = false;

    init_board(board);
    display_board(board);

    for (int turn = 0; turn < 9 && !game_over; turn++) {
        if (!take_turn(board, player)) {
            return;
        }
        display_board(board);

        if (is_winner(board, player)) {
            if (player == 'O') {
                printf("You (O) won!\n");
            } else {
                printf("Computer (X) won!\n");
            }
            game_over = true;
        } else {
            player = other_player(player);
        }
    }

    if (!game_over) {
        printf("The game is a draw!\n");
    }
}

bool play_again(void) {
    char answer[100];
    bool valid = false;

    while (!valid) {
        printf("Play again (y) or quit (q): ");
        if (scanf("%99s", answer) != 1) {
            return false;
        }

        if ((answer[0] == 'y' || answer[0] == 'q') && answer[1] == '\0') {
            valid = true;
        } else {
            printf("Please enter y or q.\n");
        }
    }
    return answer[0] == 'y';
}

int main(void) {
    srand(time(NULL));

    printf("TIC-TAC-TOE vs COMPUTER\n");
    printf("You are O and you go first. The computer is X.\n");

    do {
        play_game();
    } while (play_again());

    printf("Thanks for playing!\n");
    return 0;
}
