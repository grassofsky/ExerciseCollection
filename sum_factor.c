/*
 *判断n是否等于其因子的总和
 */

#include <stdio.h>

// 迭代
void sum_factor(int *sum, int n, int i){
    if (i == n)
        return;
    else {
        if (n/(i*1.0) == n/i) {
            *sum += i;
        }
        sum_factor(sum, n, i+1);
    }
}

int main() {
    int n, i, sum, sum2;
    char quit = ' ';
    while (quit != 'q') {
        printf("input the integer: ");
        scanf("%d", &n);
        sum = 0;
        sum2 = 0;

        // 循环
        for (i=1; i<n; i++) {
            if (n/(i*1.0) == (int)n/i) {
                sum += i;
            }
        }

        sum_factor(&sum2, n, 1);
        if (sum2 != sum) {
            printf("error was occured in sum_factor calculating");
        }

        if (sum == n)
            printf("The sum of the factors is equal to %d\n", n);
        else
            printf("The sum of the factors (%d) is not equal to %d\n", sum, n);
        printf("Do you want quit(q)?: ");
        scanf("%c", &quit);
    }
}