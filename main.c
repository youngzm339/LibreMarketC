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
    fprintf(stdout, "\n%s\n", "-----LibreMarketC-----");
    fprintf(stdout, "%s\n", "一个开源免费的商场销售系统");
    fprintf(stdout, "%s\n", "Developed by YoungZM");
    fprintf(stdout, "%s\n", "Opensoure at https://github.com/youngzm339/LibreMarketC");
    fprintf(stdout, "%s\n", "-----LibreMarketC-----");

//    Enter the menu interface
    while (1) {
        enterMenu();
    }
}