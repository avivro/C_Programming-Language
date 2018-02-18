#include <stdio.h>
#include <stdlib.h>
#include "ListNode.h"

int countNodes=0;
Node* head;
Node* mid=NULL;

int take(int num)
{

	countNodes++;
	if(countNodes==1)
	{
		head=newNode(num);
		mid=head;
	}
	else
	{
		Node* new=newNode(num);
		InsertLast( head,new);
	}
	if(countNodes%2==0)
	{
		mid=mid->next;
	}
	printf("mid is: %d\n",mid->data);
	return mid->data;
}

int main(void){
	printf("start\n");
	take(20);
	PrintList(head);
	take(10);
	PrintList(head);
	take(30);
	PrintList(head);
	take(5);
	PrintList(head);
	take(40);
	PrintList(head);

	printf("free all the list\n");
	return 0;
}
