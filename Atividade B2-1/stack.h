#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int top;
  int capacity;
  float array[];
} Stack;

Stack *st_innit(int cap) {
  Stack *st = (Stack *)malloc(sizeof(Stack));
  st->top = -1;
  st->capacity = cap;
  return st;
}

bool st_empty(Stack *st) { return st->top == -1; }

bool st_full(Stack *st) { return st->top == st->capacity - 1; }

bool st_push(Stack *st, float val) {
  if (st_full(st))
    return true;

  st->array[++st->top] = val;
  return false;
}

float st_pop(Stack *st) {
  if (st_empty(st))
    return -2147483648;

  return st->array[st->top--];
}

float st_top(Stack *st) {
  if (st_empty(st))
    return -2147483648;
  return st->array[st->top];
}
#endif