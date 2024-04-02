#include <stdbool.h>
#include "search.c"

bool ll_edit(Node *head, int id, char *name, float price, int qtd) {
  Product *match = Search(head, id);
  if (match == NULL) 
    return false;

  strcpy(match->name, name);
  match->price = price;
  
  return true;
}

bool restock(Node *head, int id, int qtd) {
  Product *match = Search(head, id);
  if (match == NULL) 
    return false;
  
  match->qtd += qtd;
  return true;
}

int buy(Node *head, int id, int qtd)
{
  Product *match = Search(head, id);

  if(match->qtd - qtd < 0)
    return 0;
  
  match->qtd -= qtd;
  return 1;

}
