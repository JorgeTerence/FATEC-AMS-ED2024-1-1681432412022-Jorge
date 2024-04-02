#include "type.c"

Product * Search(Node *head, int id)
{
  Node *current = head;
  while (current != NULL && current->data->id != id) {
    current = current->next;
  }
  if (current == NULL) {
    return NULL;
  }
  return current->data;
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
