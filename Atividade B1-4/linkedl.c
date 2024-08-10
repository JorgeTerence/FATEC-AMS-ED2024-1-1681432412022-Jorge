#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *prox;
};

typedef struct node Node;

// Retorna elo inicial da lista
Node *llinit(void) { return NULL; }

// Cria um novo elo e o retorna
Node *llinsert(Node *l, int i) {
  Node *novo = (Node *)malloc(sizeof(Node));
  novo->info = i;
  novo->prox = l;
  return novo;
}

// Imprime todos os elementos da lista
void llprint(Node *l) {
  Node *p;
  for (p = l; p != NULL; p = p->prox) {
    printf("%d", p->info);
    if (p->prox != NULL)
      printf(" -> ");
  }
}

// Diz se a lista está vazia
bool llempty(Node *l) { return l == NULL; }

// Indica se um valor está presente na lista
int llsearch(Node *l, int v) {
  for (Node *p = l; p != NULL; p = p->prox)
    if (p->info == v)
      return true;

  return false;
}

// Apaga todos os elementos da lista
void llflush(Node *l) {
  Node *p = l;
  while (p != NULL) {
    Node *temp = p->prox;
    free(p);
    p = temp;
  }
}

// Deleta, se houver, o valor `v` da lista
// ALERTA: não consegue deletar o primeiro item da lista
bool lldelete(Node *l, int v) {
  Node *back = NULL;
  for (Node *p = l; p != NULL; p = p->prox) {
    if (p->info == v) {
      if (back == NULL) {    // 1° item da lista
        if (p->prox == NULL) // Único item da lista
          free(p);
        else // Mais de um item na lista
          p = p->prox;
      } else {
        back->prox = p->prox;
        free(p);
      }
      return true;
    }
    back = p;
  }
  return false;
}
