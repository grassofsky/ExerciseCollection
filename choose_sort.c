#include <stdio.h>
#include <stdlib.h>

/* 主要步骤
   1. list[i]和list[i+1],list[i+2],...,list[n]进行比较
   2. 交换list[i]和list[min]
*/


#define MAX_SIZE 101
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int main() {
  int list[MAX_SIZE];
  int i, j, tmp, min;

  // 产生随机序列
  for(i=0; i<MAX_SIZE; ++i) {
    list[i] = rand()%1000;
    printf("%d  ", list[i]);
  }
  
  for(i=0; i<MAX_SIZE; ++i) {
    min = i;
    for (j=i+1; j<MAX_SIZE; ++j) {
      if (list[j] < list[min]) { // 比较得出大于list[i]的最小值的位置
	min = j;
      }
    }
    SWAP(list[i], list[min], tmp);
  }
  
  for(i=0; i<MAX_SIZE; ++i) {
    printf("%d  ", list[i]);
  }
  return 0;
}
