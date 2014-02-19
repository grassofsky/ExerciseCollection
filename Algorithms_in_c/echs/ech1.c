/* The exercises in chapter 2 */
#include <stdio.h>
#include <ctype.h>
#include "../src/gcd.h"

/* 2.
 * check the values for u % v when u and v are not necessarily positive
 */
void checkValues()
{
    int u, v;

    printf("Input two values are not necessarily positive:\n");
    printf("u = ");
    scanf("%d", &u);
    printf("\nv = ");
    scanf("%d", &v);

    printf("u %% v = %d\n", u % v);
    return;
}


/* 3.
 * Implement a procedure to reduce a given fraction to lowest terms
 */
typedef struct {
    int numerator;
    int denominator;
} Fraction;

Fraction reduceFraction(Fraction frac)
{
    int g;
    g = gcd(frac.numerator, frac.denominator, NULL);
    frac.numerator = frac.numerator / g;
    frac.denominator = frac.denominator / g;
    return frac;
}

void testReduceF()
{
    Fraction frac = {200, 55};
    Fraction fracReduced = reduceFraction(frac);
    printf("Initial: %d/%d\n", frac.numerator, frac.denominator);
    printf("Reduced: %d/%d\n", fracReduced.numerator, fracReduced.denominator);
    return;
}


/* 4.
 * Reads a decimal number one character (digit) at a time,
 * Terminated by a blank, and returns the values of that number
 */
int convert()
{
    char input;
    int integer = 0;
    int siginal;
    enum {NEGATIVE=-1, POSITIVE=1};

    printf("Please input a integer:\n");
    input = getchar();
    if (input == '-') {
        siginal = NEGATIVE;
        input = getchar();
    }
    else {
        siginal = POSITIVE;
    }
    while (isdigit(input)) {
        integer = integer*10 + input - '0';
        input = getchar();
    }
    return integer*siginal;
}

void testConvert()
{
    int a = convert();
    printf("%d\n", a);
    return;
}


/* 5.
 * Print out the binary equivalent of a number
 */
void binary(int x)
{
    int twoMulti = 1;
    while (x >= twoMulti) {
        twoMulti = twoMulti * 2;
    }
    twoMulti = twoMulti/2;

    do {
        printf("%d", x/twoMulti);
        x = x % twoMulti;
        twoMulti = twoMulti / 2;
    } while (twoMulti > 0);
    printf("\n");
    return;
}

void testBinary()
{
    int x;
    printf("Please input a positive integer:\n");
    scanf("%d", &x);
    binary(x);
    return;
}

/* 8.
 * Compute the greatest common divisor of three integers u, v, and w
 */
int gcd3(int u, int v, int w)
{
    int x = gcd(u, v, NULL);
    return gcd(x, w, NULL);
}

void testGcd3()
{
    int u, v, w;
    printf("Please input three integers:\n");
    printf("u = ");
    scanf("%d", &u);
    printf("v = ");
    scanf("%d", &v);
    printf("w = ");
    scanf("%d", &w);
    printf("GCD = %d\n", gcd3(u, v, w));
    return;
}

int main()
{
    char input = '0';

    while (input != 'q') {
        printf("Choose a exercise to run [2-6, 8] (q for quit):\n");
        while ((input=getchar())=='\n') ;

        switch (input) {
        case '2':
            checkValues();
            break;
        case '3':
            testReduceF();
            break;
        case '4':
            testConvert();
            break;
        case '5':
            testBinary();
            break;
        case '6':
            gcd(12345, 56789, "sdf");
            break;
        case '8':
            testGcd3();
            break;
        default:
            break;
        }
    }
    return 0;
}