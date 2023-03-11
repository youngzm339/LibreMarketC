//
// Created by YoungZM on 2023/3/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

int main(int argc, char *argv[]) {
//    Set active code page to 65001 in order to output Chinese
//    If the parameter -dc (disable chcp) is added at startup, the chcp instruction is no longer invoked
    if (!(argc == 2 && strcmp(argv[1], "-dc") == 0)) {
        system("chcp 65001");
    }

//    Say hello to my users
    printf("\n%s\n", "-----LibreMarketC-----");
    printf("%s\n", "一个开源免费的商场销售系统");
    printf("%s\n", "Developed by YoungZM");
    printf("%s\n", "Opensoure at https://github.com/youngzm339/LibreMarketC");
    printf("%s\n", "-----LibreMarketC-----");

//    Enter the menu interface and determine the exit status
    int error_code;
    do {
        error_code = 0;
        error_code = enterMenu();
        if (error_code == 0) {
            printf("程序已正常退出");
            return 0;
        } else if (error_code != 1) {
            fprintf(stderr, "\n%s:%d\n", "程序异常退出", error_code);
            switch (error_code) {
                case -1:
                    fprintf(stderr, "\n商品销售功能模块异常\n");
                    break;
                case -2:
                    fprintf(stderr, "\n商业报表功能模块异常\n");
                    break;
                case -3:
                    fprintf(stderr, "\n商品管理功能模块异常\n");
                    break;
                default:
                    fprintf(stderr, "\n未知异常\n");
            }
        }
    } while (error_code == 1);
    return error_code;
}