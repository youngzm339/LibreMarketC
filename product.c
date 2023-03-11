//
// Created by YoungZM on 2023/3/11.
//

#include <stdio.h>
#include "product.h"
#include "sqlite_api.h"

int enterProduct() {
    printf("\n%s\n", "-----Product-----");
    printf("%s\n", "    商品管理功能菜单");
    printf("%s\n", "-----Product-----");
    printf("%s\n", "[1]查询商品");
    printf("%s\n", "[2]增加商品");
    printf("%s\n", "[3]删除商品");
    printf("%s\n", "[4]修改商品");
    printf("%s\n", "[5]初始化商品表");
    printf("%s\n", "[0]返回主菜单");

    printf("\n请输入您需要的功能选项：\n");
    int selected_option;
    scanf("%d", &selected_option);
    int product_code;
    switch (selected_option) {
        case 1:
            product_code = queryProduct();
            break;
        case 2:
            product_code = addProduct();
            break;
        case 3:
            product_code = delProduct();
            break;
        case 4:
            product_code = editProduct();
        case 5:
            createTable();
        case 0:
            product_code = 1;
            break;
        default:
            fprintf(stderr, "\n功能选项输入错误，模块已经退出！\n");
            product_code = 1;
    }
    return product_code;

}

int queryProduct() {
    if (selectTable() == 0) {
        return 1;
    } else {
        return -3;

    }
}

int addProduct() {
    char *id = NULL;
    char *name = NULL;
    double price;
    printf("请按顺序依次输入（商品编码 商品名称 价格）");
    scanf("%s %s %lf", id, name, &price);
    if (insertTable(id, name, price) == 0) {
        return 1;
    } else {
        return -3;
    }
}

int delProduct() {
    return -3;
}

int editProduct() {
    return -3;
}