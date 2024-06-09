#pragma once
#include "operations.h"
#include "contato.h"
#include <stdbool.h>

typedef struct Queue {
  Node *start;
  Node *end;
} Queue;

Node *node_init(Contato *contato);
Queue *q_init();
void enqueue(Queue *queue, Contato *contact);
Contato *dequeue(Queue *queue);
void print_queue(Queue *queue);
bool queue_empty(Queue *queue);