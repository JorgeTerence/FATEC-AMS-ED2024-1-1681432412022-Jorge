/* -------------------------------------------
Fatec São Caetano do Sul - Estrutura de Dados
Professor: Carlos Veríssimo
Proposta: Sistema hospitalar
Autor: Jorge Terence
Data: 12/05/2024
------------------------------------------- */

#include "colors.h"
#include "operation.h"
#include "queue.h"
#include "types.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define PREF_FREQ 3
#define MENU "=======================\n[1] Cadastrar paciente\n[2] Atender paciente\n[3] Visualizar fila\n[0] Sair\n> "

Queue *urgency, *regular, *preferential, *history;

void list_patients(int pick) {
  Queue *queues[] = {regular, preferential, urgency, history};
  char *colors[] = {BLUE, MAGENTA, RED, YELLOW};

  // All patients
  if (pick == 4) {
    for (int i = pick - 1; i >= 0; i--) {
      printf("%s# "  RESET, colors[i]);
      print_queue(queues[i]);
    }
  }
  // Specific queue
  else {
    printf("%s# " RESET, colors[pick - 1]);
    print_queue(queues[pick]);
  }
}

// FIX: Would need closures to work properly
// Create a closure that takes the specialty before, keep it in scope and return
// the callback Either this or find a way to define the callback in main with
// the comparator in scope Queue *filter_patients(bool (*match)(Patient *pt)) {
Queue *filter_patients(char *specialty) {
  Queue *queues[] = {urgency, preferential, regular, history};
  Queue *res = q_init();

  for (int i = 0; i < 4; i++) {
    for (Node *node = queues[i]->start; node != NULL; node = node->next) {
      if (strcmp(node->patient->specialty, specialty) == 0) {
        enqueue(res, node->patient);
      }
    }
  }

  return res;
}

Patient *search_patient(int password) {
  Queue *queues[] = {urgency, preferential, regular, history};

  for (int i = 0; i < 4; i++) {
    for (Node *node = queues[i]->start; node != NULL; node = node->next) {
      if (node->patient->password == password) {
        return node->patient;
      }
    }
  }

  return NULL;
}

int main(void) {
  urgency = q_init();
  regular = q_init();
  preferential = q_init();
  history = q_init();

  enqueue(regular, patient_init(10, 18, "Ágata", "joelho"));
  enqueue(preferential, patient_init(11, 78, "Glaciete", "pulmão"));
  enqueue(regular, patient_init(12, 18, "Jorge", "coluna"));
  enqueue(urgency, patient_init(13, 89, "Simone", "coração"));

  int option;
  int pref_counter = 1;
  do {
    option = ask_int_range(MENU, 0, 3);
    system("clear");

    switch (option) {
    // Add patient to queue
    case 1: {
      Patient *patient = ask_patient();
      
      if (search_patient(patient->password) != NULL) {
        printf("Paciente {%d} já cadastrado!\n", patient->password);
      }
      
      bool pregnant = strcmp(patient->specialty, "gestação") == 0;
      bool urgent = ask_yes_no("O tratamento é urgente? [s/n] ");

      if (urgent) {
        enqueue(urgency, patient);
      } else if (patient->age >= 60 || pregnant) {
        enqueue(preferential, patient);
      } else {
        enqueue(regular, patient);
      }

      break;
    }

    // Call patients based on priority
    case 2: {
      Patient *pt = malloc(sizeof(Patient));

      // Urgency
      if (!queue_empty(urgency)) {
        printf("%sAtendimento de urgência!%s\n", RED, RESET);
        pt = dequeue(urgency);
      }
      // Preferential
      else if (!queue_empty(preferential) && pref_counter % PREF_FREQ != 0) {
        printf("%sAtendimento preferencial%s\n", MAGENTA, RESET);
        pt = dequeue(preferential);
        pref_counter++;
      }
      // Regular
      else if (!queue_empty(regular)) {
        printf("%sAtendimento comum%s\n", BLUE, RESET);
        pt = dequeue(regular);
        pref_counter++;
      }
      // All queues are empty
      else {
        printf("Todas as filas estão vazias\n");
        pt = NULL;
      }

      if (pt != NULL) {
        pt->exit = time(NULL);
        enqueue(history, pt);
        patient_card(pt);
      }

      break;
    }

    // Show queues' contents
    case 3: {
      int action =
          ask_int_range("[1] Listar\n[2] Filtrar\n[3] Buscar\n> ", 1, 3);

      switch (action) {
      // Show patients
      case 1: {
        char queue_str[] = BLUE "[1] Normal\n" MAGENTA "[2] Preferencial\n" RED "[3] Urgência\n" YELLOW "[4] Histórico\n" RESET "[5] Todas\n> ";
        list_patients(ask_int_range(queue_str, 1, 5) - 1);

        break;
      }

      // Filter
      case 2: {
        char *specialty = ask_str("Especialidade: ", 10);
        print_queue(filter_patients(specialty));

        break;
      }

      // Search patient
      case 3: {
        int password = ask_int("Senha: ");
        Patient *pt = search_patient(password);

        if (pt != NULL) patient_card(pt);
        else printf("Paciente não encontrado\n");
        
      }
      }
      break;
    }
    }
  } while (option != 0);
  return 0;
}
