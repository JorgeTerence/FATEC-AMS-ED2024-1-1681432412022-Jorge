#ifndef SORT_H
#define SORT_H

#include <bool.h>

enum order
{
  asc = false,
  desc = true
};

int bubble_sort(int nums[], size_t len, bool ordering);

#endif