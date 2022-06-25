#include "../../include/pizza_order.h"

char *my_strncpy(char *restrict dest, const char *src, size_t n) {
  size_t index = 0;

  while (index < n && src[index] != '\0') {
    dest[index] = src[index];
    index += 1;
  }
  while (index < n) {
    dest[index] = '\0';
    index += 1;
  }
  return dest;
}
