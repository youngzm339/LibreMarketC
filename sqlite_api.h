//
// Created by YoungZM on 2023/3/12.
//

#ifndef LIBREMARKETC_SQLITE_API_H
#define LIBREMARKETC_SQLITE_API_H

#include "sqlite/sqlite3.h"

struct Product {
    char id[99];
    char name[99];
    double price;
};

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

int connectDatabase();

int createTable();

int insertTable(char *id, char *name, double price);

char *getTableName(char *id);

double getTablePrice(char *id);

int selectTable(char *id);

struct Product *queryTable(char *id);

int updateTableName(char *id, char *name);

int updateTablePrice(char *id, double price);

int deleteTable(char *id);

#endif //LIBREMARKETC_SQLITE_API_H
