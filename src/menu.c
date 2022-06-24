// #include <string.h>
#include <stdio.h>
#include <stdlib.h>

size_t my_strlen(const char *s) {
  size_t len = 0;

  while (s[len] != '\0') {
    len += 1;
  }
  return len;
}

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


char *arr_size[4] = {
  "Small",
  "Medium",
  "Big",
  "Gigantic"
};

char *arr_ingredient[7] = {
  "pepperoni",
  "bannana peps",
  "sausage",
  "onion",
  "green olives",
  "cheese",
  "bell peps"
};

float size_price[] = {0.00, 1.00, 2.00, 3.00};
float total_size; //
float pizza_base_price = 9.99;
float ingredient_price = 1.00;
float total_ingredient;

// add a cart?

typedef struct s_pizza {
  char* size[4]; // char**size char* char*
  float price[7];
  char ingredient[7];
} pizza;

// void menu() {
//   pizza* s_pizza_p = malloc(sizeof(pizza));
//   // int index = 0;

//   my_strncpy(s_pizza_p->size[0], arr_size[0], my_strlen(arr_size[0]));
//   my_strncpy(s_pizza_p->ingredient, arr_ingredient[0], my_strlen(arr_ingredient[0]));
// }

// int ingredient_total_price() {
//   pizza pizza_order;
//   int index = 0;

//   while (pizza_order.ingredient[index] != '\0') {
//     total_ingredient = index * ingredient_price;
//     index += 1;
//   }
//   return total_ingredient;
// }

// int size_total_price() {
//   pizza pizza_order;
//   int index = 0;

//   while (arr_size[index] != *pizza_order.size) {
//     index += 1;
//     total_size = size_price[index];
//   }
//   return total_size;
// }

float order_total_price() {
  // float total_price = total_size + total_ingredient + pizza_base_price;
  return total_size + total_ingredient + pizza_base_price;
}

// int main(void) {
//   menu();
//   // ingredient_total_price();
//   // size_total_price();
//   printf("Total Cost: $%f\n", order_total_price());
//   printf("Subtotal Cart Cost: $%f\n", order_total_price());

//   return 0; 
// }