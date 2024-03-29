#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedl.c"

extern struct Node;

int main(void) {
  Node *l = llinit();

  for (int command = 6; command != 0; scanf("%d", &command)) {
    int n;
    switch (command) {
    case 1:
      printf("Número a incluir: ");
      scanf("%d", &n);
      l = llinsert(l, n);
      break;
    case 2:
      printf("Número a consultar: ");
      scanf("%d", &n);
      printf("Número%s encontrado\n", llsearch(l, n) ? "" : " não");
      break;
    case 3:
      printf("Número a deletar: ");
      scanf("%d", &n);
      if (!lldelete(l, n)) // Não consegue deletar o primeiro item da lista
        printf("Número %d não foi encontrado\n", n);
      else
        printf("Valor deletado\n");
      break;
    case 4:
      if (llempty(l)) {
        printf("Lista vazia\n");
      } else {
        printf("[");
        llprint(l);
        printf("]\n");
      }
      break;
    case 5:
      llflush(l);
      break;
    case 6:
      printf("0 - Sair\n");
      printf("1 - Incluir\n");
      printf("2 - Consultar\n");
      printf("3 - Deletar\n");
      printf("4 - Listar\n");
      printf("5 - Limpar\n");
      printf("6 - Ajuda\n");
      break;
    default:
      printf("Comando inválido. Digite 6 para receber ajuda.\n");
      break;
    }

    printf("> ");
  }

  printf("Terminando\n");

  return 0;
}