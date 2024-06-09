  #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "operations.h"
#include "contato.h"

Node *node_init(Contato *contato) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->contato = contato;
  node->proximo = NULL;
  return node;
}

Queue *q_init() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->start = NULL;
  queue->end = NULL;
  return queue;
}

void enqueue(Queue *queue, Contato *contact) {
  Node *node = node_init(contact);
  if (queue->start == NULL)
    queue->start = node;

  if (queue->end != NULL)
    queue->end->proximo = node;

  queue->end = node;
}

Contato *dequeue(Queue *queue) {
  if (queue->start == NULL) {
    fprintf(stderr, "Fim da fila\n");
    queue->end = NULL;
    return NULL;
  }

  Contato *contato = queue->start->contato;
  Node *node = queue->start;
  queue->start = queue->start->proximo;
  //free(node);
  return contato;
}

void print_queue(Queue *queue) {
  if (queue->start == NULL) {
    printf("Exibição vazia\n");
    return;
  }

  for (Contato *temp = dequeue(queue); temp != NULL; temp = dequeue(queue)) {
    printf("----------------------------\n");
    printf("Nome: %s\n", temp->nome);
    printf("Sobrenome: %s\n", temp->sobrenome);
    printf("Telefone: %s\n", temp->telefone);
    printf("Email: %s\n\n", temp->email);
  }
}

bool queue_empty(Queue *queue) {
  return queue->start == NULL;
}
