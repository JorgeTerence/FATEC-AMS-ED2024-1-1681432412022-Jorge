// ------------------------------------ //
// Calculadora HP12c                    //
// Autores: Jorge e Rodrigo Z           //
// Instituição: Fatec Antonio Russo     //
// Professor: Carlos Veríssimo          //
// Data: 22/04/2024                     //
//                                      //
// Professor, não foi possível alcançar //
// o resultado completo, pois existem   //
// edge-cases que não foram tratados.   //
//                                      //
// Para dar o input de dados, defina    //
// MANUAL_MODE como 1.                  //
// ------------------------------------ //

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MANUAL_MODE 0
#define MAX_EXP 16

#include "stack.h"

bool str_contains(char *str, char c) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == c)
      return true;
  }
  return false;
}

bool is_operator(char c) { return str_contains("+-*/", c); }

bool is_number(char c) { return str_contains("0123456789", c); }

float eval(Stack *memory, char equation[][MAX_EXP]) {
  for (int i = 0; i < memory->capacity; i++) {
    if (is_operator(equation[i][0])) {
      switch (equation[i][0]) {
      case '+':
        st_push(memory, st_pop(memory) + st_pop(memory));
        break;
      case '-':
        st_push(memory, -st_pop(memory) + st_pop(memory));
        break;
      case '*':
        st_push(memory, st_pop(memory) * st_pop(memory));
        break;
      case '/':
        st_push(memory, 1 / st_pop(memory) * st_pop(memory));
        break;
      }
    } else {
      st_push(memory, atof(equation[i]));
    }
  }

  return st_top(memory);
}

void read_equation(char eq[][MAX_EXP], int len) {
  for (int i = 0; i < len; i++) {
    printf("Digite um caractere: ");
    char temp[MAX_EXP];
    scanf("%s", temp);
    strcpy(eq[i], temp);
  }
}

/*
check_done = false
if eq[i] == ( check_done = true
if eq[i] == ) check_done = false

if eq[i] dentro de parenteses -> pular
if eq[i] is operator
  // procurar o número mais próximo que não foi processado e trocar de ordem
  for right to left from i
    if eq[j] is not operator && fora de ()
      if previous is not number
        move eq[i] to j+1
      else
        move eq[i] to j

        // falta colocar parenteses
*/

void show(char arr[][MAX_EXP], int len) {
  printf("[");
  for (int i = 0; i < len; i++) {
    if (i + 1 != len)
      printf("%s, ", arr[i]);
    else
      printf("%s]\n", arr[i]);
  }
}

void shift(char arr[][MAX_EXP], int from, int to) {
  char temp[MAX_EXP];
  strcpy(temp, arr[from]);

  for (int i = from; i >= to; i--)
    strcpy(arr[i], arr[i - 1]);

  strcpy(arr[to], temp);
}

char *translate(char rpn[][MAX_EXP], int size) {
  char infix[size * 2][MAX_EXP];
  char prev[MAX_EXP] = "";
  bool flag_done = false;

  for (int i = 0; i < size; i++)
    strcpy(infix[i], rpn[i]);

  for (int i = size; i < size * 2; i++)
    strcpy(infix[i], "");

  for (int i = 0; i < size * 2; i++) {
    // Skip operations between parenthesis (already processed)
    if (infix[i][0] == '(') {
      flag_done = true;
      continue;
    }
    if (infix[i][0] == ')') {
      flag_done = false;
      continue;
    }
    if (flag_done)
      continue;

    // procurar o número mais próximo que não foi processado e trocar de ordem
    if (is_operator(infix[i][0])) {
      bool flag_done_rev = false;

      for (int j = i; j >= 0; j--) {
        if (infix[j][0] == ')') {
          flag_done_rev = true;
          continue;
        }
        if (infix[j][0] == '(') {
          flag_done_rev = false;
          continue;
        }
        if (flag_done_rev)
          continue;

        if (is_number(infix[j][0])) {
          if (is_operator(prev[0]))
            shift(infix, i, j + 1);
          else
            shift(infix, i, j);

          // Surround with parenthesis
          strcpy(&infix[size * 2 - 1][0], ")");
          shift(infix, size * 2 - 1, i + 1);
          strcpy(&infix[size * 2 - 1][0], "(");
          shift(infix, size * 2 - 1, j - 1);

          break;
        }
      }

      strcpy(prev, infix[i]);
    }
  }

  strcpy(infix[0], "(");

  return infix;
}
char *stringify(char arr[][MAX_EXP], int len) {
  char *str = (char *)malloc(MAX_EXP * len);
  for (int i = 0; i <= len; i++) {
    strcat(str, arr[i]);
  }
  return str;
}

int main(void) {
  int st_size;

  if (MANUAL_MODE) {
    printf("Digite o tamanho do stack: ");
    scanf("%d", &st_size);
  } else {
    st_size = 5;
    // st_size = 7;
  }

  Stack *memory = st_innit(st_size);
  char input[st_size][MAX_EXP];

  if (MANUAL_MODE) {
    read_equation(input, st_size);
  } else {
    char predef_eq[5][MAX_EXP] = {"10", "2", "3", "*", "-"};
    // char predef_eq[7][MAX_EXP] = {"7", "3", "*", "9", "+", "2", "*"};
    for (int i = 0; i < st_size; i++) {
      strcpy(input[i], predef_eq[i]);
    }
  }

  float res = eval(memory, input);
  printf("Resultado: %.2f\n", st_top(memory));

  char *algebric = translate(input, st_size);
  char *algebricString = stringify(algebric, sizeof(algebric));
  printf("Expressão algébrica: %s", algebricString);

  free(memory);

  return 0;
}
