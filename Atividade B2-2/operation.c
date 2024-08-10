#include "queue.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

char *ask_str(char *msg, size_t size) {
  char *value = (char *)malloc(size * sizeof(char));
  printf("%s", msg);
  scanf("%s", value);
  return value;
}

bool ask_yes_no(char *msg) {
  char answer;
  while (answer != 's' && answer != 'n') {
    printf("%s", msg);
    scanf("%s", &answer);
  }

  return answer == 's';
}

Patient *ask_patient() {
  int password = ask_int("Senha: ");
  int age = ask_int("Idade: ");
  char *name = ask_str("Nome: ", 50);
  char *specialty = ask_str("Especialidade: ", 10);

  return patient_init(password, age, name, specialty);
}

void patient_card(Patient *pt) {
  printf("-----------------\n");
  printf("Senha: %d\n", pt->password);
  printf("Nome: %s\n", pt->name);
  printf("Idade: %d\n", pt->age);
  printf("Caso: %s\n", pt->specialty);
  
  char entry_str[10];
  strftime(entry_str, 10, "%H:%M:%S", localtime(&pt->entry));
  printf("Entrada: %s\n", entry_str);
  
  if (pt->exit != 0) {
    char exit_str[10];
    strftime(exit_str, 10, "%H:%M:%S", localtime(&pt->exit));
    printf("Saída: %s\n", exit_str);
  }
  
  printf("-----------------\n");
}
