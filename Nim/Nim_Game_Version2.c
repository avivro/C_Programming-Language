
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions_Version2.h"


int flag; /* flag=0 computer starts,flag=1 users starts */
int* num1=NULL;
int* num2=NULL;
int* num3=NULL;

int main(void){
	int x,y,z;
	num1=&x;
	num2=&y;
	num3=&z;
	bool gameOver=false;

	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Please enter 3 numbers without strings:\n");

	while((scanf("%d %d %d",&x,&y,&z)!=3 )||*num1<0||*num2<0||*num3<0 )
	{
		printf("Please enter 3 Positive numbers without strings!!! \n");
		while(getchar() != '\n');
		setvbuf(stdout, NULL, _IONBF, 0);
	}
	PrintPackest();

	if(*num1==1&&*num2==1&&*num3==1) flag=0;
	if(SumOf2(*num1,*num2,*num3)==1) flag=1;
	if(Option6()==1) flag=0; /// for computer win always
	if(Option7()==1) flag=0; /// for computer win always*/

	printf("flag is:%d \n",flag);

	if(flag==0) printf("computer start\n");
	else printf("you start\n");

	while(!(gameOver=GameOver()))
	{
		switch(flag)
		{
		case 0: /// computer
			turnComputer();
			break;

		case 1:/// user
			turnUser();
			break;
		}
	}

	PrintPackest();
	if(flag==1) printf("Game Over - You Lost !! ");
	else printf("you win");
	return 0;
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

bool GameOver()
{
	if(*num1+*num2+*num3==1) return true;
	return false;
}

void PrintPackest()
{
	printf("packet 1 | packet 2 | packet 3:\n");
	printf("   %d         %d          %d\n",*num1,*num2,*num3);
	printf("\n");
}

void turnComputer()
{
	sort();
	PrintPackest();
	int before=*num3;
	if(Option1(*num1,*num2,*num3))
	{
		*num3=1;
	}
	if(Option2())
	{
		*num3=0;
	}
	else if(Option3())
	{
		*num3=1;
	}
	else if(Option4())
	{
		*num3=0;
	}
	else if(Option5())
	{
		*num3=0;
	}
	else if(Option6())
	{
		*num3=0;
	}
	else if(Option7())
	{
		*num3=1;
	}
	else
	{
		*num3=(*num2)-(*num1);

	}

	printf("i turned %d to %d\n",before,*num3);
	flag=1;
}

void turnUser()
{
	sort();
	int PacketToChange=0,change=-1;
	PrintPackest();
	printf("Please chose Packet To Change:\n");

	while(scanf("%d",&PacketToChange)!=1||!(ProperInputPacketToChange(PacketToChange)))
	{
		printf("wrong!! Please chose again Packet To Change:\n");
		while(getchar() != '\n');

	}
	printf("to\n");


	while(scanf("%d",&change)!=1||!(UserPacketChange(PacketToChange,change)))
	{

		printf("wrong!! Please enter again:\n");
		while(getchar() != '\n');
		printf("packet %d ",PacketToChange);
		printf("to\n");

	}
	flag=0;
}

bool UserPacketChange(int PacketToChange,int change)
{
	if(change<0)
	{
		printf("you chose change<0!!!\n");
		return false;
	}
	if (PacketToChange==1)
	{
		if(*num1>change)
		{
			*num1=change;
			return true;
		}
		printf("your number is>=%d \n",*num1);
		return false;
	}
	if (PacketToChange==2)
	{
		if(*num2>change)
		{
			*num2=change;
			return true;
		}
		printf("your number is>=%d \n",*num2);
		return false;
	}
	if (PacketToChange==3)
	{
		if(*num3>change)
		{
			*num3=change;
			return true;
		}
		printf("your number is>=%d \n",*num1);
		return false;
	}

}

bool ProperInputPacketToChange(int PacketToChange)
{
	if(!(PacketToChange==1||PacketToChange==2||PacketToChange==3)) return false;
	if(PacketToChange==1&&*num1==0){
		printf("PacketToChange is 0!!\n");
				return false;
	}
	if(PacketToChange==2&&*num2==0){
		printf("PacketToChange is 0!!\n");
				return false;
	}
	if(PacketToChange==3&&*num3==0){
		printf("PacketToChange is 0!!\n");
				return false;
	}

	return true;
}


int SumOf2()
{
	if(*num1+*num2==*num3||*num1+*num3==*num2||*num2+*num3==*num1) return 1;
	return 0;
}

bool Option1(int x, int y,int z) /// x 0 0 //
{
	if((x==0&&y==0&&z>1)||(x==0&&y>1&&z==0)||(x>1&&y==0&&z==0)) return 1;
	return 0;
}
bool Option2(int x, int y,int z)  /// x 1 0
{
	if((x>1&&y==1&&z==0)||(x>0&&y==0&&z==1)||(x==1&&y==0&&z>1)||(x==1&&y>1&&z==0)||(x==0&&y==1&&z>1)||(x==0&&y>1&&z==1)) return 1;
	return 0;
}
bool Option3(int x, int y,int z) /// x 1 1
{

	if((x>1&&y==1&&z==1)||(x==1&&y>1&&z==1)||(x==1&&y==1&&z>1)) return 1;
	return 0;
}
bool Option4(int x, int y,int z) /// 0 1 1
{

	if((x==0&&y==1&&z==1)||(x==1&&y==0&&z==1)||(x==0&&y==1&&z==1)) return 1;
	return 0;
}

bool Option5(int x, int y,int z) /// x x y x>y
{

	if((x==y&&z!=x&&x>z)||(x==z&&x!=y&&x>y)||(x!=y&&y==z&&y>x)) return 1;
	return 0;
}
bool Option6(int x, int y,int z) /// x x y x<y
{

	if((x==y&&z!=x&&x<z)||(x==z&&x!=y&&x<y)||(x!=y&&y==z&&y<x)) return 1;
	return 0;
}
bool Option7(int x, int y,int z) /* 2 3 x | x>3 */
{

	if((x==2&&y==3&&z>3)||(x==2&&y>3&&z==3)||(x==3&&y==2&&z>3)||(x==3&&y>3&&z==2)||(x>3&&y==3&&z==2)||(x>2&&y==2&&z==3)) return 1;
	return 0;
}

void sort()
{
	int temp1=*num1;
	int	temp2=*num2;
	if(*num1>*num2){
		if(*num2>*num3){
			*num1=*num3;
			*num3=temp1;
		}
		else{
			if(*num1>*num3){
				*num2=*num3;
				*num1=temp2;
				*num3=temp1;
			}
		}
	}
	else{
		if(*num1>*num3)
		{
			*num1=*num3;
			*num2=temp1;
			*num3=temp2;
		}
		else{
			if(*num2>*num3)
			{
				*num2=*num3;
				*num3=temp2;
			}
		}

	}
}

