#pragma once
#include <stdbool.h>
#include "types.h"

int ask_int(char *msg);

int ask_int_range(char *msg, int min, int max);

char *ask_str(char *msg, size_t size);

bool ask_yes_no(char *msg);

Patient *ask_patient();

void patient_card(Patient *pt);