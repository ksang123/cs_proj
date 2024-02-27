#include <stdio.h>
#include <stdbool.h>

#define MAX_COLS 7


// function declarations

void print_board(char board[][MAX_COLS], int rows, int cols);

int get_rows(void);

int get_columns(void);

int get_k(int rows, int cols);

void print_error_k(int correct_k);

void start_game(int rows, int cols, int k);

void reset_board(char board[][MAX_COLS], int rows, int cols);

bool check_win(char board[][MAX_COLS], int rows, int cols, char symbol);

int has_place(char board[][MAX_COLS], int rows, int col);

int get_input(char symbol, char board[][MAX_COLS], int rows, int cols);

void player_turn(char symbol, char board[][MAX_COLS], int rows, int cols);

bool has_ended(char board[][MAX_COLS], int rows, int cols,
               char symbol, int turns, int k);

bool is_draw(char board[][MAX_COLS], int rows, int cols);

bool is_win(char board[][MAX_COLS], int rows, int cols,
            char symbol, int turns, int k);

bool is_horizontal(char board[][MAX_COLS], int rows, int cols,
                   char symbol, int k);

bool is_vertical(char board[][MAX_COLS], int rows, int cols,
                 char symbol, int k);

bool is_diagonal_up(char board[][MAX_COLS], int rows, int cols,
                    char symbol, int k);

bool is_diagonal_down(char board[][MAX_COLS], int rows, int cols,
                      char symbol, int k);

int main(void) {
    int rows = get_rows();//get the rows of the board
    if (rows == -1) {//check that the amount of rows is valid
        return -1;
    }
    int cols = get_columns();//get the cols of the board
    if (cols == -1) {//check that the amount of cols is valid
        return -1;
    }
    int k = get_k(rows, cols);//get the k
    start_game(rows, cols, k);//call the function to manage the game
    return 0;
}

/** @return gets the amount of rows from the user */
int get_rows(void) {
    int rows;//get the rows from the user
    printf("Number of rows:\n");
    scanf("%d", &rows);
    if (rows > 7 || rows < 0) {//check that the amount of rows is valid
        printf("Error: Number of rows must be smaller than 8\n");
        return -1;
    }
    return rows;
}

/** @return gets the amount of cols from the user */
int get_columns(void) {
    int columns;//get the cols from the user
    printf("Number of columns:\n");
    scanf("%d", &columns);
    if (columns > 7 || columns <= 0) {//check that the amount of cols is valid
        printf("Error: Number of columns must be smaller than 8\n");
        return -1;
    }
    return columns;
}

/**
 * @param rows the rows in the board
 * @param cols the cols in the board
 * @return gets the k from the user */
int get_k(int rows, int cols) {
    int k;//get the k from the user
    printf("Please enter k:\n");
    scanf("%d", &k);
    if (k <= 0) {//check that the k is bigger than 0
        if (rows < cols) {//set k to the correct value
            k = rows;
            print_error_k(k);//print to the user
        } else {
            k = cols;
            print_error_k(k);//print to the user
        }
    }
    return k;
}

/** @param correct_k the new k
 * prints about changing k to the user*/
void print_error_k(int correct_k){
    printf("Error: k must be greater "
           "than zero, setting k to %d\n", correct_k);
}

/**
 * @param rows the rows in the board
 * @param cols the cols in the board
 * @param k the k in a row
 * the function manages a single game */
void start_game(int rows, int cols, int k) {
    int turns = 0;
    char symbol = 'Y';
    char board[MAX_COLS][MAX_COLS];
    reset_board(board, rows, cols);
    print_board(board, rows, cols);
    while (!has_ended(board, rows, cols, symbol, turns, k)) {
        player_turn(symbol, board, rows, cols);
        symbol = symbol == 'Y' ? 'X' : 'Y';
        print_board(board, rows, cols);
        turns++;
    }
}

/**
 * @param board the board of the game
 * @param rows the rows in the board
 * @param cols the cols in the board
 * @param symbol the symbol of the current player
 * @param turns the amount of turns taken so far
 * @param k the k in a row
 * @return returns true if the game ended and false otherwise */
bool has_ended(char board[][MAX_COLS], int rows, int cols,
               char symbol, int turns, int k) {
    //switch the symbol to the last player's turn
    symbol = symbol == 'Y' ? 'X' : 'Y';
    //check if there is a win or a draw
    return is_draw(board, rows, cols) ||
           is_win(board, rows, cols, symbol, turns, k);
}

/**
 * @param board the board of the game
 * @param rows the rows in the board
 * @param cols the cols in the board
 * the function resets the board to be all empty */
void reset_board(char board[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = ' ';
        }
    }
}

/**
 * @param symbol the symbol of the player who's turn it is
 * @param board the board of the game
 * @param rows the rows in the board
 * @param cols the cols in the board
 * the function places a single coin for the player */
void player_turn(char symbol, char board[][MAX_COLS], int rows, int cols) {
    int col = get_input(symbol, board, rows, cols); //get input from the player
    while (col == -1) { //validate the input
        col = get_input(symbol, board, rows, cols);
    }
    int row = has_place(board, rows, col); //get the lowest row for the coin
    board[row][col] = symbol; //place the coin
}

/**
 * @param symbol the symbol of the player who's turn it is
 * @param board the board of the game
 * @param rows the rows in the board
 * @param cols the cols in the board
 * the function gets a valid column from the player
 * @return return the column or -1 if the column is invalid */
int get_input(char symbol, char board[][MAX_COLS], int rows, int cols) {
    int col; //get a column from the player
    printf("Player %c, enter col:\n", symbol);
    scanf("%d", &col);
    if (col < 0 || col >= cols) { //check that the column is valid
        printf("Invalid input, try again\n");
        return -1;
    }
    //check that there is available place in the column
    if (has_place(board, rows, col) == -1) {
        printf("Column is full, try again\n");
        return -1;
    }
    return col;
}

/**
 * @param board the board of the game
 * @param rows the rows in the board
 * @param col the col that the player chose on the board
 * the function checks if theres a valid place in the column
 * @return return the row or -1 if the column is full */
int has_place(char board[][MAX_COLS], int rows, int col) {
    //iterate over every row from bottom to top
    for (int i = rows; i >= 0; i--) {
        if (board[i][col] == ' ') { //check if the spot is empty
            return i;
        }
    }
    return -1;
}

/**
 * @param board the board of the game
 * @param rows the rows in the board
 * @param cols the cols in the board
 * the function prints the board */
void print_board(char board[][MAX_COLS], int rows, int cols) {
    //print the board in the following format:
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("|");
        for (int j = 0; j < cols; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
    }
}

/**
 * @param board the board of the game
 * @param rows the rows in the board
 * @param cols the cols in the board
 * @return the function returns true if the game is a draw
 * and false otherwise */
bool is_draw(char board[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i <= cols; i++) { //iterate over every column
        if (has_place(board, rows, i) != -1) { //check if it's full or not
            return false;
        }
    }
    printf("DRAW!\n");
    return true;
}

/**
 * @param board the board of the game
 * @param rows the rows in the board
 * @param cols the cols in the board
 * @param symbol the symbol of the player who's turn it is
 * @param turns the amount of turns taken so far
 * @param k the k in a row
 * @return the function returns true if the game is won
 * and false otherwise */
bool is_win(char board[][MAX_COLS], int rows, int cols,
            char symbol, int turns, int k) {
    if (is_horizontal(board, rows, cols, symbol, k) ||
        is_vertical(board, rows, cols, symbol, k) ||
        is_diagonal_up(board, rows, cols, symbol, k) ||
        is_diagonal_down(board, rows, cols, symbol, k)) {
        printf("Player %c won in %d moves!\n", symbol, turns);
        return true;
    }
    return false;
}

/**
 * @param board the board of the game
 * @param rows the rows in the board
 * @param cols the cols in the board
 * @param symbol the symbol of the player who's turn it is
 * @param k the k in a row
 * @return the function returns true if the game is won horizontally
 * and false otherwise */
bool is_horizontal(char board[][MAX_COLS], int rows, int cols,
                   char symbol, int k) {
    for (int i = 0; i < rows; i++) {
        //a loop for every column you can start a winning streak from
        for (int j = 0; j <= cols - k; j++) {
            bool is_win = true;//true until proven else
            //a loop for every item in the streak
            for (int h = j; h < j + k; h++) {
                if (board[i][h] != symbol) {
                    is_win = false;
                }
            }
            if (is_win) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @param board the board of the game
 * @param rows the rows in the board
 * @param cols the cols in the board
 * @param symbol the symbol of the player who's turn it is
 * @param k the k in a row
 * @return the function returns true if the game is won vertically
 * and false otherwise */
bool is_vertical(char board[][MAX_COLS], int rows, int cols,
                 char symbol, int k) {
    for (int i = 0; i < cols; i++) { //a loop for every column
        //a loop for every row you can start a winning streak from
        for (int j = 0; j <= rows - k; j++) {
            bool is_win = true;//true until proven else
            //a loop for every item in the streak
            for (int h = j; h < j + k; h++) {
                if (board[h][i] != symbol) {
                    is_win = false;
                }
            }
            if (is_win) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @param board the board of the game
 * @param rows the rows in the board
 * @param cols the cols in the board
 * @param symbol the symbol of the player who's turn it is
 * @param k the k in a row
 * @return the function returns true if the game is won diagonally (up)
 * and false otherwise */
bool is_diagonal_up(char board[][MAX_COLS], int rows, int cols,
                    char symbol, int k) {
    //a loop for every row you can start a winning streak from
    for (int i = 0; i <= rows - k; i++) {
        //a loop for every column you can start a winning streak from
        for (int j = cols - 1; j <= k; j++) {
            bool is_win = true;//true until proven else
            //a loop for every item in the streak
            for (int h = 0; h < k; h++) {
                if (board[i + h][j - h] != symbol) {
                    is_win = false;
                }
            }
            if (is_win) {
                return true;
            }
        }
    }
    return false;
}

/**
 * @param board the board of the game
 * @param rows the rows in the board
 * @param cols the cols in the board
 * @param symbol the symbol of the player who's turn it is
 * @param k the k in a row
 * @return the function returns true if the game is won diagonally (down)
 * and false otherwise */
bool is_diagonal_down(char board[][MAX_COLS], int rows, int cols,
                      char symbol, int k) {
    //a loop for every row you can start a winning streak from
    for (int i = 0; i <= rows - k; i++) {
        //a loop for every column you can start a winning streak from
        for (int j = 0; j <= cols - k; j++) {
            bool is_win = true;//true until proven else
            //a loop for every item in the streak
            for (int h = 0; h < k; h++) {
                if (board[i + h][j + h] != symbol) {
                    is_win = false;
                }
            }
            if (is_win) {
                return true;
            }
        }
    }
    return false;
}
