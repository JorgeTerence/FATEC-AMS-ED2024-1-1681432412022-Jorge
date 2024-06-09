#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "contato.h"

typedef struct {
  int top;
  int capacity;
  Contato *array[];
} Stack;

Stack *st_innit(int cap);
bool st_empty(Stack *st);
bool st_full(Stack *st);
bool st_push(Stack *st, Contato *val);
Contato *st_pop(Stack *st);
Contato *st_top(Stack *st);