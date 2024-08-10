#ifndef EDIT_H
#define EDIT_H

#include <stdbool.h>
#include "search.h"

int buy(Node *head, int qtd)
{
  Product *match = ll_search(head);

  if(match->qtd - qtd < 0)
    return 0;
  
  match->qtd -= qtd;
  return 1;
}
#endif /* EDIT_H */