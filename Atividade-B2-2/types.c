#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int password;
  int age;
  char name[50];
  char specialty[10];
  time_t entry;
  time_t exit;
} Patient;

Patient *patient_init(int password, int age, char *name, char *specialty) {
  Patient *pt = (Patient *)malloc(sizeof(Patient));
  
  pt->password = password;
  pt->age = age;
  strcpy(pt->name, name);
  strcpy(pt->specialty, specialty);
  pt->entry = time(NULL);
  pt->exit = 0;
  return pt;
}
