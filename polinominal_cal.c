/*
 * 多项式求解
 * n次多项式,系数为n+1维数组a
 * 令B(1) = a(n)*x + a(n-1)
 * 则: B(2) = B(1)*x + a(n-2);...; B(n) = B(n-1)*x + a(0)
 */

#include <stdio.h>
#include <stdlib.h>  // random function
#include <math.h>

/* Polinominal calculation
 * n     : n+1 elements of a
 * index : index of B
 * x     : input value of x
 */
double polinominal_cal(double a[], int index, int n, double x) {
    if (index == 1) return a[n]*x + a[n-1];
    else {
        return polinominal_cal(a, index-1, n, x)*x + a[n-index];
    }
}

int main() {
    int i;
    int n = 30;
    double x = 3;
    double a[n+1];
    double result;
    for (i = 0; i < n+1; ++i) {
        a[i] = i*2;
    }
    result = polinominal_cal(a, n, n, x);
    printf("result: %f\n", result);

    result = 0;
    for (i=0; i < n+1; ++i) {
        result += a[i]*pow(x,i);
    }
    printf("std result: %f\n", result);
}