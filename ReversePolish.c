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
    char tmp;
    int i = 0;

    // All the input token was recorded except spaces
    while ((tmp = getchar()) && i < MAX_SIZE-1) {
	if (isspace(tmp)) break;
	token[i++] = tmp;
    }
    token[i] = '\0';
  
    if (i == 0) return FALSE;
    else return TRUE;
}

/*
 * Check the input token is number or not
 */
int isNumber(char token[]) {
    int i;
    int nDot = 0; // count the number of the dot in the token
    // which must < 2

    for (i = 0; token[i] != '\0' && i < MAX_SIZE; ++i) {
	if (token[i] >= '0' && token[i] <= '9') continue;
	else if (token[i] == '.' && nDot < 2) { // Support the "double" input token, such as, 3.2
	    nDot++;
	    continue;
	} else {
	    return FALSE;
	}
    }
    return TRUE;
}

/*
 * check the token is an operator or not
 */
int isOperator(char token[]) {
    if (token[1] == '\0' &&
	(token[0] == '-' || token[0] == '*' || token[0] == '=' ||
	 token[0] == '/' || token[0] == '+')) {
	return TRUE;
    } else {
	return FALSE;
    }
}

/*
 * check the token is an signal for quiting
 */
int isQuit(char token[]) {
    if (token[0] == 'q') {
	return TRUE;
    } else {
	return FALSE;
    }
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

    while (getToken(token)) {
	if (token[0] == '\0') continue;
	else if (isNumber(token)) {
	    tmp = atof(token);
	    push(stack, tmp, &topIndex);
	    if (topIndex > MAX_SIZE-1) {
		printf("Exceed the max size (40)\n");
		break;
	    }
	} else if (isOperator(token)){
	    switch (token[0]) {
	    case '+':
		tmp = pop(stack, &topIndex);
		tmp += pop(stack, &topIndex);
		push(stack, tmp, &topIndex);
		break;
	    case '-':
		tmp = pop(stack, &topIndex);
		tmp -= pop(stack, &topIndex);
		push(stack, tmp, &topIndex);
		break;
	    case '*':
		tmp = pop(stack, &topIndex);
		tmp *= pop(stack, &topIndex);
		push(stack, tmp, &topIndex);
		break;
	    case '/':
		tmp = pop(stack, &topIndex);
		tmp /= pop(stack, &topIndex);
		push(stack, tmp, &topIndex);
		break;
	    case '=':
		tmp = pop(stack, &topIndex);
		printf("Ans: %f\n",tmp);
		break;
	    default:
		printf("Error operator\n");
		return -1;
	    }
	} else if (isQuit(token)) {
	    break;
	}
    }
}

