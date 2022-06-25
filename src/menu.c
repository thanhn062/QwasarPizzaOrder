#include "../include/pizza_order.h"

const char *arr_size[4] = {
  "Small",
  "Medium",
  "Big",
  "Gigantic"
};
 
const char *arr_ingredient[7] = {
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
 
typedef struct s_pizza {
  char* size[4]; // char**size char* char*
  float price[7];
  float subtotal;
  char ingredient[7];
} pizza;
 
void menu() {
   pizza* s_pizza_p = malloc(sizeof(pizza));
   int index = 0;
 
   //strncpy(s_pizza_p->size[0], arr_size[0], my_strlen(arr_size[0]));
   //strncpy(s_pizza_p->ingredient, arr_ingredient[0], my_strlen(arr_ingredient[0]));
   strcpy( s_pizza_p->size[0], "Big");
   strcpy( s_pizza_p->ingredient, "pepperoni");
 
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
 
   while (arr_size[index] != *pizza_order->size) {
       printf("%s", *pizza_order->size);
    index += 1;
    pizza_order->subtotal = size_price[index];
   }
   return pizza_order->subtotal;
}
 
// float order_total_price() {
    // float total_price = subtotal + total_ingredient + pizza_base_price;
    // return subtotal + total_ingredient + pizza_base_price;
// } // change

int main(void) {
  menu();
  ingredient_total_price();
  size_total_price();
  // printf("Total Cost: $%f\n", order_total_price());
  // printf("Subtotal Cart Cost: $%f\n", order_total_price());

  return 0;
}
