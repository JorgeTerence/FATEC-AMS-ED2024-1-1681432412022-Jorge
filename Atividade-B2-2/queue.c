#include <stdio.h>
#include <stdlib.h>
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

Node *node_init(Patient *patient) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->patient = patient;
  node->next = NULL;
  return node;
}

Queue *q_init() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->start = NULL;
  queue->end = NULL;
  return queue;
}

void enqueue(Queue *queue, Patient *patient) {
  Node *node = node_init(patient);
  if (queue->start == NULL)
    queue->start = node;

  if (queue->end != NULL)
    queue->end->next = node;
  
  queue->end = node;
}

Patient *dequeue(Queue *queue) {
  if (queue->start == NULL) {
    fprintf(stderr, "Can't dequeue from empty queue\n");
    queue->end = NULL;
    return NULL;
  }

  Patient *pt = queue->start->patient;
  Node *node = queue->start;
  queue->start = queue->start->next;
  free(node);
  return pt;
}

void print_queue(Queue *queue) {
  if (queue->start == NULL) {
    printf("[]\n");
    return;
  }
  
  Node *node = queue->start;
  printf("[%s{%d}", node->patient->name, node->patient->password);
  node = node->next;
  
  while (node != NULL) {
    printf(" -> %s{%d}", node->patient->name, node->patient->password);
    node = node->next;
  }

  printf("]\n");
}

bool queue_empty(Queue *queue) {
  return queue->start == NULL;
}
