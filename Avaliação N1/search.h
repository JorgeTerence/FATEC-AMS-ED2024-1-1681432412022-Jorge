#ifndef SEARCH_H
#define SEARCH_H

#include "type.h"

Product *ll_search(Node *head) {
  int id;
  printf("Digite o id do produto: ");
  scanf("%d", &id);
  
  for (Node *current = head; current != NULL && current->data != NULL; current = current->next) {
    if (current->data->id == id) {
      return current->data;
    }
  }

  return NULL;
}

int ll_count(Node *head) {
  int count = 0;
  Node *current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}
#endif /*SEARCH_H*/