#include <bool.h>

enum order
{
  asc = false,
  desc = true
};

int bubble_sort(int nums[], size_t len, bool ordering) {
  for (int i = 0; i < len; i++) {
    bool ok = true;

    for (int j = 0; j < len - 1; j++) {
      bool swap = false;
      if (ordering)
        swap = nums[j] < nums[j + 1];
      else
        swap = nums[j] > nums[j + 1];

      if (swap) {
        Book temp = books[i];
        books[i] = books[j];
        books[j] = temp;

        ok = false;
      }
    }

    if (ok) break;
  }

  return 0;
}
