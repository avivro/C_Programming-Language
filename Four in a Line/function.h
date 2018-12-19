#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define ROW_SIZE 6
#define COLUMN_SIZE 7
#define CHAR_PLAYER1 'X'
#define CHAR_PLAYER2 'O'
#define UNDOARR_SIZE ROW_SIZE*COLUMN_SIZE
#define VALIDINPIT_SIZE 10

/* casing function for Check function,
 * get matrix
 * output:print all element of the matrix in form gameboard;
 */
void printArr(char a[ROW_SIZE][COLUMN_SIZE]);

/*
 * get matrix and column_number
 * output:return if in column_number in gameboard is full ;
 */
bool fullColumn(char a[ROW_SIZE][COLUMN_SIZE],int column);

/*
 * get matrix
 * output:return if gameboard is full ;
 */
bool fullGameBoard(char a[ROW_SIZE][COLUMN_SIZE]);
/*
 * get matrix and column_number
 * output:return if in column_number in gameboard is empty ;
 */
bool emptyColumn(char a[ROW_SIZE][COLUMN_SIZE],int column);
/*
 * get matrix
 * output:return if gameboard is empty ;
 */
bool emptyGameBoard(char a[ROW_SIZE][COLUMN_SIZE]);
/*
 * casing function for ConsecutiveColumn4,ConsecutiveDiagonal4,ConsecutiveRow4;
 * get matrix, char_player, int lastRow and int lastColumn-know where to check the win game Conditions
 * output:return if player is wim ;
 */
bool Consecutive4(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn);

/*
 * get matrix, char_player, int lastRow and int lastColumn-know where to check the win game Conditions
 * output:return if Condition exist:4 consecutive same Characters in row;
 */
bool ConsecutiveRow4(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn);


/*
 * get matrix, char_player, int lastRow and int lastColumn-know where to check the win game Conditions
 * output:return if Condition exist:4 consecutive same Characters in column;
 */
bool ConsecutiveColumn4(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn);

/*casing function for ConsecutiveDiagonal4Right, ConsecutiveDiagonal4Left;
 * get matrix, char_player, int lastRow and int lastColumn-know where to check the win game Conditions
 * output:return if Condition exist:4 consecutive same Characters in diagonal line;
 */
bool ConsecutiveDiagonal4(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn);

/*
 * get matrix, char_player, int lastRow and int lastColumn-know where to check the win game Conditions
 * output:return if Condition exist:4 consecutive same Characters in diagonal line-dowun_right;
 */
bool ConsecutiveDiagonal4Right(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn);
/*
 * get matrix, char_player, int lastRow and int lastColumn-know where to check the win game Conditions
 * output:return if Condition exist:4 consecutive same characters in diagonal line-dowun_left;
 */
bool ConsecutiveDiagonal4Left(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn);

/*
 * get matrix and column_number
 * output:return the next empty place in gameboard from column_number
 if all the column is full return -1;
 */
int placingPlayerChoice(char a[ROW_SIZE][COLUMN_SIZE],int column);

/*
 * get matrix,column_number and char charplayer
 * output:with "placingPlayerChoice" the function set up of the player in the next empty place in gameboard from column_number;
 */
int placingPlayerChoice2(char a[ROW_SIZE][COLUMN_SIZE],int column,char charplayer);

/*
 * get matrix and char charplayer
 * output:the function will place the player_choice in gameboard in accordance to validInput and rules of the game;
 * extension: if payer choice '0' its meaning delete the last turn;
 */
void turn(char a[ROW_SIZE][COLUMN_SIZE],char charplayer);

/*
 * get string for input from player
 * output:the function will check if the string is valid its mean player_choice_column between 1 to 7;
 */
void validInput(char[VALIDINPIT_SIZE]);

/*from https://stackoverflow.com/questions/4235519/counting-number-of-occurrences-of-a-char-in-a-string-in-c
 * get str pointer and character
 * output: count the occurrences of  character in str;
 */
int count_characters(const char *str, char character);

/*
 * get matrix
 * output:the function delete the last turn(if payer choice '0');
 */
bool undoFunction(char a[ROW_SIZE][COLUMN_SIZE]);
