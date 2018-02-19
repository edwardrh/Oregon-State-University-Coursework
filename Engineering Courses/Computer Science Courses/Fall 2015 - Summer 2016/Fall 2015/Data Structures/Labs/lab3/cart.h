//
//  cart.h
//  Lab 3
//
//  Created by Todd Kulesza on 1/19/14.
//

#ifndef Lab_3_cart_h
#define Lab_3_cart_h

struct CartItem;
struct ShoppingCart;

struct ShoppingCart* createCart(int capacity);
struct CartItem* createItem(char *name, double price);
void freeCart(struct ShoppingCart *cart);
void freeItem(struct CartItem *item);
void addItemToCart(struct ShoppingCart *cart, struct CartItem *item);
double getTotalPrice(struct ShoppingCart *cart);
int getNumItems(struct ShoppingCart *cart);
int containsItem(struct ShoppingCart *cart, struct CartItem *item);
void removeItemFromCart(struct ShoppingCart *cart, struct CartItem *item);

#endif