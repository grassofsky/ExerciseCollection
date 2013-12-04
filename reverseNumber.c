#include <stdio.h>

/*
 * Reverse the input int number using iterator method
 */
void reverseNumIter(int number) {
    if (number == 0)
	return;
    
    printf("%d", number%10);
    reverseNumIter(number/10);
    return;
}

/*
 * Rverse the input int number using loop
 */
void reverseNumLoop(int number) {
    do {
	printf("%d", number%10);
    } while(number = number/10);
}
 
int main() {
    int number = 3254;
    
    printf("Using iterator method: ");
    reverseNumIter(number);

    printf("\nUsing loop method: ");
    reverseNumLoop(number);
    printf("\n");
}
