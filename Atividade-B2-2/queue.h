#pragma once
#include <stdbool.h>
#include "types.h"

typedef struct Node {
  Patient *patient;
  struct Node *next;
} Node;

typedef struct {
  Node *start;
  Node *end;
} Queue;

Node *node_init(Patient *patient);

Queue *q_init();

void enqueue(Queue *queue, Patient *patient);

Patient *dequeue(Queue *queue);

void print_queue(Queue *queue);

bool queue_empty(Queue *queue);
