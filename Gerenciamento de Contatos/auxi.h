#pragma once

char *ask_str(char *msg, int size);
char *ask_numeric_str(char *msg, int size);
int ask_int(char *msg);
int ask_int_range(char *msg, int min, int max);