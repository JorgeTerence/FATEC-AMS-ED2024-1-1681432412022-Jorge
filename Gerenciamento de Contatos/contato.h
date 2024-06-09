#pragma once

typedef struct {
  char nome[50];
  char sobrenome[50];
  char telefone[15];
  char email[50];
} Contato;

Contato *contato_init(char *name, char *last_name, char *telefone, char *email);
Contato *prompt_contato();