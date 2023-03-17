//
// Created by YoungZM on 2023/3/11.
//
#include <stdio.h>
#include <time.h>
#include "report.h"

void enterReport() {
    fprintf(stdout, "\n%s\n", "-----Report-----");
    fprintf(stdout, "%s\n", "    商业报表功能菜单");
    fprintf(stdout, "%s\n", "-----Report-----");
    if (exportReport() == 0) {
        fprintf(stdout, "\n导出成功\n");
    } else {
        fprintf(stdout, "\n导出失败\n");
    }
}

int exportReport() {
    char inStr[999];
    char filename[128] = "saved_paid_history.txt";
    FILE *file = fopen(filename, "r+");
    while (fgets(inStr, sizeof(inStr), file) != NULL) {
        time_t return_time;
        double return_money;
        sscanf(inStr, "%lld %lf", &return_time, &return_money);
        struct tm *info;
        info = localtime(&return_time);
        fprintf(stdout, "\n---详细销售记录---\n");
        fprintf(stdout, "%s 收入金额：%lf", asctime(info), return_money);
        fprintf(stdout, "\n---END详细销售记录END---\n");
    }
    return 0;
}