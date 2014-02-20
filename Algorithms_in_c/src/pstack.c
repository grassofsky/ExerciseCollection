/* File pstack.c
 * Realise the pushdown stack data struct using list
 */

#include <stdio.h>
#include <stdlib.h>
#include "datastruct.h"

void stackInitialize(pNode* head, pNode* end)
{
    (*head) = (pNode) malloc(sizeof(**head));
    (*end) = (pNode) malloc(sizeof(**end));
    (*head)->next = (*end);
    (*head)->key = 0;
    (*end)->next = (*end);
}

void push(int v, pNode head)
{
    pNode t;
    t = (pNode) malloc(sizeof(*t));
    if (!t) printf("error");
    t->key = v;
    t->next = head->next;
    head->next = t;
}

int pop(pNode head)
{
    pNode t;
    int x;
    t = head->next;
    head->next = t->next;
    x = t->key;
    free(t);
    return x;
}

int stackEmpty(pNode head, pNode end)
{
    return head->next == end;
}