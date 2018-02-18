/*
 ============================================================================
 Name        : ListNode.c
 Author      : aviv
 Version     :
 Copyright   : Your copyright notice
 ============================================================================
 */

#include "ListNode.h"

Node* newNode(int data)
{
	Node* new=malloc(sizeof(Node));
		if(new==NULL) exit(1);

		new->data=data;
		new->next=NULL;

		return new;
}

Node* InsertFirst(Node* head,Node* new)
{

	if(head==NULL) return NULL;


	new->next=head;
	return new;
}


void InsertLast(Node* head,Node* new)
{
	if(head!=NULL)
	{
		Node* p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=new;

	}

}

void PrintList(const Node* n)
{

	while(n->next!=NULL)
	{
		printf("%d->",n->data);
		n=n->next;
	}
	printf("%d",n->data);
	printf("\n");
	printf("\n");
}

Node* deletFirst2(Node* n)
{
	if(n==NULL) return n;
	Node* p=n;
	n=n->next;
	free(p);
	return n;
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

