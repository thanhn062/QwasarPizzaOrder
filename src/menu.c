#include "../include/pizza_order.h"

const char *pizza_size[4] = {
  "Small",
  "Medium",
  "Big",
  "Gigantic"
};
 
const char *pizza_ingredient[7] = {
  "pepperoni",
  "bannana peps",
  "sausage",
  "onion",
  "green olives",
  "cheese",
  "bell peps"
};
 
const float size_price[] = {0.00, 1.00, 2.00, 3.00};
const float pizza_base_price = 9.99;
const float ingredient_price = 1.00;
const int   user_ingredient_choice[7] = {0, 1, 0, 1, 0, 0, 0};

typedef struct s_pizza {
  char* pizza_size;
  float price[7];
  float subtotal;
  char ingredient[7];
} pizza;
 
pizza* menu(int size, int user_ingredient_choice[7]) {
  pizza* s_pizza_p = malloc(sizeof(pizza));
  int len = my_strlen(pizza_size[size]);
  s_pizza_p->size = malloc(sizeof(char) * len);
  int index = 0;
  // s_pizza_p->size = pizza_size[size];
  my_strncpy(s_pizza_p->size, pizza_size[size]);

  while (index < 7) {
    if (user_ingredient_choice[index] == 1) {
      printf("%s\n", pizza_ingredient[index]);
    }
    index += 1;
  }
  //my_strncpy(s_pizza_p->size[0], pizza_size[0], my_strlen(pizza_size[0]));
  //my_strncpy(s_pizza_p->ingredient, pizza_ingredient[0], my_strlen(pizza_ingredient[0]));
  
  // my_strncpy(s_pizza_p->ingredient, "pepperoni");
}
 
 int ingredient_total_price() {
  pizza pizza_order;
  int index = 0;
  float total_ingredient;


  while (pizza_order.ingredient[index] != '\0') {
    total_ingredient = index * ingredient_price;
    index += 1;
  }
  return total_ingredient;
 }

 int size_total_price() {
   pizza* pizza_order;
   int index = 0;
 
   while (pizza_size[index] != *pizza_order->size) {
       printf("%s", *pizza_order->size);
    index += 1;
    pizza_order->subtotal = size_price[index];
   }
   return pizza_order->subtotal;
}
 
float order_total_price() {
    float total_price = subtotal + total_ingredient + pizza_base_price;
    return subtotal + total_ingredient + pizza_base_price;
} // change

int main(void) {
  printf("%s\n", menu(0, user_ingredient_choice->pizza_size);
  ingredient_total_price();
  size_total_price();
  // printf("Total Cost: $%f\n", order_total_price());
  // printf("Subtotal Cart Cost: $%f\n", order_total_price());

  return 0;
}
