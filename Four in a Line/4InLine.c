#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "function.h"
#define ROW_SIZE 6
#define COLUMN_SIZE 7
#define CHAR_PLAYER1 'X'
#define CHAR_PLAYER2 'O'
#define UNDOARR_SIZE ROW_SIZE*COLUMN_SIZE
#define VALIDINPIT_SIZE 10

int count=0;
int undoArro[UNDOARR_SIZE]={0};

bool flagTurnX=true;
bool flagTurnO=false;
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	char matrix[ROW_SIZE][COLUMN_SIZE];
	for (int i = 0; i < ROW_SIZE; ++i){
		for (int j = 0; j < COLUMN_SIZE; ++j){
			matrix[i][j]=' ';}
	}
while(true){
		if(flagTurnX==true&&flagTurnO==false){
			turn(matrix,CHAR_PLAYER1);}
		if(flagTurnO==true&&flagTurnX==false){
			turn(matrix,CHAR_PLAYER2);}
	}
}
void printArr(char a[ROW_SIZE][COLUMN_SIZE]){
	printf("\n");
	for(int i = 0; i < ROW_SIZE;i++){
		for(int j = 0; j < COLUMN_SIZE; j++){
			printf("|%c",a[i][j]);
		}
		printf("|");
		printf("\n");
	}
	for (int k = 1;k <=COLUMN_SIZE; k++){
		printf(" %d",k);
	}
	printf("\n");
	printf("\n");
}
bool fullColumn(char a[ROW_SIZE][COLUMN_SIZE],int column)
{
	for(int i = 0; i < ROW_SIZE; i++){
		if(a[i][column]==' ') return false;
	}
	return true;
}

bool fullGameBoard(char a[ROW_SIZE][COLUMN_SIZE])
{
	for (int k =0;k <COLUMN_SIZE; k++){
		if(!(fullColumn(a,k))) return false;
	}
	return true;
}

bool emptyColumn(char a[ROW_SIZE][COLUMN_SIZE],int column)
{
	for(int i = 0; i < ROW_SIZE; i++){
		if(a[i][column]!=' ') return false;
	}
	return true;
}

bool emptyGameBoard(char a[ROW_SIZE][COLUMN_SIZE])
{
	for (int k =0;k <COLUMN_SIZE; k++){
		if(!(emptyColumn(a,k))) return false;
	}
	return true;
}

bool Consecutive4(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn)
{
	return(ConsecutiveRow4(a,playerCheck,lastRow,lastColumn)||ConsecutiveColumn4(a,playerCheck,lastRow,lastColumn)||ConsecutiveDiagonal4(a,playerCheck,lastRow,lastColumn));
}

bool ConsecutiveColumn4(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn)
{
	if(lastRow<=2&&a[lastRow+1][lastColumn]==playerCheck&&a[lastRow+2][lastColumn]==playerCheck&&a[lastRow+3][lastColumn]==playerCheck){
		printf("cc4");
		return true;
	}
	return false;
}

bool ConsecutiveRow4(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn)
{
	int count=1;
	int lastColumnIteration1=lastColumn,lastColumnIteration2=lastColumn;


	while( ++lastColumnIteration1<COLUMN_SIZE&&a[lastRow][lastColumnIteration1]==playerCheck){
		count++;
	}
	while(--lastColumnIteration2>=0&&COLUMN_SIZE&&a[lastRow][lastColumnIteration2]==playerCheck){
		count++;
	}
	if(count>=4){
		return true;
	}
	return false;
}

bool ConsecutiveDiagonal4(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn)
{
	return(ConsecutiveDiagonal4Right(a,playerCheck,lastRow,lastColumn)||ConsecutiveDiagonal4Left(a,playerCheck,lastRow,lastColumn));
}


bool ConsecutiveDiagonal4Right(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn)
{
	int count=1;
	int lastColumnIteration1=lastColumn,lastColumnIteration2=lastColumn;
	int lastRowIteration1=lastRow,lastRowIteration2=lastRow;

	while( ++lastColumnIteration1<COLUMN_SIZE&&++lastRowIteration1<ROW_SIZE&&a[lastRowIteration1][lastColumnIteration1]==playerCheck){
		count++;
	}

	while(--lastColumnIteration2>=0&&--lastRowIteration2>=0&&a[lastRowIteration2][lastColumnIteration2]==playerCheck){
		count++;
	}
	if(count>=4) return true;

	return false;
}

bool ConsecutiveDiagonal4Left(char a[ROW_SIZE][COLUMN_SIZE],char playerCheck,int lastRow,int lastColumn)
{
	int count=1;
	int lastColumnIteration1=lastColumn,lastColumnIteration2=lastColumn;
	int lastRowIteration1=lastRow,lastRowIteration2=lastRow;

	while( ++lastColumnIteration1<COLUMN_SIZE&&--lastRowIteration1<=0&&a[lastRowIteration1][lastColumnIteration1]==playerCheck){
		count++;
	}
	while(--lastColumnIteration2>=0&&++lastRowIteration2<ROW_SIZE&&a[lastRowIteration2][lastColumnIteration2]==playerCheck){
		count++;
	}
	if(count>=4)
	{
		return true;
	}
	return false;
}

int placingPlayerChoice(char a[ROW_SIZE][COLUMN_SIZE],int column)
{
	int iPlacing=ROW_SIZE-1;
	if(column<0||column>=COLUMN_SIZE) return -1;
	while(a[iPlacing][column]!=' '){
		iPlacing--;
		if(iPlacing<0) return -1;
	}
	return iPlacing;
}

int placingPlayerChoice2(char a[ROW_SIZE][COLUMN_SIZE],int column,char charplayer)
{
	int ppc=placingPlayerChoice(a,column);
	if(ppc<0) return -1;
	a[ppc][column]=charplayer;
	undoArro[count]=column;
	count++;
	return ppc;
}

void turn(char a[ROW_SIZE][COLUMN_SIZE],char charplayer)
{

	int playerChoice;
	int placingChoice;
	int validInputChoice;
	char input[VALIDINPIT_SIZE];

	do {
		printArr(a);
		printf("Player %c, please enter a column number (or 0 to undo):\n",charplayer);
		scanf("%s",&input);
		validInputChoice=inputValid(input);
		if(validInputChoice==0){
			printf("input is : %s\n",input);
			printf("Invalid input, bye-bye! \n");
			exit(1);
		}
		playerChoice=input[0]-'0'-1;
		if(validInputChoice==1){
			placingChoice=placingPlayerChoice2(a,playerChoice,charplayer);
			printArr(a);
			printf("Invalid input, bye-bye! \n");
			exit(1);
		}
		if(validInputChoice==4){
			printf("Invalid input, the number must be between 1 to 7:\n");
			playerChoice=-1;
		}
		else if(validInputChoice==2)
		{
			bool uF=undoFunction(a);
			if(uF==false){
				printf("Board is empty - can't undo!\n");
				placingChoice=-1;
			}
		}
		else{
			placingChoice=placingPlayerChoice2(a,playerChoice,charplayer);
			if(validInputChoice==3&&placingChoice<0){
				printf("Invalid input, this column is full. Please choose another one:\n");
			}
		}
	} while(placingChoice<0 );

	if(Consecutive4(a,charplayer,placingChoice,playerChoice)){
		printArr(a);
		printf(" Player %c wins!\n",charplayer);
		exit(1);
	}
	if(fullGameBoard(a)){
		printArr(a);
		printf("It's a tie! \n");
		exit(1);
	}

	if(charplayer==CHAR_PLAYER1)
	{
		flagTurnX=false;
		flagTurnO=true;
	}
	else{
		flagTurnO=false;
		flagTurnX=true;
	}
}


int inputValid(char input[VALIDINPIT_SIZE])
{
	int strLenInput=strlen(input);
	int option1=count_characters(input,'.');
	if(isdigit(input[0])&&option1==1&&input[1]=='.') return 1;
	if(strLenInput==1&&input[0]-'0'==0) return 2;
	if(strLenInput==1&&input[0]-'0'>=1&&input[0]-'0'<=COLUMN_SIZE) return 3;
	{
		int i=-1;
		while(++i<strLenInput){
			if(!isdigit(input[i])) return 0;
		}
		return 4;
	}
	return 0;
}

int count_characters(const char *str, char character)
{
	const char *p = str;
	int count = 0;

	do {
		if (*p == character)
			count++;
	} while (*(p++));

	return count;
}
bool undoFunction(char a[ROW_SIZE][COLUMN_SIZE])
{
	if(count==0||emptyGameBoard(a)) return false;
	int lastColumn=undoArro[--count];
	int lastRow=placingPlayerChoice(a,lastColumn);
	if(lastRow==-1)lastRow=-1;
	++lastRow;
	a[lastRow][lastColumn]=' ';
	return true;
}
