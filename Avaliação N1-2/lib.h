#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *code2status(int code) {
  switch (code) {
  case 1:
    return "Em processamento";
  case 2:
    return "Em trânsito";
  case 3:
    return "Em espera";
  case 4:
    return "Entregue";
  case 99:
    return "Extraviado";
  default:
    return "Unknown";
  }
}

struct pacote {
  int id;
  char *cidade_origem[20];
  char *cidade_destino[20];
  int status;
  char *conteudo[20];
  struct pacote *next;
};

typedef struct pacote Pacote;

Pacote *inserir(Pacote *head) {
  Pacote *novo = (Pacote *)malloc(sizeof(Pacote));
  novo->id = head->id + 2;


  char temp[20];
  printf("Cidade de origem: ");
  scanf("%s", temp);
  strcpy(novo->cidade_origem, temp);

  printf("Cidade de destino: ");
  scanf("%s", temp);
  strcpy(novo->cidade_destino, temp);

  printf("Conteúdo: ");
  scanf("%s", temp);
  strcpy(novo->conteudo, temp);

  printf("\n[1] = Em processamento\n[2] Em trânsito\n[3] Em espera\n[4] = "
         "Entregue\n[99] Extraviado\n");
  printf("Status: ");
  scanf("%d", &novo->status);

  novo->next = head;

  printf("Pacote com id %d criado!\n", novo->id);

  return novo;
}

Pacote *pesquisar(Pacote *head) {
  int id;
  printf("Id da busca: ");
  scanf("%d", &id);

  for (Pacote *cur = head; cur != NULL; cur = cur->next)
    if (cur->id == id) 
      return cur;

  return NULL;
}

void alterar(Pacote *head) {
  Pacote *pacote = pesquisar(head);

  int status;
  printf("Status: ");
  scanf("%d", &status);

  if (status != 1 && status != 2 && status != 3 && status != 4 && status != 99) {
    printf("Status inválido\n");
    return;
  }

  pacote->status = status;
}

void listar(Pacote *head) {
  printf("\n");
  for (Pacote *node = head; node->next != NULL; node = node->next) {
    printf("Conteúdo: %s\n", node->conteudo);
    printf("Status: %s\n", code2status(node->status));
    printf("-=-=-=-=-=-=-=-\n");
  }
}

void rastrear(Pacote *head) {
  Pacote *pacote = pesquisar(head);
  printf("Conteúdo: %s\n", pacote->conteudo);
  printf("Status: %s\n", code2status(pacote->status));
  printf("-=-=-=-=-=-=-=-\n");
}
#endif