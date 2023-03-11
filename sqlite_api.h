//
// Created by YoungZM on 2023/3/12.
//

#ifndef LIBREMARKETC_SQLITE_API_H
#define LIBREMARKETC_SQLITE_API_H

#include "sqlite/sqlite3.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

int connectDatabase();

int createTable();

int insertTable(char *id, char *name, double price);

int selectTable();

int updateTable();

int deleteTable();

#endif //LIBREMARKETC_SQLITE_API_H
