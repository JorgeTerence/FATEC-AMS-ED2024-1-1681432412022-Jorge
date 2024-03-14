#include <stdio.h>

void swap(int *arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

void order(int *arr, int len)
{
  for (int k = 1; k < len; k++)
    for (int l = 0; l < len; l++)
      for (int i = 0; i < len; i++)
        if (i + k < len && arr[i] > arr[i + k])
          swap(arr, i, i + k);
}

int max(int *arr, int len)
{
  int max = -2147483647;
  for (int i = 0; i < len; i++)
    if (arr[i] > max)
      max = arr[i];

  return max;
}

int sum(int *arr, int len)
{
  int acc = 0;
  for (int i = 0; i < len; i++)
    acc += arr[i];

  return acc;
}

void show(int *arr, int len)
{
  printf("[");
  for (int i = 0; i < len; i++)
  {
    if (i + 1 != len)
      printf("%d, ", arr[i]);
    else
      printf("%d]\n", arr[i]);
  }
}

void doubler(int *arr, int len)
{
  for (int i = 0; i < len; i++)
    arr[i] = arr[i] * 2;
}
