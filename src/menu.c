#include "../include/pizza_order.h"

const float base_price = 9.99;
const float topping_price = 1.00;
const float size_price[4] = {
    0.00,
    1.00,
    2.00,
    3.00
};

const char *sizes[4] = {
    "Small",
    "Medium",
    "Large",
    "Gigantice"
};

const char *toppings[7] = {
    "pepperoni",
    "bannana peps",
    "sausage",
    "onion",
    "green olives",
    "cheese",
    "bell peps"
};

typedef struct s_pizza {
    char* size;
    char** toppings;//char* toppings[7]
    float subtotal;
} pizza;

pizza* menu(const int size, const int choice[7]) {
    pizza* s_pizza_p    = malloc(sizeof(pizza));
    s_pizza_p->toppings = malloc(sizeof(char*) * 7);
    s_pizza_p->size     = malloc(sizeof(char) * my_strlen(sizes[size]));
    s_pizza_p->subtotal = base_price + size_price[size];
    int index = 0;

    my_strncpy(s_pizza_p->size, sizes[size], my_strlen(sizes[size]));// s_pizza_p->size = sizes[size];
    while (index < 7) {
        if (choice[index] == 1) {
            s_pizza_p->toppings[index] = malloc(sizeof(char) * my_strlen(toppings[index]));
            my_strncpy(s_pizza_p->toppings[index], toppings[index], my_strlen(toppings[index]));
            s_pizza_p->subtotal += topping_price;
        }
        else {
            s_pizza_p->toppings[index] = NULL;
        }
        index += 1;
    }
    return s_pizza_p;
}

void print_receipt(int fd, pizza* s_pizza_p, const int choice[7]) {
    int index = 0;

    dprintf(fd, "Pizza Size: %s\n\nIngredients:\n\n", s_pizza_p->size);
    while (index < 7) {
        if (choice[index] == 1) {
            dprintf(fd, "%s\n", s_pizza_p->toppings[index]);
        }
        index += 1;
    }
    dprintf(fd, "\nSubtotal: $%f", s_pizza_p->subtotal);
    close(fd);
}

int main(void) {
    // const int choice[7] = {1, 1, 1, 1, 0, 0, 1};
    const int choice[7] = {0, 0, 0, 0, 0, 0, 0};
    int fd = open("./receipt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    close(open("./receipt", O_RDONLY | O_WRONLY | O_TRUNC));// close(open("./receipt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
    pizza* s_pizza_p = menu(0, choice);
    print_receipt(fd, s_pizza_p, choice);
    int index = 0;

    free(s_pizza_p->size);
    while (index < 7) {
        if (choice[index] == 1) {// bypass warning free NULL pointer
            free(s_pizza_p->toppings[index]);
        }
        index += 1;
    }
    free(s_pizza_p->toppings);
    free(s_pizza_p);
    return EXIT_SUCCESS;
}