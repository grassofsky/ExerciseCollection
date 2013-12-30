/*
    **布尔变量组合输出**
    bool_print.c: 给定n个布尔变量x1,...,xn，
    我们希望打印所有可能的真值组合。
    如n=2,输出为(true, true),(false, true),
    (true, false), (false, false)
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0

void setValue(int* bool_set, int index, int n) {
    int i;
    // After all of the values have been set, print out them.
    if (index == n) {
        for (i=0; i<n; ++i) {
            if (bool_set[i]) printf("true");
            else printf("false");
            printf(",");
        }
        printf("\n");
        return;
    }

    bool_set[index] = TRUE;
    setValue(bool_set, index+1, n);
    bool_set[index] = FALSE;
    setValue(bool_set, index+1, n);
}

int main() {
    int n;
    int ngroup;
    int *bool_set;
    printf("Please input the number of bool value\n");
    scanf("%d", &n);

    printf("n = %d\n", n);
    bool_set = (int*) calloc(n, sizeof(int));
    setValue(bool_set, 0, n);

    free(bool_set);
    return 0;
}