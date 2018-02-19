//
//  cart.c
//  Lab 3
//
//  Created by Todd Kulesza on 1/19/14.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cart.h"

/* Holds an item that can be added to a shopping cart */
struct CartItem {
    char name[32];
    double price;
};

struct ShoppingCart {
    struct CartItem **items;
    int numItems;
    int capacity;
    double totalPrice;
};

/* Allocate memory for a new ShoppingCart and initialize it */
struct ShoppingCart* createCart(int capacity) {
    struct ShoppingCart *cart = malloc(sizeof (struct ShoppingCart));
    
    cart->items = malloc (sizeof (struct CartItem *) * capacity);
    cart->capacity = capacity;
    cart->numItems = 0;
    
    return cart;
}

/* Allocate memory for a new CartItem and initialize it */
struct CartItem* createItem(char *name, double price) {
    struct CartItem *item = malloc(sizeof (struct CartItem));

    strncpy(item->name, name, 32);
    item->price = price;
    
    return item;
}

/* Free the memory used by a ShoppingCart */
void freeCart(struct ShoppingCart *cart) {
    int i = 0;
    
    for (i = 0; i < cart->numItems; i++) {
        freeItem(cart->items[i]);
    }
    
    free(cart);
}

/* Free the memory used by a CartItem */
void freeItem(struct CartItem *item) {
    free(item);
}

/* Add a CartItem to a given ShoppingCart */
void addItemToCart(struct ShoppingCart *cart, struct CartItem *item) {
    cart->totalPrice += item->price;
    
    if (cart->numItems >= cart->capacity)     {
        printf("Error: out of space!\n");
        return;
    }
    
    cart->items[cart->numItems] = item;
    cart->numItems++;
}

/* Returns the price of all items in the ShoppingCart */
double getTotalPrice(struct ShoppingCart *cart) {
    return cart->totalPrice;
}

/* Return the number of items in the ShoppingCart */
int getNumItems(struct ShoppingCart *cart) {
    return cart->numItems;
}

/* Returns the index of 'item', if it exists in the ShoppingCart.
 * Returns -1 if 'item' was not found in the cart. */
int containsItem(struct ShoppingCart *cart, struct CartItem *item) {
    int i;
    int result = -1;
    
    for (i = 0; i < cart->numItems && result == -1; i++) {
        if (cart->items[i] == item) {
            result = i;
        }
    }
    
    return result;
}

/* Removes 'item' from the ShoppingCart */
void removeItemFromCart(struct ShoppingCart *cart, struct CartItem *item) {
    int i;
    int index = containsItem(cart, item);
    
    if (index > -1) {
        for (i = index; i < cart->numItems; i++) {
            cart->items[i] = cart->items[i + 1];
        }
    }
    
    cart->numItems--;
}