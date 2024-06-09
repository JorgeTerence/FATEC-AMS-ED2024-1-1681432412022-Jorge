#include "aux.h"
#include "colors.h"
#include "queue.h"
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENU                                                                   \
  "=======================\n[1] Cadastrar\n[2] Exibir\n[3] Consultar\n[4] "    \
  "Editar\n[5] "                                                               \
  "Remover\n[0] Sair\n> "

#define SEARCH_LIMIT 100

// Adicionar
Node *adicionar_contato(Node *head, Contato *contato) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->contato = contato;
  new->proximo = NULL;

  if (head == NULL || strcmp(contato->nome, head->contato->nome) < 0) {
    new->proximo = head;
    return new;
  }

  Node *anterior = NULL;
  Node *atual = head;
  while (atual != NULL && strcmp(contato->nome, atual->contato->nome) > 0) {
    anterior = atual;
    atual = atual->proximo;
  }

  anterior->proximo = new;
  new->proximo = atual;

  return head;
}

// Exibir lista de contatos
void ll_show(Node *head) {
  Queue *exibition = (Queue *)malloc(sizeof(Queue));
  exibition->start = head;

  Node *last = NULL;
  for (last = head; last != NULL; last = last->proximo);
  exibition->end = last;

  print_queue(exibition);
}

// Função para exibir os detalhes completos de um contato
void show_contact_details(Contato *contato) {
  printf("Nome: %s\n", contato->nome);
  printf("Sobrenome: %s\n", contato->sobrenome);
  printf("Telefone: %s\n", contato->telefone);
  printf("Email: %s\n", contato->email);
}

// Buscar
Contato *search_contato(Node *lista) {
  char *name = ask_str("Digite o nome que deseja consultar: ", 50);
  Stack *found = st_innit(SEARCH_LIMIT);

  // Filtrar pelo nome e armazenar fila
  for (Node *p = lista; p != NULL; p = p->proximo)
    if (strcmp(p->contato->nome, name) == 0)
      st_push(found, p->contato);

  if (found->top == -1) {
    printf("%sNão encontrou:%s %s\n", RED, RESET, name);
    return NULL;
  }

  printf("%sContatos encontrados:%s\n", YELLOW, RESET);
  for (int i = 0; i <= found->top; i++) {
    Contato *contato = found->array[i];
    printf("[%d] %s %s - %s\n", i + 1, contato->nome, contato->sobrenome, contato->telefone);
  }

  int choice;
  printf("Escolha um contato (1-%d): ", found->top + 1);
  scanf("%d", &choice);

  if (choice < 1 || choice > found->top + 1) {
    printf("Escolha inválida!\n");
    return NULL;
  }

  Contato *selected_contact = found->array[choice - 1];
  show_contact_details(selected_contact);

  return selected_contact;
}

// Função de busca simplificada para edição e remoção
Contato *search_contato_simple(Node *lista) {
  char *name = ask_str("Digite o nome que deseja buscar: ", 50);
  Stack *found = st_innit(SEARCH_LIMIT);

  // Armazenar pessoas com mesmo nome em uma lista
  for (Node *p = lista; p != NULL; p = p->proximo)
    if (strcmp(p->contato->nome, name) == 0)
      st_push(found, p->contato);

  if (found->top == -1) {
    printf("%sNão encontrou:%s %s\n", RED, RESET, name);
    return NULL;
  }

  printf("%sContatos encontrados:%s\n", YELLOW, RESET);
  for (int i = 0; i <= found->top; i++) {
    Contato *contato = found->array[i];
    printf("[%d] %s %s - %s\n", i + 1, contato->nome, contato->sobrenome,
           contato->telefone);
  }

  int choice;
  printf("Escolha um contato (1-%d): ", found->top + 1);
  scanf("%d", &choice);
  getchar(); // Limpar o buffer de entrada

  if (choice < 1 || choice > found->top + 1) {
    printf("Escolha inválida!\n");
    return NULL;
  }

  return found->array[choice - 1];
}

// Editar contato
Node *editar_contato(Node *lista) {
  Contato *contato = search_contato_simple(lista);
  if (contato == NULL)
    return lista;

  // Editar os campos do contato
  char *novo_nome = ask_str("Novo nome: ", 50);
  char *novo_sobrenome = ask_str("Novo sobrenome: ", 50);
  char *novo_telefone = ask_str("Novo telefone: ", 20);
  char *novo_email = ask_str("Novo email: ", 50);

  // Atualizar o contato
  strcpy(contato->nome, novo_nome);
  strcpy(contato->sobrenome, novo_sobrenome);
  strcpy(contato->telefone, novo_telefone);
  strcpy(contato->email, novo_email);

  printf("Contato atualizado com sucesso!\n");

  return lista;
}

// Remover contato
Node *delete_contact(Node *lista, char *nome) {
  Contato *contatosEncontrados[SEARCH_LIMIT];
  Node *nodesEncontrados[SEARCH_LIMIT];
  int encontrados = 0;

  Node *anterior = NULL;
  Node *atual = lista;

  while (atual != NULL) {
    if (strcmp(atual->contato->nome, nome) == 0) {
      contatosEncontrados[encontrados] = atual->contato;
      nodesEncontrados[encontrados] = atual;
      encontrados++;
      if (encontrados >= SEARCH_LIMIT) {
        break;
      }
    }
    anterior = atual;
    atual = atual->proximo;
  }

  if (encontrados == 0) {
    printf("%sNão encontrou:%s %s\n", RED, RESET, nome);
    return lista;
  }

  printf("%sContatos encontrados:%s\n", YELLOW, RESET);
  for (int i = 0; i < encontrados; i++) {
    printf("[%d] %s %s - %s\n", i + 1, contatosEncontrados[i]->nome,
           contatosEncontrados[i]->sobrenome, contatosEncontrados[i]->telefone);
  }

  int escolha;
  printf("Escolha um contato para remover (1-%d): ", encontrados);
  scanf("%d", &escolha);
  getchar(); // Limpar o buffer de entrada

  if (escolha < 1 || escolha > encontrados) {
    printf("Escolha invalida!\n");
    return lista;
  }

  Node *remover = nodesEncontrados[escolha - 1];

  if (remover == lista) {
    lista = remover->proximo;
  } else {
    for (Node *p = lista; p != NULL; p = p->proximo) {
      if (p->proximo == remover) {
        p->proximo = remover->proximo;
        break;
      }
    }
  }

  free(remover);

  printf("Contato removido com sucesso!\n");

  return lista;
}

// Bloqueia a inserção de caracteres alem de numeros
int read_option() {
  char input[10];

  while (1) {
    printf(MENU);
    scanf("%s", input);

    // Verifica se a entrada é um número inteiro
    int ok = 1;
    for (int i = 0; i < strlen(input); i++) {
      if (!isdigit(input[i])) {
        ok = 0;
        break;
      }
    }

    if (ok)
      return atoi(input);
    printf("%sEntrada inválida!%s Insira um número inteiro.\n", RED, RESET);
  }
}