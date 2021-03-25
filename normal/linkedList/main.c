#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"
#include "node.h"

int main(){
	
	printf("\nNode test\n");


    struct LinkedList *ll = makeLinkedList();
    struct Node* first = makeNode(1, NULL);


    // Adding values
    printf("Adding elements\n");
    linkedListAddNode(ll, first);
    linkedListAddNode(ll, makeNode(2, NULL));
    linkedListAdd(ll, 3);
    linkedListAddIndex(ll, 5, 3);
    linkedListAddIndex(ll, 4, 3);
    linkedListAddIndex(ll, 0, 0);
    printLinkedList(ll);


    // Removing Values
    printf("Removing elements\n");
    //linkedListDeleteIndex(ll, 0);
    linkedListDeleteIndex(ll, 5);
    linkedListDeleteIndex(ll, 3);
    printLinkedList(ll);

    // Clear list
    //clearLinkedList(ll);

    // Adding array of ints
    printf("Adding array of elements\n");
    int ints[] = {0, 1, 2, 3, 4};

    int size = sizeof(ints)/sizeof(ints[0]);
    linkedListAddArr(ll, ints, size);
    printLinkedList(ll);


	printf("\nEnd\n\n");

	return 0;

}
