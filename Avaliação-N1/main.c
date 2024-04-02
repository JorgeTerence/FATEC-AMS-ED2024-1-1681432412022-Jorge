// ----------------------------------- //
// Dado 14                             ||
// Autores: Jorge e Rodrigo Z          ||
// Instituição: Fatec Antonio Russo    ||
// Professor: Carlos Veríssimo         ||
// Data: 02/04/2024                    ||
// ----------------------------------- //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.c"
#include "edit.c"
#include "remove.c"
#include "search.c"

int main(void) {
  Node *head = ll_init();

  for (int i = 6; i != 0; scanf("%d", &i)) {
    switch (i) {
      case 1:
        printf("Enter product name: ");
        char name[50];
        scanf("%s", name);
        
        printf("Enter product price: ");
        float price;
        scanf("%f", &price);
        
        printf("Enter product quantity: ");
        int qtd;
        scanf("%d", &qtd);
        
        Product *prod = (Product *)malloc(sizeof(Product));
        prod->id = ll_count(head) + 1;
        strcpy(prod->name, name);
        prod->price = price;
        prod->qtd = qtd;
        
        head = ll_add(head, prod);
        break;
      case 2: 
           
        printf("Digite o id do produto: ");
        scanf( "%d", &id);
        scanf()
        buy(head,)
    }
  }
  return 0;
}