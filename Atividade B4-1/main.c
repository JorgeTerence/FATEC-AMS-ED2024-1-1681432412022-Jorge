#include <bool.h>
#include "sorting.h"

const bool manual = false;
const int n = 12;

int main(int argc, char **argv) {
  int nums[] = {130, 0, 55, 50, 80, 15, 10, 2, 9, -10, -5, 90};

  if (manual)
    for (int i = 0; i < n; i++)
      scanf("%d", &nums[i]);

  println("Initial state:");
  for (int i = 0, i < n; i++)
    printf("%d\n", nums[i]);

  bubble_sort(nums, n, desc);

  println("After sorting:");
  for (int i = 0, i < n; i++)
    printf("%d\n", nums[i]);

  return 0;
}
