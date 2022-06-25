#include "../../include/pizza_order.h"


int my_strncmp(const char *s1, const char *s2, size_t n) {
  size_t index = 0;

  while (s1[index] != '\0' || s2[index] != '\0' || index < n) {
    if (s1[index] != s2[index]) {
      return s1[index] - s2[index];
    }
    index += 1;
  }
  return 0;
}
