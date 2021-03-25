#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "node.h"

struct LinkedList{
	struct Node *head;
	struct Node *tail;
	int size;
};

struct LinkedList* makeLinkedList();
void clearLinkedList(struct LinkedList* ll);
void printLinkedList(struct LinkedList *ll);

void linkedListAddNode(struct LinkedList *ll, struct Node *newNode);
void linkedListAdd(struct LinkedList *ll, double val);
void linkedListAddArr(struct LinkedList *ll, int vals[], int size);

void linkedListAddIndex(struct LinkedList *ll, double val, int index);
void linkedListAddIndexNode(struct LinkedList *ll, double val, int index, struct Node *node);

void nodeAdd(struct LinkedList *ll, struct Node *newNode);
void headAdd(struct LinkedList *ll, struct Node *newNode);

struct Node* linkedListGet(struct LinkedList *ll, int index);

void linkedListDeleteIndex(struct LinkedList *ll, int index);
void linkedListDeleteIndexNode(struct LinkedList *ll, int index, struct Node *node);
#endif
