/*
 * 对长度为n的有序的序列实现折半查找, list[0]<=list[1]<=...
 * 1. 查找范围初始为[left, right]， middle=(left + right)/2
 * 2. if lookfor > list[middle]: left=middle
 *    elif lookfor < list[middle]: right=middle
 *    elif lookfor == list[middle]: return middle
 * 3. 重复查找，直到left > right
 */

#include <stdio.h>

int half_search(int lookfor, int left, int right, int list[]) {
  int middle;

  middle = (left + right)/2;
  if (left > right) {
    return -1;
  } else if (lookfor > list[middle]) {
    left = middle;
  } else if (lookfor == list[middle]) {
    return middle;
  } else if (lookfor < list[middle]) {
    right = middle;
  }
  half_search(lookfor, left, right, list);
}

int main() {
  int list[20];
  int i, site;
  int lookfor = 10;
  
  for (i=0; i<20; ++i) {
    list[i] = i*2;
  }
  site = half_search(lookfor, 0, 19, list);
  if (site == -1) {
    printf("There is no %d in list\n", lookfor);
  } else {
    printf("The number %d is at list[%d]\n", lookfor, site);
  }
}
