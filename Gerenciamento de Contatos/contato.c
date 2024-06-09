#include "contato.h"
#include "aux.h"
#include <stdlib.h>
#include <string.h>

Contato *contato_init(char *name, char *last_name, char *telefone, char *email) {
  Contato *pt = (Contato *)malloc(sizeof(Contato));
  strcpy(pt->nome, name);
  strcpy(pt->sobrenome, last_name);
  strcpy(pt->telefone, telefone);
  strcpy(pt->email, email);
  return pt;
}

Contato *prompt_contato() {
  char *name = ask_str("Nome: ", 50);
  char *sobrenome = ask_str("Sobrenome: ", 50);
  char *email = ask_str("E-mail: ", 50);
  char *tel = ask_numeric_str("Telefone: ", 15);

  return contato_init(name, sobrenome, email, tel);
}