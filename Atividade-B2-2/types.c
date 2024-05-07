#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  int password;
  int age;
  char name[50];
  char specialty[10];
} Patient;

Patient *patient_init(int id, int password, int age, char *name, char *specialty) {
  Patient *pt = (Patient *)malloc(sizeof(Patient));
  pt->id = id;
  pt->password = password;
  pt->age = age;
  strcpy(pt->name, name);
  strcpy(pt->specialty, specialty);
  return pt;
}
