//
// Created by YoungZM on 2023/3/11.
//

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "cart.h"
#include "report.h"
#include "product.h"


void enterMenu() {
    fprintf(stdout, "\n%s\n", "-----Menu-----");
    fprintf(stdout, "%s\n", "    功能菜单");
    fprintf(stdout, "%s\n", "-----Menu-----");
    fprintf(stdout, "%s\n", "[1]商品销售功能");
    fprintf(stdout, "%s\n", "[2]商业报表功能");
    fprintf(stdout, "%s\n", "[3]商品管理功能");
    fprintf(stdout, "%s\n", "[0]退出程序");

    printf("\n请输入您需要的功能选项：\n");
    int selected_menu_option;
    scanf("%d", &selected_menu_option);
    switch (selected_menu_option) {
        case 1:
            enterCart();
            break;
        case 2:
            enterReport();
            break;
        case 3:
            enterProduct();
            break;
        case 0:
            exit(0);
        default:
            fprintf(stderr, "\n功能选项输入错误，请在给出的选项中做出选择！\n");
    }
}
