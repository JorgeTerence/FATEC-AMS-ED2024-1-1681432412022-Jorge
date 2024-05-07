#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "operation.h"
#include "queue.h"
#include "types.h"
#include "colors.h"

#define PREF_FREQ 3
#define MENU "=======================\n1 - Cadastrar paciente\n2 - Atender paciente\n3 - Visualizar fila\n0 - Sair\n> "

/*
TO-DO:
- [ ] registrar pacientes já atendidos
- [ ] registrar hora de entrada e saída
*/

int main(void) {
  Queue *urgency = q_init();
  Queue *regular = q_init();
  Queue *preferential = q_init();

  enqueue(regular, patient_init(1, 10, 18, "Ágata", "joelho"));
  enqueue(preferential, patient_init(2, 11, 78, "Glaciete", "pulmão"));
  enqueue(regular, patient_init(3, 12, 18, "Jorge", "coluna"));
  enqueue(urgency, patient_init(4, 13, 89, "Simone", "coração"));

  int option;
  int pref_counter = 1;
  do {
    option = ask_int_range(MENU, 0, 3);
    switch (option) {
    case 1: {
      // Add patient to queue
      Patient *patient = ask_patient();
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

    case 2: {
      // Call patients based on priority
      if (!queue_empty(urgency)) {
        printf("%sAtendimento de urgência!%s\n", RED, RESET);
        patient_card(dequeue(urgency));
        break;
      }

      if (!queue_empty(preferential) && pref_counter % PREF_FREQ != 0) {
        printf("%sAtendimento preferencial%s\n", MAGENTA, RESET);
        patient_card(dequeue(preferential));
      } else if (!queue_empty(regular)) {
        printf("%sAtendimento comum%s\n", BLUE, RESET);
        patient_card(dequeue(regular));
      } else {
        printf("Todas as filas estão vazias\n");
        break;
      }

      pref_counter++;
      break;
    }

    // See queues' contents
    case 3: {
      int action = ask_int_range("[1] Listar\n[2] Filtrar\n[3] Buscar\n> ", 1, 3);

      switch (action) {
      // Show patients
      case 1: {
        char queue_str[80];
        sprintf(queue_str, "%s[1] Normal\n%s[2] Preferencial\n%s[3] Urgência%s\n[4] Todas\n> ", RED, MAGENTA, BLUE, RESET);
        int pick = ask_int_range(queue_str, 1, 4) - 1;
        Queue *queues[3] = {regular, preferential, urgency};
        char *colors[] = {BLUE, MAGENTA, RED};

        // All patients
        if (pick == 3) {
          for (int i = 2; i >= 0; i--) {
            printf("%s#%s ", colors[i], RESET);
            print_queue(queues[i]);
          }
        }
        // Specific queue
        else { 
          printf("%s#%s ", colors[pick], RESET);
          print_queue(queues[pick]);
        }
        
        break;
      }

      // Filter
      case 2: {
        char *specialty = ask_str("Especialidade: ", 10);
        Queue *queues[3] = {urgency, preferential, regular};
        Queue *res = q_init();

        for (int i = 0; i < 3; i++) {
          for (Node *node = queues[i]->start; node != NULL; node = node->next) {
            if (strcmp(node->patient->specialty, specialty) == 0) {
              enqueue(res, node->patient);
            }
          }
        }

        print_queue(res);
        break;
      }
 
      // Search patient
      case 3: {
        int password = ask_int("Senha: ");
        Queue *queues[3] = {urgency, preferential, regular};

        for (int i = 0; i < 3; i++) {
          for (Node *node = queues[i]->start; node != NULL; node = node->next) {
            if (node->patient->password == password) {
              patient_card(node->patient);
              break;
            }
          }
        }
      }
      }
      break;
    }
    }
  } while (option != 0);
  return 0;
}