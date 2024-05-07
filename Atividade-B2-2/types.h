#pragma once

typedef struct {
  int id;
  int password;
  int age;
  char name[50];
  char specialty[10];
} Patient;

Patient *patient_init(int id, int password, int age, char *name, char *specialty);