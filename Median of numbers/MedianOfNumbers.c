#include <stdio.h>
#include <stdlib.h>


int count=0;
int* a;


/*
 * get number and add him to array(on dynamic heap)
 *
 */
void Insert(int num)
{

	count++;
	if(count==1)  a=(int*)malloc(count*sizeof(int));
	else
	{
		a=(int*)realloc(a,count*sizeof(int));
	}
	*(a+count-1)=num;
}


/**
 * https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
 */
int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

void sort(int* a,int size){
	qsort(a, size, sizeof(int), cmpfunc);
}
void PrintPointer(const int* head)
{
	int countfun=count;
	while(countfun>1&&head!=NULL)
	{
		printf("%d->",*head);
		head++;
		--countfun;
	}
	printf("%d",*head);
	printf("\n");
	printf("\n");
}


void FreePointer(int* head)
{
	int* p;
	while(head!=NULL)
	{
		p=head;
		head=head+1;
		free(p);
	}
}

int take2(int num)
{
	int mid;

	Insert(num);
	sort(a,count);
	if(count%2==0) mid=a[(count/2)-1];

	else mid=a[count/2];
	printf("mid is : %d\n",mid);
	return mid;
}



int main(void){
	printf("start\n");
	printf("add 20\n");
	take2(20);
	PrintPointer(a);
	printf("add 10\n");
	take2(10);
	PrintPointer(a);
	printf("add 30\n");
	take2(30);
	PrintPointer(a);
	printf("add 5\n");
	take2(5);
	PrintPointer(a);
	printf("add 40\n");
	take2(40);
	PrintPointer(a);

	free(a);
	printf("free pinter\n");
	return 0;
}
