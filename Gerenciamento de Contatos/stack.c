#include <stdbool.h>
#include <stdlib.h>
#include "contato.h"

typedef struct {
  int top;
  int capacity;
  Contato *array[];
} Stack;

Stack *st_innit(int cap) {
  Stack *st = (Stack *)malloc(sizeof(Stack));
  st->top = -1;
  st->capacity = cap;
  return st;
}

bool st_empty(Stack *st) { return st->top == -1; }

bool st_full(Stack *st) { return st->top == st->capacity - 1; }

bool st_push(Stack *st, Contato *val) {
  if (st_full(st))
    return true;

  st->array[++st->top] = val;
  return false;
}

Contato *st_pop(Stack *st) {
  if (st_empty(st))
    return NULL;

  return st->array[st->top--];
}

Contato *st_top(Stack *st) {
  if (st_empty(st))
    return NULL;
  return st->array[st->top];
}
