//
// Created by YoungZM on 2023/3/11.
//

#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "sqlite_api.h"

extern char sql_tmp_id[99];
extern char sql_tmp_name[99];
extern char sql_tmp_price[99];

void enterProduct() {
    fprintf(stdout, "\n%s\n", "-----Product-----");
    fprintf(stdout, "%s\n", "    商品管理功能菜单");
    fprintf(stdout, "%s\n", "-----Product-----");
    fprintf(stdout, "%s\n", "[1]查询商品");
    fprintf(stdout, "%s\n", "[2]增加商品");
    fprintf(stdout, "%s\n", "[3]删除商品");
    fprintf(stdout, "%s\n", "[4]修改商品");
    fprintf(stdout, "%s\n", "[5]初始化商品表");
    fprintf(stdout, "%s\n", "[0]返回主菜单");

    fprintf(stdout, "\n请输入您需要的功能选项：\n");
    int selected_product_option;
    scanf("%d", &selected_product_option);
    int product_code;
    switch (selected_product_option) {
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
            break;
        case 5:
            product_code = initProduct();
            break;
        case 0:
            product_code = 301;
            break;
        default:
            fprintf(stderr, "\n功能选项输入错误，请重新输入！\n");
            product_code = 502;
    }
    switch (product_code) {
        case 301:
            break;
        case 502:
            enterProduct();
            break;
        case -1:
            fprintf(stderr, "查询商品出错");
            break;
        case -2:
            fprintf(stderr, "添加商品出错");
            break;
        case -3:
            fprintf(stderr, "删除商品出错");
            break;
        case -4:
            fprintf(stderr, "修改商品出错");
            break;
        case -5:
            fprintf(stderr, "初始化商品表出错");
            break;
        default:
//            fprintf(stderr, "商品管理未知错误");
    }
}

int queryProduct() {
    char id[99];
    fprintf(stdout, "\n请输入商品编码以查询商品\n");
    fscanf(stdin, "%s", id);
    if (selectTable(id) == 0) {
//        printf("%s", getTableName(id));
//        struct Product *return_product = malloc(sizeof(struct Product));
//        return_product = queryTable(id);
        fprintf(stdout, "\n---查询商品结果:---\n");
        fprintf(stdout, "\n商品编号：%s", sql_tmp_id);
        fprintf(stdout, "\n商品名称：%s", sql_tmp_name);
        fprintf(stdout, "\n商品价格：%s", sql_tmp_price);
        fprintf(stdout, "\n--END商品结果END--\n");
        return 0;
    } else {
        return -1;
    }
}

int addProduct() {
    char id[99];
    char name[99];
    double price;
    fprintf(stdout, "\n请按顺序依次输入（商品编码 商品名称 价格）以增加商品\n");
    scanf("%s %s %lf", id, name, &price);
    if (insertTable(id, name, price) == 0) {
        return 0;
    } else {
        return -2;
    }
}

int delProduct() {
    char id[99];
    fprintf(stdout, "\n请输入商品编码以删除商品\n");
    scanf("%s", id);
    if (deleteTable(id) == 0) {
        return 0;
    } else {
        return -3;
    }
}

int editProduct() {
    char id[99];
    char name[99];
    double price;
    fprintf(stdout, "\n请输入商品编码以修改商品\n");
    scanf("%s", id);
    if (selectTable(id) == 0) {
        int selected_edit;
        fprintf(stdout, "\n%s\n", "-----editProduct-----");
        fprintf(stdout, "%s\n", "    修改商品功能菜单");
        fprintf(stdout, "%s\n", "-----editProduct-----");
        fprintf(stdout, "%s\n", "[1]修改商品名称");
        fprintf(stdout, "%s\n", "[2]修改商品价格");
        fprintf(stdout, "%s\n", "[0]返回商品管理功能菜单");
        scanf("%d", &selected_edit);
        switch (selected_edit) {
            case 1:
                fprintf(stdout, "\n请输入新的商品名称:");
                scanf("%s", name);
                if (updateTableName(id, name) == 0) {
                    return 0;
                } else {
                    return -4;
                }
            case 2:
                fprintf(stdout, "\n请输入新的商品价格:");
                scanf("%lf", &price);
                if (updateTablePrice(id, price) == 0) {
                    return 0;
                } else {
                    return -4;
                }
            case 0:
                return 0;
            default:
                return -4;
        }
    } else {
        fprintf(stderr, "未查询到需要修改的商品");
        return -4;
    }
}

int initProduct() {
    if (createTable() == 0) {
        return 0;
    } else {
        return -5;
    }
}