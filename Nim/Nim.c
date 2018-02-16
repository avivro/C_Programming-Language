/*
 ============================================================================
 Name        : Hw1.c
 Author      : aviv 307974162
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Hw1.h"
#define MANY 100
#include <ctype.h>


int main()
{

	int num1,num2,num3,PacketToChange,change,flag=0; /* flag=0 computer starts,flag=1 users starts */
	char name[MANY];


	setvbuf(stdout, NULL, _IONBF, 0); /* C/C++ printf() before scanf() issue from stackoverflow */




	printf("Please enter your name:\n");
	scanf("%s",&name);
	printf("your name: %s\n",name);
	/*setvbuf(stdout, NULL, _IONBF, 0);*/
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);

	printf("Please enter 3 numbers without strings:\n");
	while((scanf("%d%d%d",&num1,&num2,&num3)!=3 )||num1<0||num2<0||num3<0 ) ////Scanf("%d%d%d",&num1,&num2,&num3)<3)
	{
		printf("Please enter 3 Positive numbers without strings!!! \n");
		while(getchar() != '\n');
		setvbuf(stdout, NULL, _IONBF, 0);

	}
	printf("Packet sizes are: %d,%d,%d\n",num1,num2,num3);




	if(num1==1&&num2==1&&num3==1) flag=0;
	if(SumOf2(num1,num2,num3)==1) flag=1;
	if(Option6(num1, num2,num3)==1) flag=0; /// for computer win always
	if(Option7(num1, num2,num3)==1) flag=0; /// for computer win always*/

	if(flag==0) printf("computer start\n");
	else printf("%s start\n",name);

	while(num1+num2+num3>1)
	{


		switch(flag)
		{
		case 0: /// computer
			printf("Packet sizes are: %d,%d,%d\n",num1,num2,num3);
			if(Option1(num1, num2,num3)==1)
			{
				PacketToChange=Big(num1,num2,num3);
				change=1;
			}
			if(Option2(num1, num2,num3)==1)
			{
				PacketToChange=Big(num1,num2,num3);
				change=0;
			}
			else if(Option3(num1, num2,num3)==1)
			{
				PacketToChange=Big(num1,num2,num3);
				change=1;
			}
			else if(Option4(num1, num2,num3)==1)
			{
				PacketToChange=Big(num1,num2,num3);
				change=0;
			}
			else if(Option5(num1, num2,num3)==1)
			{
				PacketToChange=Small(num1,num2,num3);
				change=0;
			}
			else if(Option6(num1, num2,num3)==1)
			{
				PacketToChange=Big(num1,num2,num3);
				change=0;
			}
			else if(Option7(num1, num2,num3)==1)
			{
				PacketToChange=Big(num1,num2,num3);
				change=1;
			}
			else
			{
				PacketToChange=Big(num1,num2,num3);
				change=Mid(num1,num2,num3)-Small(num1,num2,num3);
			}

			printf("i turned %d to %d\n",PacketToChange,change);
			if(num1==PacketToChange) num1=change;
			else {
				if(num2==PacketToChange) num2=change;
				else  num3=change;
			}
			flag=1;
			break;

		case 1:/// user
			printf("Packet sizes are: %d,%d,%d\n",num1,num2,num3);
			printf("Please state how much to take:\n");

			while(scanf("%d",&PacketToChange)!=1||PacketToChange!=num1&&PacketToChange!=num2&&PacketToChange!=num3)
			{
				printf("wrong!! Please state how much to take:\n");
				while(getchar() != '\n');

			}
			printf("to\n");


			while(scanf("%d",&change)!=1||change>=PacketToChange|| change<0)
			{

				printf("wrong!! Please enter number>=0 and number<%d:\n",PacketToChange);
				while(getchar() != '\n');
				printf("%d ",PacketToChange);
				printf("to\n");

			}
			if(PacketToChange==num1) num1=change;
			else
			{
				if(PacketToChange==num2) num2=change;
				else num3=change;
			}

			flag=0;
			break;
		}
	}
	printf("Packet sizes are: %d,%d,%d\n",num1,num2,num3);
	if(flag==1) printf("Game Over - You Lost !! ");
	else printf("%s win",name);


	return 0;

}


int Big(int x,int y,int z) /// function return the biggest number
{
	if(x>y)
	{
		if(z>x) return z;
		return x;
	}
	else
	{
		if(z>y)return z;
		return y;
	}
}

int Mid(int x,int y,int z) /// function return the mid number
{

	if(x>y)
	{
		if(z>x) return x;
		else
		{
			if(y>z) return y;
			else return z;
		}
	}
	else
	{
		if(z>y)return y;
		else{
			if(z>x) return z;
			else return x;
		}
	}
}
int Small(int x,int y,int z) /// function return the smallest number
{
	if(x<y)
	{
		if(z>y ) return x;
		else
		{
			if(x<z)return x;
			else return z;
		}
	}
	else
	{
		if(z>x)return y;
		else
		{
			if(y<z)return y;
			else return z;

		}
	}
}

int SumOf2(int num1,int num2, int num3)
{
	if(num1+num2==num3||num1+num3==num2||num2+num3==num1) return 1;
	return 0;
}

int Option1(int x, int y,int z) /// x 0 0 //
{
	if((x==0&&y==0&&z>1)||(x==0&&y>1&&z==0)||(x>1&&y==0&&z==0)) return 1;
	return 0;
}
int Option2(int x, int y,int z)  /// x 1 0
{
	if((x>1&&y==1&&z==0)||(x>0&&y==0&&z==1)||(x==1&&y==0&&z>1)||(x==1&&y>1&&z==0)||(x==0&&y==1&&z>1)||(x==0&&y>1&&z==1)) return 1;
	return 0;
}
int Option3(int x, int y,int z) /// x 1 1
{

	if((x>1&&y==1&&z==1)||(x==1&&y>1&&z==1)||(x==1&&y==1&&z>1)) return 1;
	return 0;
}
int Option4(int x, int y,int z) /// 0 1 1
{

	if((x==0&&y==1&&z==1)||(x==1&&y==0&&z==1)||(x==0&&y==1&&z==1)) return 1;
	return 0;
}

int Option5(int x, int y,int z) /// x x y x>y
{

	if((x==y&&z!=x&&x>z)||(x==z&&x!=y&&x>y)||(x!=y&&y==z&&y>x)) return 1;
	return 0;
}
int Option6(int x, int y,int z) /// x x y x<y
{

	if((x==y&&z!=x&&x<z)||(x==z&&x!=y&&x<y)||(x!=y&&y==z&&y<x)) return 1;
	return 0;
}
int Option7(int x, int y,int z) /* 2 3 x | x>3 */
{

	if((x==2&&y==3&&z>3)||(x==2&&y>3&&z==3)||(x==3&&y==2&&z>3)||(x==3&&y>3&&z==2)||(x>3&&y==3&&z==2)||(x>2&&y==2&&z==3)) return 1;
	return 0;
}




