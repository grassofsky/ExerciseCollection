# This is a list of the exercises

**Reverse Polish Notation for Calculate**
for example: (1-2) * (4+5) => 1 2 - 4 5 + * (ReversePolish.c)

**Reverse the input int number**
for example: 2342 => 2423

**Quicksort**
Given an array, one element is chosen and the others partitioned in two subsets-those less than the partition element and those greater than or equal to it

## 递归算法－数据结构基础（C语言版）
**选择排序**
choose_sort.c: From those integers that are currently unsorted, find the smallest and place it next in the sorted list.

**二项式系数**
通过递归的方式给出二项式系数的值，可以通过下式给出：。

**折半查找**
half_search.c: 通过递归的方式实现对已经排序的序列进行折半查找。

**集合的置换** *Not finished*
打印处给定集合的所有可能置换，如：集合{a, b, c}, 它的所有置换为{(a,b,c), (a,c,b), (b,a,c), (b,c,a), (c,a,b), (c,b,a)}

**多项式求解**
polinominal_cal.c: `A(x) = a(n)*x^n + a(n-1)*x^n-1 + ... + a(1)*x + a(0)*x^0`多项式求解，可采用Horner规则：`A(x) = (...((a(n)*x + a(n-1))*x+...+a(1))*x + a0)`,用递归实现上述过程。

**布尔变量组合输出**
bool_print.c: 给定n个布尔变量x1,...,xn，我们希望打印所有可能的真值组合。如n=2,输出为(true, true),(false, true), (true, false), (false, false)

**判断n是否等于其因子的总和**
sum_factor.c: 给定整整数n，判定n是否等于其因子的总和，因子t可以整除n，1 <= t < n

**用递归的方式实现阶乘**

**递归循环求Fibonacci的f(i), f0 = 0, f1=1**

**Ackerman function**
A(m, n) = (n + 1, if m = 0); (A(m-1, 1)), if n = 0); (A(m-1, A(m, n-1)), otherwise)

**Hanoi塔**
三根柱子，64个直径不等的空心碟子套在第一根柱子上，下面的碟子都比上面的大，要求将第一根柱子上的碟子移动到第三根柱子上，移动时遵循以下规则：
1. 一次只能移动一个碟子
2. 大碟子不能放在小碟子上
写一个递归程序，打印移动碟子的过程

**Powerset(S)**
S是n个元素的集合，它的幂集是它所有子集的集合。例如，如果S ＝ {a, b, c}, 那么powerset（S） = {{}, {a}, {b}, {c}, {a, b}, {a, c}, {b, c}, {a, b, c}}
