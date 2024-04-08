// ----------------------------------- //
// Dado 14                             //
// Autores: Jorge e Rodrigo Z          //
// Instituição: Fatec Antonio Russo    //
// Professor: Carlos Veríssimo         //
// Data: 02/04/2024                    //
// ----------------------------------- //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "edit.h"
#include "input.h"
#include "search.h"

void debugg(Product *prod) {
  printf("chegamos");
  if (prod == NULL) 
    printf("tá vazio\n");

  printf("%s: R$%.2f\n", *prod->name, prod->price * prod->qtd);
}

int main(void) {
  Node *head = ll_init();
  Product *prod;
  int qtd;
  int i;
  while(i!=0) {
    printf("1 - Adicionar produto\n");
    printf("2 - Buscar produto\n");
    printf("3 - Dar baixa no produto\n");
    
    scanf("%d", &i);
    switch (i) {
    case 1: 
      head = ll_add(head, input_prod(ll_count(head) + 1));
      break;
    case 2: 
      prod = ll_search(head);
      if (prod == NULL)
        printf("Produto não encontrado :(\n");
      else
      {
        printf("Nome: %s\n", prod->name);
        printf("Qtd: %d\n", prod->qtd);
      }
      break;
      
      case 3:
      printf("Digite a quantidade a ser retirada: ");
      scanf("%d", &qtd);
      if(buy(head, qtd))
        printf("Compra realizada com sucesso!\n");
      else
        printf("Compra não realizada (falta no estoque)\n");
      break;
    }
    
  }
  return 0;
}
