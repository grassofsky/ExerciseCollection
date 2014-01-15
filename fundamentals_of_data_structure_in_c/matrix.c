#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
#define CALLOC(p,n,s) \
    if (!((p)=calloc(n,s))) {                   \
    printf(stderr, "Instufficient memory"); \
    exit(EXIT_FAILURE); \
}

/*
 * 希疏矩阵在三元组的顺序为: 按行升序排序,同行元素按列序升序排序
 */
typedef struct {
    int col;
    int row;
    int value;
} term;

void print_matrix(term a[])
{
    int n, i, j, index;
    n = a[0].value;

    index = 1;
    for (i=0; i<a[0].row; ++i) {
        for (j=0; j<a[0].col; ++j) {
            if (j == a[index].col &&
                i == a[index].row) {
                printf("%d ", a[index].value);
                index++;
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void print_one_array(int *b, int n)
{
    int i;
    for (i=0; i<n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

/*
 * for all elements in column j
 *   take element <i, j, value> in
 *   element <j, i, value>
 */
void transpose(term a[], term b[])
{
    int n, i, j, currentb;
    n = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    if (n>0) {
        currentb = 1;
        for (i=0; i<a[0].col; i++) {
            for (j=1; j<=n; j++) {
                if (a[j].col == i) {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
}

/*
 * 将上述的transpose进行进一步的优化
 *   先确定原矩阵中每列非零元素的个数,即转置矩阵中每行非零元素的个数
 *   则转置矩阵中每行的起始位置就确定下来,
 *   原来矩阵的每项数据可以对应到转置矩阵的已知位置
 */
void fast_transpose(term a[], term b[])
{
    int *non_zer;
    int *start_point;
    int i, n, j, index;

    n = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    if (n > 0) {
        CALLOC(non_zer, a[0].col, sizeof(int));
        CALLOC(start_point, (a[0].col+1), sizeof(int));

        /* Determine the number of non-zero element in a */
        for (i=1; i<=n; ++i) {
            non_zer[a[i].col] += 1;
        }

        /*
           Determine the start site of every row: new matrix
        */
        start_point[0] = 1;
        for (i=1; i<=a[0].col; ++i) {
            start_point[i] = start_point[i-1] + non_zer[i-1];
        }

        print_one_array(start_point, a[0].col);

        /* The index from every start point is in sequence */
        for (i=1; i<=n; ++i) {
            index = start_point[a[i].col]++;
            b[index].col = a[i].row;
            b[index].row = a[i].col;
            b[index].value = a[i].value;
        }
        free(start_point);
        free(non_zer);
    }
}

int main()
{
    term a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS];
    a[0].col = 6; a[0].row = 6; a[0].value = 8;

    a[1].row = 0; a[1].col = 0; a[1].value = 15;

    a[2].row = 0; a[2].col = 3; a[2].value = 22;
    a[3].row = 0; a[3].col = 5; a[3].value = -15;
    a[4].row = 1; a[4].col = 1; a[4].value = 11;
    a[5].row = 1; a[5].col = 2; a[5].value = 3;
    a[6].row = 2; a[6].col = 3; a[6].value = 6;
    a[7].row = 4; a[7].col = 0; a[7].value = 91;
    a[8].row = 5; a[8].col = 2; a[8].value = 28;

    printf("Matrix a: \n");
    print_matrix(a);

    transpose(a, b);

    printf("Matrix b: \n");
    print_matrix(b);

    printf("Matrix c: \n");
    fast_transpose(b, c);
    print_matrix(c);
}