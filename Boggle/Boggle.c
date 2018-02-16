#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "function.h"
#define MATRIX_SIZE 4
#define true 1
#define false 0
#define STRING_SIZE MATRIX_SIZE*MATRIX_SIZE+1

/*
 *  solution use recursive depth-first search (DFS)
 */

int main(void) {

	char game[][MATRIX_SIZE]= {{'C','A','R','T'},{'E','T','A','K'},{'E','S','M','E'},{'L','L','P','N'}};
	printf("count of words is:%d\n",printWords(game));
	return 0;
}


int printWords(char game[MATRIX_SIZE][MATRIX_SIZE])
{
	int count=0,i,j;
	for (i = 0; i < MATRIX_SIZE; i++)
	{
		for (j = 0; j <MATRIX_SIZE; j++)
		{
			int  touch[MATRIX_SIZE][MATRIX_SIZE]={{0}};
			char word[STRING_SIZE];
			int INDEX_0=0; ///index of '\0'
			word[INDEX_0]=game[i][j];
			INDEX_0++;
			word[INDEX_0]='\0';
			printf("path start with character : %s\n",word);
			count+=Check(game,touch,word,i,j,INDEX_0);

		}

	}

	return count;
}

int Check(char game[MATRIX_SIZE][MATRIX_SIZE],int touch[MATRIX_SIZE][MATRIX_SIZE],char word[STRING_SIZE],int i,int j,int INDEX_0)
{
	int count=0;
	touch[i][j]=1;
	if((j+1<MATRIX_SIZE)&&(touch[i][j+1]==0)) ///1.same row next column
	{
		word[INDEX_0]=game[i][j+1];
		INDEX_0++;
		word[INDEX_0]='\0';
		if(isWord(word))
		{
			count++;
			printf("word:%s\n",word);

		}
		count+=Check(game,touch,word,i,j+1,INDEX_0);
		touch[i][j+1]=0;
		INDEX_0--;
		word[INDEX_0]='\0';


	}
	if((j-1>=0)&&(touch[i][j-1]==0)) ///2.same row previous column
	{
		word[INDEX_0]=game[i][j-1];
		INDEX_0++;
		word[INDEX_0]='\0';
		if(isWord(word))
		{
			count++;
			printf("word:%s\n",word);
		}
		count+=Check(game,touch,word,i,j-1,INDEX_0);
		touch[i][j-1]=0;
		INDEX_0--;
		word[INDEX_0]='\0';
	}

	if((i-1>=0)&&(touch[i-1][j]==0)) ///3.previous row same column
	{
		word[INDEX_0]=game[i-1][j];
		INDEX_0++;
		word[INDEX_0]='\0';
		/*	strncat(word, game[i-1][j], STRING_SIZE);*/

		if(isWord(word))
		{
			count++;
			printf("word:%s\n",word);
		}
		count+= Check(game,touch,word,i-1,j,INDEX_0);
		touch[i-1][j]=0;
		INDEX_0--;
		word[INDEX_0]='\0';
	}


	if((i+1<MATRIX_SIZE)&&(touch[i+1][j]==0)) /// 4.next row same column
	{
		word[INDEX_0]=game[i+1][j];
		INDEX_0++;
		word[INDEX_0]='\0';
		if(isWord(word))
		{
			count++;
			printf("word:%s\n",word);
		}
		count+=Check(game,touch,word,i+1,j,INDEX_0);
		touch[i+1][j]=0;
		INDEX_0--;
		word[INDEX_0]='\0';
	}

	return count;
}

void printArr(int a[MATRIX_SIZE][MATRIX_SIZE])
{
	printf("\n");
	for(int i = 0; i < MATRIX_SIZE; i++)
	{
		for(int j = 0; j < MATRIX_SIZE; j++)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
}

bool isWord(char* s)
{
	return(!strcmp(s,"CAT") |
			!strcmp(s,"CATS") |
			!strcmp(s,"TRAM") |
			!strcmp(s,"TRAMS") |
			!strcmp(s,"TAME") |
			!strcmp(s,"CAR") |
			!strcmp(s,"CARS") |
			!strcmp(s,"RAT") |
			!strcmp(s,"RATS") |
			!strcmp(s,"RAMP") |
			!strcmp(s,"ART") |
			!strcmp(s,"CART") |
			!strcmp(s,"STAMP") |
			!strcmp(s,"TAKEN") |
			!strcmp(s,"MEN") |
			!strcmp(s,"MAKE") |
			!strcmp(s,"TAKE") |
			!strcmp(s,"ATE") |
			!strcmp(s,"SELL") |
			!strcmp(s,"STEEL") |
			!strcmp(s,"RAKE") );
}
