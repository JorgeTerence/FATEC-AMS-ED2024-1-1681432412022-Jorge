/* -------------------------------------------
Fatec São Caetano do Sul - Estrutura de Dados
Professor: Carlos Veríssimo
Proposta: Sistema de Gerenciamento de Contatos
Autor: Equipe 2
Data: 28/05/2024
------------------------------------------- */

#include "operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"
#include "contato.h"
#include "aux.h"

int main() {
  Node *lista = NULL;

  lista = adicionar_contato(lista, contato_init("Fulano", "Vasconcelos", "123456789", "fulano@example.com"));
  lista = adicionar_contato(lista, contato_init("Ciclano", "de Assis", "987654321", "ciclano@example.com"));
  lista = adicionar_contato(lista, contato_init("Beltrano", "de Almeida", "456123789", "beltrano@example.com"));

  int option;

  do {
    option = read_option();
    switch (option) {
    case 1:
      lista = adicionar_contato(lista, prompt_contato());
      break;
    case 2:
      ll_show(lista);
      break;
    case 3:
      search_contato(lista);
      break;
    case 4: {
      editar_contato(lista);
      break;
    }
    case 5: {
      char *search = ask_str("Digite o nome do contato que deseja excluir: ", 50);
      lista = delete_contact(lista, search);
      break;
    }
    }
  } while (option != 0);
  
  return 0;
}
