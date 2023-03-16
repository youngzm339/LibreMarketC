//
// Created by YoungZM on 2023/3/11.
//

#ifndef LIBREMARKETC_CART_H
#define LIBREMARKETC_CART_H

#include <stdlib.h>
#include "sqlite_api.h"

typedef struct CartProduct {
    struct Product *elem;
    struct CartProduct *next;
} CartProduct;

CartProduct *initLink();

CartProduct *insertElem(CartProduct *p, struct Product *elem, int add);

CartProduct *delElem(CartProduct *p, int add);

int selectElem(CartProduct *p, struct Product *elem);

void enterCart();

int checkoutCart(CartProduct *p, int num);

void display(struct Product *elem);

#endif //LIBREMARKETC_CART_H
