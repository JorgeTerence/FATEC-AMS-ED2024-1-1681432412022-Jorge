#include "type.c"

int Remove(Node * head, int id)
{
  Node *current = head;
  Node *prev = NULL;

  while (current != NULL && current->data->id != id)
    {
      prev = current;
      current = current->next;
    }
  if (current == NULL)
    {
      return 0;
    }
  if(prev == NULL)
  {
    head = current->next;
    return 1;
  }
  prev->next = current->next;
  free(current);
  return 1;
}