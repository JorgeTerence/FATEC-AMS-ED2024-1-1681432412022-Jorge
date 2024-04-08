#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
  int id;
  char *name[50];
  float price;
  int qtd;
};

typedef struct product Product;

struct node {
  Product *data;
  struct node *next;
};

typedef struct node Node;
#endif /*TYPE_H*/