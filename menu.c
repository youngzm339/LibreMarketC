//
// Created by YoungZM on 2023/3/11.
//

#include <stdio.h>
#include "menu.h"
#include "cart.h"
#include "report.h"
#include "product.h"


int enterMenu() {
    printf("\n%s\n", "-----Menu-----");
    printf("%s\n", "    功能菜单");
    printf("%s\n", "-----Menu-----");
    printf("%s\n", "[1]商品销售功能");
    printf("%s\n", "[2]商业报表功能");
    printf("%s\n", "[3]商品管理功能");
    printf("%s\n", "[0]退出程序");

    printf("\n请输入您需要的功能选项：\n");
    int selected_option;
    scanf("%d", &selected_option);
    int menu_code;
    switch (selected_option) {
        case 1:
            menu_code = enterCart();
            break;
        case 2:
            menu_code = enterReport();
            break;
        case 3:
            menu_code = enterProduct();
            break;
        case 0:
            menu_code = 0;
            break;
        default:
            fprintf(stderr, "\n功能选项输入错误，请在给出的选项中做出选择！\n");
            menu_code = 1;
    }
    return menu_code;
}
