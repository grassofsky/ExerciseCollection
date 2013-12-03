/**
 * Using the reverse polish notation to calculate the 
 * simple expression, such as, (2 + 3) * (3 - 5) then the
 * input is 2 3 + 3 5 - * =
 * The detail information can be found at (http://en.wikipedia.org/wiki/Reverse_Polish_notation)
 ***/

#include <stdio.h>
#include <ctype.h> // function: isspace
#include <stdlib.h> // atof

#define MAX_SIZE 40 // The max size of the tokens can be stored
#define FALSE 0
#define TRUE 1
#define DEBUG 0
#define NUMBER 1

/*
 * print the input char: used in debuging
 */
void print(char* file, int line, char* valName, char tmp) {
    if (DEBUG) {
	printf("%s,%d,%s:%c\n", file, line, valName, tmp);
    }
}

/* 
 * get the token from input stream
 */
int getToken(char token[]) {
    char c;      // The value name 'c' usually was used as a usual char
    int i, nDot; // Define usually before being used
    
    // The initial space will be neglected
    while ((token[0] = c = getchar()) == ' ' || c == '\t')
	;
    token[1] = '\0';
    if (!isdigit(c) && c != '.') {
	return c;
    }
    
    nDot = 0;
    if (c == '.') {
	nDot += 1;
    }

    i = 1;
    while (c = getchar()) {
	if (isdigit(c)) token[i++] = c;
	else if (c == '.' && nDot == 0) {
	    nDot += 1;
	    token[i++] = c;
	} else if (c != EOF){
	    ungetc(c, stdin);
	    break;
	} else {
	    break;
	}
    }
    token[i] = '\0';
  
    return NUMBER;
}

/* 
 * push the value to the stack
 */
void push(double stack[], double value, int* pTopIndex) {
    stack[*pTopIndex] = value;
    *pTopIndex += 1;
}

/*
 * pop the value from the stack
 */ 
double pop(double stack[], int* pTopIndex) {
    *pTopIndex -= 1;
    return stack[*pTopIndex];
}

int main() {
    double stack[MAX_SIZE]; // The stack used to store the input tokens
    double tmp;             // Record the temperate result after operating
    char token[MAX_SIZE];
    int topIndex = 0;       // The topIndex means the index above the top
    char type;

    while ((type = getToken(token)) != EOF) {
	switch (type) {
	case NUMBER:
	    push(stack, atof(token), &topIndex);
	    break;
	case '+':
	    tmp = pop(stack, &topIndex);
	    tmp += pop(stack, &topIndex);
	    push(stack, tmp, &topIndex);
	    break;
	case '-':
	    tmp = pop(stack, &topIndex);
	    tmp = pop(stack, &topIndex) - tmp;
	    push(stack, tmp, &topIndex);
	    break;
	case '*':
	    tmp = pop(stack, &topIndex);
	    tmp *= pop(stack, &topIndex);
	    push(stack, tmp, &topIndex);
	    break;
	case '/':
	    tmp = pop(stack, &topIndex);
	    tmp = pop(stack, &topIndex)/tmp;
	    push(stack, tmp, &topIndex);
	    break;
	case '\n':
	    tmp = pop(stack, &topIndex);
	    printf("Ans: %f\n",tmp);
	    break;
	default:
	    printf("Error operator\n");
	    return -1;
	}
    }
}

