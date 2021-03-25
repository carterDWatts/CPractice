#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct Node * makeNode(double val, struct Node * next){

    struct Node* ret = NULL;
    ret = (struct Node*)malloc(sizeof(struct Node));
    ret -> val = val;
    ret -> next = next;
    return ret;

}

void printNode(struct Node *node){

    if (node == NULL){
        printf("NULL\n");
        return;
    }

    printf("(Node: %f)", node->val);
}