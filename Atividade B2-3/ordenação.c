/* -------------------------------------------
Fatec São Caetano do Sul - Estrutura de Dados
Professor: Carlos Veríssimo
Proposta: Inclusão ordenada em array e lista ligada
Autor: Jorge Terence
Data: 25/05/2024
------------------------------------------- */

#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define arr_len 4

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node *node(int n) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = n;
  node->next = NULL;
  return node;
}

void ll_print(Node *head) {
  Node *current = head;
  printf("[%d", current->data);

  for (current = current->next; current != NULL; current = current->next)
    printf(" -> %d", current->data);

  printf("]\n");
}

int test_ll_time(Node *head, int n) {
  printf("Início: ");
  ll_print(head);
  int start = time(NULL);

  for (Node *temp = head; temp != NULL; temp = temp->next) {
    if (temp->data > n) {
      Node gambiarra = *temp;
      *temp = *node(n);
      temp->next = &gambiarra;
      
      int end = time(NULL) - start;
      
      printf("Fim: ");
      ll_print(head);
      return end;
    }
  }

  head->next = node(n);

  int end = time(NULL) - start;

  printf("Fim: ");
  ll_print(head);  
  return end;
}

void array_print(int *arr, int n) {
  printf("[");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\b]\n");
}

int test_array_time(int *arr, int n) {
  printf("Início: ");
  array_print(arr, arr_len);
  int start = time(NULL);
  int res[arr_len + 1];

  int found = 0;
  
  for (int i = 0; i < arr_len + 1; i++) {
    if (!found && arr[i] > n) {
      found = 1;
      res[i] = n;
    } else {
      res[i] = arr[i - found];
    }
  }

  int end = time(NULL) - start;

  printf("Fim: ");
  array_print(res, arr_len + 1);  
  return end;
}

int main(void) {
  Node *head = node(10);
  head->next = node(25);
  head->next->next = node(40);
  head->next->next->next = node(80);

  int test_array[] = {10, 25, 40, 80};
    
  int time_ll = test_ll_time(head, 30);
  int time_array = test_array_time(test_array, 30);

  printf("Resultado lista ligada: %d\n", time_ll);
  printf("Resultado array: %d\n", time_array);
  return 0;
}
