#include <stdio.h>

int main(void) {
  char name[20];
  printf("Por favor, informe seu nome: ");
  scanf("%s", name);
  printf("Olá, Sr(a). %s\n", name);
  return 0;
}