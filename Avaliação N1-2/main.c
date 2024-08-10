#include "lib.h"

int main(void) {
  int input = 5;
  Pacote *head = (Pacote *)malloc(sizeof(Pacote));
  while (input > 0) {
    printf("Digite a opção desejada: ");
    scanf("%d", &input);

    switch (input) {
    case 1:
      head = inserir(head);
      break;
    case 2:
      alterar(head);
      break;
    case 3:
      rastrear(head);
      break;
    case 4:
      listar(head);
      break;
    }
  }
  return 0;
}