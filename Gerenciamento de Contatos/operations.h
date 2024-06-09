#include "contato.h"

#ifndef Node_h
#define Node_h
typedef struct Node {
  Contato *contato;
  struct Node *proximo;
} Node;
#endif

Node *adicionar_contato(Node *lista, Contato *contato);
void ll_show(Node *lista);
Contato *search_contato(Node *lista);
Node *delete_contact(Node *lista, char *nome);
Node *editar_contato(Node *lista);
char *ask_str(char *msg, int size);
char *ask_numeric_str(char *msg, int size);
int read_option();