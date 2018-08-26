
#include <stdio.h>
#include <stdlib.h>


typedef struct _Node{
	int data;
	struct Node* next;
}Node;

Node* InsertFirst(int data,Node* next)
{
	Node* p=malloc(sizeof(Node));
	if(p==NULL) exit(1);

	p->data=data;
	p->next=next;
	return p;
}

void deletFirst(Node** n)
{
	if(*n==NULL) return;
	Node* p=*n;
	*n=p->next;
	/*	*n=(*n)->next;*/
	free(p);
}

Node* deletFirst2(Node* n)
{
	if(n==NULL) return n;
	Node* p=n;
	n=n->next;
	free(p);
	return n;
}

Node* newNode(int data,Node* next)
{
	Node* p=malloc(sizeof(Node));
	if(p==NULL) exit(1);

	p->data=data;
	p->next=next;
	return p;
}


void InsertLast(Node** n,int data)
{
	Node** p=n;
	while(*p!=NULL)
	{
		p=&((*p)->next);
	}
	*p=newNode(data,NULL);
}




void PrintList1(Node* head)
{
	Node* p=head;
	while(p!=NULL)
	{
		printf("data is:%d\n",p->data);
		p=p->next;

	}
}

void PrintList2(const Node* n)
{

	while(n!=NULL)
	{
		printf("%d->",n->data);
		n=n->next;
	}
	printf("\n");
}


void FreeList(Node* head)
{
	Node* p;
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		free(p);
	}
}

Node* cloneList(const Node* head)
{
	if(head==NULL) return NULL;
	Node* listCopy=(Node*)malloc(sizeof(Node));
	if(listCopy==NULL) exit(1);
	listCopy->data=head->data;
	listCopy->next=cloneList(head->next);

	return listCopy;
}


int main(void) {
	Node* head=NULL;
	head=InsertFirst(3,head);
	head=InsertFirst(7,head);
	head=InsertFirst(8,head);
	head=InsertFirst(10,head);
	printf("original is: ");
	PrintList2(head);

	Node* list=cloneList(head);
	printf("clone is: ");
	PrintList2(list);
	printf("\n");

	head=InsertFirst(99,head);
	printf("original after insert 99 to original is: ");
	PrintList2(head);
	printf("clone after insert 99 to original is: ");
	PrintList2(list);
	printf("\n");

	list=InsertFirst(50,list);
	printf("original after insert 50 to clone is: ");
	PrintList2(head);
	printf("clone after insert 50 to clone is: ");
	PrintList2(list);
	printf("\n");

	InsertLast(&head,800);
	printf("original after insertLast 800 to original is: ");
	PrintList2(head);
	printf("clone after insertLast 800 to original is: ");
	PrintList2(list);

	printf("\n");
	InsertLast(&list,365);
	printf("original after insertLast 365 to clone is: ");
	PrintList2(head);
	printf("clone after insertLast 365 to clone is: ");
	PrintList2(list);

	FreeList(head);
	FreeList(list);
	return 0;
}
