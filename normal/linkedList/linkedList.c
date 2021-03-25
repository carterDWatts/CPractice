#include <stdlib.h>
#include <stdio.h>

#include "linkedList.h"
#include "node.h"


struct LinkedList* makeLinkedList() {
    struct LinkedList *ret = calloc(1, sizeof(*ret));
    return ret;
}
void clearLinkedList(struct LinkedList* ll){
    ll -> head = NULL;
    ll -> tail = NULL;
    ll -> size = 0;
}
void printLinkedList(struct LinkedList *ll){

    struct Node *cur = ll-> head;

    for(int i = 0; i < ll->size; i++){
        printNode(cur);
        printf(" -> ");
        cur = cur-> next;
    }

    printf("(Null)\n");

}

void linkedListAddNode(struct LinkedList *ll, struct Node *newNode){

    nodeAdd(ll, newNode);
}
void linkedListAdd(struct LinkedList *ll, double val){

    nodeAdd(ll, makeNode(val, NULL));
}

void linkedListAddArr(struct LinkedList *ll, int vals[], int size){

    for(int i = 0; i < size; i++){
        linkedListAdd(ll, vals[i]);
    }

}

void linkedListAddIndex(struct LinkedList *ll, double val, int index){

    //printf("linkedListAddIndex\n");

    if(index == 0){

        struct Node *oldHead = ll-> head;
        struct Node *newNode = makeNode(val, oldHead);
        ll-> head = newNode;
        ll-> size += 1;

    } else if (index > ll->size) {
        printf("Adding to index out of bounds");
        return;
    } else {
        linkedListAddIndexNode(ll, val, index, ll-> head);
    }

}
void linkedListAddIndexNode(struct LinkedList *ll, double val, int index, struct Node *node){

    //printf("linkedListAddIndexNode val: %f index: %d\n", val, index);

    if( index == 1 ){

        if (node->next != NULL){
            struct Node *newNode = makeNode(val, node);
            struct Node *later = node->next;

            node -> next = newNode;
            newNode -> next = later;

        }else{
            struct Node *newNode = makeNode(val, node);
            node-> next = newNode;
        }

        ll -> size += 1;

    } else {
        index--;
        node = node-> next;
        linkedListAddIndexNode(ll, val, index, node);
    }

}

void nodeAdd(struct LinkedList *ll, struct Node *newNode){

    if (ll->tail) {
        ll->tail->next = newNode;
        ll->tail = newNode;
        ll->size += 1;
    } else headAdd(ll, newNode);

}
void headAdd(struct LinkedList *ll, struct Node *newNode){

    ll -> head = newNode;
    ll -> size += 1;

    if (ll->size == 1) ll->tail = ll->head;

}

struct Node* linkedListGet(struct LinkedList *ll, int index){

    if (index >= ll->size) {
        return NULL;
    }

    struct Node *cur = ll-> head;

    while( index > 0){
        cur = cur-> next;
        index--;
    }

    return cur;
}

void linkedListDeleteIndex(struct LinkedList *ll, int index){

     if(index == 0){

         if (ll-> head-> next != NULL){
            ll-> head = ll->head->next;
         }else {
            ll-> head = NULL;
         }

         ll-> size -= 1;

     } else {
         linkedListDeleteIndexNode(ll, index, ll-> head);
     }

}
void linkedListDeleteIndexNode(struct LinkedList *ll, int index, struct Node *node){

     if( index == 0 ){

         if (node->next != NULL){
             node = node -> next;
         }else{
             node = NULL;
         }

         ll -> size -= 1;

     } else {
         index--;
         node = node-> next;
         linkedListDeleteIndexNode(ll, index, node);
     }

 }
