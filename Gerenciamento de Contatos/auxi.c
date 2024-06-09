#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "colors.h"

char *ask_str(char *msg, int size) {
  char *value = (char *)malloc(size * sizeof(char));
  printf("%s", msg);
  scanf(" %[^\n]", value);
  return value;
}

char *ask_numeric_str(char *msg, int size) {
  char *value = (char *)malloc(size * sizeof(char));
  int valid = 0;

  while (!valid) {
    printf("%s", msg);
    scanf("%s", value);
    valid = 1;
    for (int i = 0; i < strlen(value); i++) {
      if (!isdigit(value[i])) {
        valid = 0;
        printf("%sEntrada inválida!%s Por favor, insira apenas números.\n", RED,
               RESET);
        break;
      }
    }
  }

  return value;
}

int ask_int(char *msg) {
  int value;
  printf("%s", msg);
  scanf("%d", &value);
  return value;
}

int ask_int_range(char *msg, int min, int max) {
  int value;
  do { value = ask_int(msg); }
  while (value < min || value > max);

  return value;
}