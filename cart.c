//
// Created by YoungZM on 2023/3/11.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "cart.h"
#include "sqlite_api.h"

extern char sql_tmp_id[99];
extern char sql_tmp_name[99];
extern char sql_tmp_price[99];

void enterCart() {
    fprintf(stdout, "\n%s\n", "-----Cart-----");
    fprintf(stdout, "%s\n", "    商品销售功能菜单");
    fprintf(stdout, "%s\n", "-----Cart-----");
    CartProduct *init = initLink();
    int num = 0;
    while (1) {
        char id[99];
        fprintf(stdout, "\n%s", "请输入商品条码以录入商品，或输入checkout以结算,或输入exit退出本界面");
        fscanf(stdin, "%s", id);
        if (strcmp(id, "exit") == 0) {
            break;
        } else if (strcmp(id, "checkout") == 0) {
            if (checkoutCart(init, num) == 0) {
                break;
            } else {
                fprintf(stderr, "\n结账失败！\n");
            }
        } else {
            if (selectTable(id) == 0) {
                struct Product *tmp_product = malloc(sizeof(struct Product));
                strcpy(tmp_product->id, id);
                strcpy(tmp_product->name, sql_tmp_name);
                tmp_product->price = getTablePrice(id);
                insertElem(init, tmp_product, num + 1);
                num++;
                fprintf(stdout, "\n已成功加入商品：\n");
                display(tmp_product);
            } else {
                fprintf(stderr, "商品或指令不存在，请检查你的输入");
            }
        }
    }
}

int checkoutCart(CartProduct *p, int num) {
    double amount = 0.0;
    if (num == 0) {
        fprintf(stdout, "没有商品需要结算，无需付款");
    } else {
        CartProduct *tmp_product = p;
        tmp_product = tmp_product->next;
        for (int i = 1; i <= num; ++i) {
            amount += tmp_product->elem->price;
            tmp_product = tmp_product->next;
        }
    }
    fprintf(stdout, "\n---结账信息:---\n");
    fprintf(stdout, "\n需要支付的商品数量：%d", num);
    fprintf(stdout, "\n需要支付的款项：%lf", amount);
    fprintf(stdout, "\n--END结账信息END--\n");
    fprintf(stdout, "\n输入你支付的金额：");
    double paid_money;
    fscanf(stdin, "%lf", &paid_money);
    if (paid_money - amount < 1e-6) {
        return -1;
    } else {
        double return_money = paid_money - amount;
        fprintf(stdout, "\n支付成功，应找回金额：%lf\n", return_money);
        time_t seconds;
        seconds = time(NULL);
        char str_seconds[60];
        sprintf(str_seconds, "%ld", seconds);
        char str_amount[60];
        sprintf(str_amount, "%lf", amount);
        char filename[128] = "saved_paid_history.txt";
        FILE *file = fopen(filename, "w+");
        fprintf(file, "%s %s\n", str_seconds, str_amount);
        fclose(file);
        return 0;
    }
}

CartProduct *initLink() {
    CartProduct *p = (CartProduct *) malloc(sizeof(CartProduct));
    p->elem = NULL;
    p->next = NULL;
    return p;
}

CartProduct *insertElem(CartProduct *p, struct Product *elem, int add) {
    CartProduct *temp = p;
    for (int i = 1; i < add; i++) {
        if (temp == NULL) {
            fprintf(stderr, "插入位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    CartProduct *c = (CartProduct *) malloc(sizeof(CartProduct));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;
}

CartProduct *delElem(CartProduct *p, int add) {
    CartProduct *temp = p;
    for (int i = 1; i < add; i++) {
        temp = temp->next;
    }
    CartProduct *del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return p;
}

int selectElem(CartProduct *p, struct Product *elem) {
    CartProduct *t = p;
    int i = 1;
    while (t->next) {
        t = t->next;
        if (t->elem == elem) {
            return i;
        }
        i++;
    }
    return -1;
}

void display(struct Product *elem) {
    fprintf(stdout, "\n---商品信息:---\n");
    fprintf(stdout, "\n商品编号：%s", elem->id);
    fprintf(stdout, "\n商品名称：%s", elem->name);
    fprintf(stdout, "\n商品价格：%lf", elem->price);
    fprintf(stdout, "\n--END商品信息END--\n");
}