/*
 * Exercise of chapter 2
 */
#include <stdio.h>
#include "../src/gcd.h"
#include "../src/datastruct.h"

/*
  1. Fill in a two-dimensional array of boolean values by setting
     a[i][j] to 1 if the greatest common divisor of i and j is 1
     and to 0 otherwise.
*/
void exerciseOne()
{
    int a[100][100], b[100][100];
    int i, j, t, count, sum;

    // Traverse all elements from 1 to 100
    count = 0;
    for (i = 1; i <= 100; ++i) {
        for (j = 1; j <= 100; ++j) {
            count++;
            t = gcd(i, j, NULL);
            if (t == 1) {
                a[i-1][j-1] = 1;
            } else {
                a[i-1][j-1] = 0;
            }
        }
    }
    printf("All traversed: %d\n", count);

    // Traverse half of the all elements first
    // and then copy the elements in [i][j] to [j][i]
    count = 0;
    for (i = 1; i <= 100; ++i) {
        for (j = 1; j <= i; ++j) {
            t = gcd(i, j, NULL);
            count++;
            if (t == 1) {
                b[i-1][j-1] = 1;
                b[j-1][i-1] = 1;
            } else {
                b[i-1][j-1] = 0;
                b[j-1][i-1] = 0;
            }
        }
    }
    printf("Half traversed: %d\n", count);

    // If the a and b is the same, the sum == 0
    sum = 0;
    for (i = 0; i < 100; ++i) {
        for (j = 0; j < 100; ++j) {
            sum = sum + a[i][j] - b[i][j];
        }
    }
    if (sum == 0) printf("The two methods get the same result\n");
    else printf("Error in the method b\n, the sum is: %d\n", sum);
}


/*
  2. Move the node following the node pointed to by s
     to the beginning of the list.
     head->a->l->i->s->t->b->end =>
     head->t->a->l->i->s->b->end
*/
void moveNextToFront(pNode *t, pNode *head)
{
    pNode x, tmp;
    x = (*head)->next;

    while (!(isLast(x->next)) &&
           x->next != (*t))
        x = x->next;

    if ((isLast(x->next)) && x->next == (*t)) {
        tmp = (*head)->next;
        (*head)->next = x->next;
        x->next = x->next->next;
        (*head)->next->next = tmp;
    } else if (x->next == (*t)) {
        tmp = (*head)->next;
        (*head)->next = (*t)->next;
        (*t)->next = (*t)->next->next;
        (*head)->next->next = tmp;
    } else {
        printf("Not find node t in the list\n");
    }
    return;
}


/*
  3. Implement a routine for a linked list htat exchange
     the positions of the nodes after the nodes pointed
     to by t and u
*/
void exchange(pNode t, pNode u) {
    pNode tmp1;
    pNode tmp2;
    pNode tmp3;

    tmp1 = t->next;
    tmp2 = t->next->next;
    tmp3 = u->next->next;

    t->next = u->next;
    t->next->next = tmp2;

    u->next = tmp1;
    u->next->next = tmp3;
}

void testList(char c)
{
    pNode head; pNode end; pNode t;
    pNode move; pNode ch1; pNode ch2;

    int i;

    /* Initial a list and give values */
    listInitialize(&head, &end);

    printf("Initial: ");
    t = head;
    for (i = 0; i < 14; ++i) {
        printf("%d ", i);
        t = insertAfter(i, &t);
        if (i == 2) move = t;
        if (i == 3) ch1 = t;
        if (i == 10) ch2 = t;
    }
    printf("\n");

    switch (c) {
    case '2':
        /* Move the node next to move to (next to head) */
        moveNextToFront(&move, &head);
        t = head->next;
        printf("Moved the element after 2\n");
        printf("Moved: ");
        for (i = 0; i < 14; ++i) {
            printf("%d ", t->key);
            t = t->next;
        }
        printf("\n");
        break;
    case '3':
        /* Print the result: change the nodes */
        exchange(ch1, ch2);
        t = head->next;
        printf("Exchange the element after 3 and after 10\n");
        printf("Changed: ");
        for (i = 0; i < 14; ++i) {
            printf("%d ", t->key);
            t = t->next;
        }
        printf("\n");
        break;
    default:
        break;
    }
    return;
}

/*
  4. N people have decided to commit mass suicide by arranging themselves
     in a circle and killing the Mth person around the circle, closing
     rangs as each person drops out of the circle.
     For example:
     N=9, M=5: 1 2 3 4 5 6 7 8 9
     The killed people in the order are 5 1 7 4 3 6 9 2 8
*/
/* With list */
void pListJosephus(int N, int M)
{
    int i;
    pNode t; pNode x;
    t = (pNode)malloc(sizeof(*t));
    t->key = 1; x= t;
    for (i = 2; i <= N; i++) {
        t->next = (pNode)malloc(sizeof(*t));
        t = t->next;
        t->key = i;
    }

    t->next = x;
    while (t != t->next) {
        for (i = 1; i < M; i++) t = t->next;
        printf("%d ", t->next->key);
        x = t->next;
        t->next = t->next->next;
        free(x);
    }
    printf("%d\n", t->key);
}

/* With array */
#define NMAX 100
void arrayJosephus(int N, int M)
{
    int x, i;
    int next[NMAX+1], key[NMAX+1];

    for (i = 1; i < N; i++) {
        next[i] = i+1;
        key[next[i]] = i;
    }
    next[i] = 1;
    key[next[i]] = N;

    x = 1;
    while (next[x] != next[next[x]]) {
        for (i = 1; i < M; i++) x = next[x];
        printf("%d ", key[next[x]]);
        next[x] = next[next[x]];
    }
    printf("%d\n", key[next[x]]);
}

void testJosephus()
{
    int N, M;
    scanf("%d %d", &N, &M);
    printf("The result using plist: \n\t");
    pListJosephus(N, M);
    printf("The result using array: \n\t");
    arrayJosephus(N, M);

    return;
}


/*
  5. Write procedures for insertion and deletion in a
     doubly linked list
*/
typedef struct DNode *pDNode;
struct DNode {
    int key;
    pDNode next;
    pDNode pre;
};

pDNode dHead; pDNode dEnd;

void dListInitialize()
{
    dHead = (pDNode) malloc(sizeof(*dHead));
    dEnd = (pDNode) malloc(sizeof(*dEnd));
    dHead->next = dEnd;
    dHead->pre = NULL;
    dEnd->next = NULL;
    dEnd->pre = dHead;
}

pDNode dInsertAfter(int v, pDNode t)
{
    pDNode x;
    x = (pDNode) malloc(sizeof(*x));
    x->key = v;
    x->pre = t;
    t->next->pre = x;
    x->next = t->next;
    t->next = x;

    return x;
}

void dDeleteNext(pDNode t)
{
    pDNode x;
    x = t->next;
    t->next = x->next;
    x->next->pre = t;
    free(x);
}

void testDoubleList()
{
    int i;
    pDNode t; pDNode x;
    dListInitialize();

    t = dHead;
    printf("Initial list:\n\t");
    for (i = 0; i < 20; ++i) {
        t = dInsertAfter(i, t);
        printf("%d ", i);
        if (i == 10) {
            x = t;
        }
    }
    printf("\n");

    dInsertAfter(100, x);
    printf("After insert:\n\t");
    t = dHead->next;
    for (i = 0; i < 21; ++i) {
        printf("%d ", t->key);
        t = t->next;
    }
    printf("\n");

    dDeleteNext(x);
    printf("After delete:\n\t");
    t = dHead->next;
    for (i = 0; i < 20; ++i) {
        printf("%d ", t->key);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    char input = '0';

    while (input != 'q') {
        printf("Choose a exercise to run [1-10] (q for quit):\n");
        while ((input=getchar())=='\n') ;

        switch (input) {
        case '1':
            exerciseOne();
            break;
        case '2':
            testList('2');
            break;
        case '3':
            testList('3');
            break;
        case '4':
            testJosephus();
            break;
        case '5':
            testDoubleList();
            break;
        case '6':
            break;
        case '8':
            break;
        default:
            break;
        }
    }
    return 0;
}