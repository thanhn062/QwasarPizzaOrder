#include "../inc/clui.h"

// TODO: put all in 1 printf
// printf("%d\n", my_strncmp("quit", "quis", my_strlen("quit")));
// printf("Total Cost: $%f\n", order_total_price());
// printf("Subtotal Cart Cost: $%f\n", order_total_price());

//  int size_total_price() {
//    order* order_order;
//    int index = 0;
 
//    while (order_size[index] != order_order->order_size) {
//       printf("%s", order_order->order_size);
//     index += 1;
//     order_order->subtotal = size_price[index];
//    }
//    return order_order->subtotal;
// }
 
// float order_total_price() {
//     float total_price = subtotal + total_ingredient + order_base_price;
//     return subtotal + total_ingredient + order_base_price;
// } // change

// #define topping_size 7
#define SIZES_NUMBER    4 // do we always need ifndef?
#define TOPPINGS_NUMBER 7 // test edge cases // also works when size bigger than actual toppings number

const float base_price    = 9.99;
const float topping_price = 1.00;
const float size_price[SIZES_NUMBER] = {
    0.00,
    1.00,
    2.00,
    3.00
};//should we end struct with NULL?

const char *g_sizes[SIZES_NUMBER] = {
    "Small",
    "Medium",
    "Large",
    "Giant" // Gigantic
};//should we end struct with NULL?

const char *g_toppings[TOPPINGS_NUMBER] = {
    "pepperoni",
    "banana peps", //n or nn?
    "sausage",
    "onion",
    "green olives",
    "cheese",
    "bell peps"
};
// pizza order vs cart
typedef struct s_order {
    char*  size;
    char** toppings;
    float  subtotal;
    float  total;
} order;

order* menu(const int size, const int choice[7]) {
    order* s_order_p    = malloc(sizeof(order));
    s_order_p->toppings = malloc(sizeof(char*) * 7); //what if initliatizing all to NULL?
    s_order_p->size     = malloc(sizeof(char) * my_strlen(g_sizes[size]));
    s_order_p->subtotal = base_price + size_price[size];
    int len   = 0;
    int index = 0;

    my_strncpy(s_order_p->size, g_sizes[size], my_strlen(g_sizes[size]));// s_order_p->size = g_sizes[size];
    while (index < 7) {
        if (choice[index] == 1) {
            len = my_strlen(g_toppings[index]);
            s_order_p->toppings[index] = malloc(sizeof(char) * len);
            my_strncpy(s_order_p->toppings[index], g_toppings[index], len);
            s_order_p->subtotal += topping_price;
        }
        else {
            s_order_p->toppings[index] = NULL;
        }
        index += 1;
    }
    return s_order_p;
}
// improve below it by outputing to a gtroff-ms doc to create pdf
void print_receipt(int fd, order* s_order_p, const int choice[TOPPINGS_NUMBER]) {
    int index = 0;

    dprintf(fd, "Pizza Size: %s\n\nIngredients:\n\n", s_order_p->size);
    while (index < TOPPINGS_NUMBER) {
        if (choice[index] == 1) {
            dprintf(fd, "%s\n", s_order_p->toppings[index]);
        }
        index += 1;
    }
    dprintf(fd, "\nSubtotal: $%.2f", s_order_p->subtotal); // ROUND NUMBER vs TRUNC <-- fn floor
    close(fd);
}

void my_send_receipt(const int choice[TOPPINGS_NUMBER]) {
    int fd = open("./receipt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); // look at it again
    close(open("./receipt", O_RDONLY | O_WRONLY | O_TRUNC));// close(open("./receipt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
    order* s_order_p = menu(SIZES_NUMBER - 1, choice); // if size for we see values pushed to the stakc peperoni....? SIZES_NUMBER -1?
    print_receipt(fd, s_order_p, choice);
    int index = 0;

    free(s_order_p->size);
    while (index < TOPPINGS_NUMBER) { // define size
        if (choice[index] == 1) {// bypass warning free NULL pointer
            free(s_order_p->toppings[index]);
        }
        index += 1;
    }
    free(s_order_p->toppings);
    free(s_order_p);
}

int main(void) {
    const int choice[TOPPINGS_NUMBER] = {0, 0, 0, 0, 0, 0, 0};// set 0,1 accordingly
    my_send_receipt(choice);
    return EXIT_SUCCESS; // 0 or 1 -1 define in stdlib.h
}