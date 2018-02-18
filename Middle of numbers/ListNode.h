
#ifndef LISTNODE_H_
#define LISTNODE_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct _Node{
	int data;
	struct Node* next;
}Node; ///sizeof(node)=12(4-int1+8-pointer)///


/*
 * get data ( number)
 * output:return pointer to Node with data ;
 */
Node* newNode(int data);

/*
 * get two nodes pointer
 * output:add new node to top of the list ;
 */
Node* InsertFirst(Node* head,Node* new);


/*
 * get two nodes pointer
 * output:add new node to end of the list ;
 */
void InsertLast(Node* head,Node* new);

/*
 * get head of list
 * output:print all the node of the list ;
 */
void PrintList(const Node* n);


/*
 * get head of list
 * output:remove the head of the list ;
 */
Node* deletFirst2(Node* n);


/*
 * get head of list
 * output:free all the dynamic memory of the heap ;
 */
void FreeList(Node* head);

#endif /* LISTNODE_H_ */
