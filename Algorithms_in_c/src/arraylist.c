/**
 * Implement list using array
 **/

/*
  Initialize the list.
  @Input: head, end the head of the list
          x, the current the index in the key[]
          next, the array to store the index, act as link
*/
void aListInitialize(int* head, int* end, int *x, int next[])
{
    *head = 0;
    *end = 1;
    *x = 2;
    next[*head] = *end;
    next[*end] = *end;
}

void aDeleteNext(int t, int next[])
{
    next[t] = next[next[t]];
}

int aInsertAfter(int v, int t, int *x, int key[], int next[])
{
    key[*x] = v;
    next[*x] = next[t];
    next[t] = *x;
    return (*x)++;
}
