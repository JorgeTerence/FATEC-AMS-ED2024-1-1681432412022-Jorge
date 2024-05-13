#pragma once
#include <time.h>

typedef struct {
  int password;
  int age;
  char name[50];
  char specialty[10];
  time_t entry;
  time_t exit;
} Patient;

Patient *patient_init(int password, int age, char *name, char *specialty);