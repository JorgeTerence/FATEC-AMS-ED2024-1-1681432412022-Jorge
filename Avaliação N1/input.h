#ifndef INPUT_H
#define INPUT_H

#include "type.h"
#include <stdio.h>
#include <string.h>


Node *ll_init() {
  Node *head = (Node *)malloc(sizeof(Node));
  head->data = NULL;
  head->next = NULL;
  return head;
}

Node *ll_add(Node *head, Product *prod) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = prod;
  new_node->next = head;
  return new_node;
}

Product *input_prod(int id) {
  Product *prod = (Product *)malloc(sizeof(Product));

  printf("Enter product name: ");
  char name_temp[50];
  scanf("%s", name_temp);
  strcpy(prod->name, name_temp);

  printf("Enter product price: ");
  scanf("%f", &prod->price);

  printf("Enter product quantity: ");
  scanf("%d", &prod->qtd);

  prod->id = id;
  
  return prod;
}

#endif /*INPUT_H*/
