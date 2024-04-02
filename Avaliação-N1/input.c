#include "type.c"

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
