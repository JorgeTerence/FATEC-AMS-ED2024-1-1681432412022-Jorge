#include <stdbool.h>
#include <stdio.h>

#include "arrays.c"

int main(void) {
  bool manual = false;
  int values[] = {10, 2, 4, 0, 8};
  int len = 5;

  if (manual)
    for (int i = 0; i < len; i++) {
      printf("Valor %d: ", i);
      scanf_s("%d", &values[i]);
    }

  order(values, len);
  show(values, len);

  printf("%d\n", max(values, len));
  printf("%d\n", sum(values, len));
  
  doubler(values, len);
  show(values, len);

  return 0;
}
