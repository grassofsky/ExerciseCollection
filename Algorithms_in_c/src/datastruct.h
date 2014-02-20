#ifndef _DATASTRUCT_H_
#define _DATASTRUCT_H_
#include <stdlib.h>

typedef struct Node *pNode;
struct Node {
    int key;
    pNode next;
};

/* List */
extern pNode lHead;
extern pNode lEnd;
extern pNode list;

void listInitialize();
void deleteNext(pNode t);
pNode insertAfter(int v, pNode t);

/* Pushdown Stacks Using List */
void stackInitialize(pNode *head, pNode *end);
void push(int v, pNode head);
int pop(pNode head);
int stackEmpty(pNode head, pNode end);

#endif /* _DATASTRUCT_H_ */