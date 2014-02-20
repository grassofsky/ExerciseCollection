/**
 * Convert the arithmetic expressions to reverse Polish notation
 * For example:
 *  9+(10-20)*4= 9 10 20 - 4 * +
 **/
#include <stdio.h>
#include "../src/datastruct.h"

pNode oHead;
pNode oEnd;
pNode dHead;
pNode dEnd;

void reversePolish()
{
    char c, op, rPolish[100];
    int x, isdigital, i;
    stackInitialize(&oHead, &oEnd); // Store the operator
    stackInitialize(&dHead, &dEnd); // Store the data
    for ( ; scanf("%1s", &c) != EOF; ) {
        x = 0;

        /*
          Convert the continue digital character to number
        */
        while (c>='0' && c<='9') {
            push((int)c, dHead);
            scanf("%1c", &c);
        }

        /*
          When meet ')' push the operation
          between '(' and ')' to data stack from op stack;
          When meet '=', push the rest operation
          to data stack from operation stack;
          The others push to operation stack.
          Between every element, add a space
        */
        if (c != '(' && c !=')') {
            push(32, dHead);
        }

        if (c==')') {
            while (!stackEmpty(oHead, oEnd) &&
                   (op=(char)pop(oHead)) != '(') {
                push(32, dHead);
                push((int)op, dHead);
            }
        } else if (c=='=') {
            while(!stackEmpty(oHead, oEnd)) {
                push((int)pop(oHead), dHead);
                push(32, dHead);
            }
        } else {
            push((int)c, oHead);
        }
    }

    /*
      Reverse the elements in stack,
      and store them in array rPolish
    */
    i = 0;
    while (1) {
        if (stackEmpty(dHead, dEnd)) break;
        rPolish[i] = (char)pop(dHead);
        i++;
    }

    rPolish[i] = '\0';
    printf("The data are: ");
    for (i=i-1; i>=0; i--) {
        printf("%c", rPolish[i]);
    }
    printf("\n");
}

int main()
{
    reversePolish();
    return 0;
}