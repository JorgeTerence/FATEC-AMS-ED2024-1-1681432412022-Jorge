#include <stdbool.h>
#include <stdio.h>

#include "arrays.c"

#define manual false
#define len 5

int main(void) {
  int values[len] = {10, 2, 4, 0, 8};

  if (manual)
    for (int i = 0; i < len; i++) {
      printf("Valor %d: ", i);
      scanf_s("%d", &values[i]);
    }

  order(values, len);

  printf("Valores ordenados: ");
  show(values, len);

  printf("Valor maximo: %d\n", max(values, len));
  printf("Soma dos valores: %d\n", sum(values, len));
  
  doubler(values, len);
  printf("Valores duplicados: ");
  show(values, len);

  return 0;
}
