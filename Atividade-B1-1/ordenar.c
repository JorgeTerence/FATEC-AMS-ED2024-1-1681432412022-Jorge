#include <stdbool.h>
#include <stdio.h>

int main(void)
{
  bool manual = false;

  int len = 10;
  int values[] = {10, 2, 4, 0, 8, 8, 3, 9, 1, 5};

  if (manual)
    for (int i = 0; i < len; i++)
      scanf_s("%d", &values[i]);

  for (int k = 1; k < len; k++)
  {
    for (int l = 0; l < len; l++)
    {
      for (int i = 0; i < len; i++)
      {
        if (i + k < len && values[i] > values[i + k])
        {
          int temp = values[i];
          values[i] = values[i + k];
          values[i + k] = temp;
        }
      }
    }
  }

  for (int i = 0; i < len; i++)
    printf("%d ", values[i]);
  return 0;
}