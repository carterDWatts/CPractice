#ifndef NODE_H_
#define NODE_H_

struct Node{
	double val;
	struct Node *next;
};

struct Node * makeNode(double val, struct Node * next);
void printNode(struct Node *node);

#endif

