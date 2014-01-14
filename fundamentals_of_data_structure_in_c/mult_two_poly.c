#include <stdio.h>
#include <string.h>

#define MAX_DEGREE 101
#define MAX_TERM 101
#define COMPARE(x,y) ((x)<(y)?-1:((x)==(y)?0:1))

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial1;

typedef struct {
    int expon;
    float coef;
} polynomial2;

polynomial2 termsA[MAX_TERM];
polynomial2 termsB[MAX_TERM];
polynomial2 termsC[MAX_TERM];

void printPoly(polynomial2 terms[], int n, char *s)
{
    int i;
    printf("%s:", s);
    for (i=0; i<n-1; ++i) {
        printf("%5.2fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%5.2fx^%d\n", terms[n-1].coef, terms[n-1].expon);
}

void padd(polynomial2 a[], int an,
          polynomial2 b[], int *bn)
{
    /* add a and b to b */
    polynomial2 tmp[MAX_TERM];
    int i, j, k;
    i = 0; j = 0; k=0;

    if (*bn == 0) {
        for (i=0; i<an; ++i) {
            b[i] = a[i];
        }
        *bn = an;
        return;
    }

    while (i < an || j < *bn) {
        switch(COMPARE(a[i].expon, b[j].expon)) {
        case -1: /*a expon < b expon */
            tmp[k].coef = b[j].coef;
            tmp[k].expon = b[j].expon;
            j++;
            break;
        case 0:
            tmp[k].coef = a[i].coef + b[j].coef;
            tmp[k].expon = a[i].expon;
            i++;
            j++;
            break;
        case 1: /* a expon > b expon */
            tmp[k].coef = a[i].coef;
            tmp[k].expon = a[i].expon;
            i++;
            break;
        }
        k++;
    }

    /* trans the value in tmp to b */
    for (i=0; i<k; ++i) {
        b[i] = tmp[i];
    }
    *bn = k;
}

void pmult(polynomial2 a[], int an,
           polynomial2 b[], int bn,
           polynomial2 c[], int *cn)
{
    /* multiply a and b to c */
    int i, j, expon;
    float coef;

    polynomial2 tmp1[MAX_TERM];
    for (i=0; i<an; ++i) {
        for (j=0; j<bn; ++j) {
            /* Store every element in a temp array */
            tmp1[j].coef = a[i].coef * b[j].coef;
            tmp1[j].expon = a[i].expon + b[j].expon;
        }
        /* Add the temp array and the c */
        padd(tmp1, bn, c, cn);
    }
}

int main()
{
    int na, nb, *nc;
    termsA[0].expon = 1;
    termsA[0].coef = 2;
    termsA[1].expon = 0;
    termsA[1].coef = 4;
    na = 2;

    termsB[0].expon = 2;
    termsB[0].coef = 1;
    termsB[1].expon = 1;
    termsB[1].coef = 4;
    nb = 2;

    *nc = 0;
    printPoly(termsA, na, "termsA");
    printPoly(termsB, nb, "termsB");

    //padd(termsA, na, termsB, nc);
    pmult(termsA, na, termsB, nb, termsC, nc);
    printPoly(termsC, *nc, "nc");
}