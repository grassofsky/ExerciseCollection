/* File: plist.c
 * Realise the list structure using pointer
 */

#include "datastruct.h"

void listInitialize(pNode *head, pNode *end)
{
    *head = (pNode)malloc(sizeof(**head));
    *end = (pNode)malloc(sizeof(**end));
    (*head)->next = *end;
    (*head)->key = 0;
    (*end)->next = *end;
}

/* Delete the next element of t */
void deleteNext(pNode *t)
{
    pNode x;
    x = (*t)->next;
    (*t)->next = (*t)->next->next;
    free(x);
}

/* Insert v after the t element */
pNode insertAfter(int v, pNode *t)
{
    pNode x;
    x = (pNode)malloc(sizeof(*x));
    x->key = v;
    x->next = (*t)->next->next;
    (*t)->next = x;
    return x;
}

/* Test the pNode is at the last point or not */
int isLast(pNode t)
{
    if (t->next == t) return 1;
    else return 0;
}