//
// Created by YoungZM on 2023/3/12.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite_api.h"
#include "sqlite/sqlite3.h"

char sql_tmp_id[99];
char sql_tmp_name[99];
char sql_tmp_price[99];

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
//    int i;
//    for (i = 0; i < argc; i++) {
//        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//    }
//    printf("\n");
    strcpy(sql_tmp_id, argv[0]);
    strcpy(sql_tmp_name, argv[1]);
    strcpy(sql_tmp_price, argv[2]);
    return 0;
}

int connectDatabase() {
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("LibreMarketC.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        // fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
    return 0;
}

int createTable() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    /* Open database */
    rc = sqlite3_open("LibreMarketC.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    /* Create SQL statement */
    sql = "CREATE TABLE PRODUCT("  \
         "ID TEXT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "PRICE         REAL );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
    sqlite3_close(db);
    return 0;
}

int insertTable(char *id, char *name, double price) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char sql[999];

    /* Open database */
    rc = sqlite3_open("LibreMarketC.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        // fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    sprintf(sql, "INSERT INTO PRODUCT (ID,NAME,PRICE) VALUES ('%s','%s', %lf );", id, name, price);

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }
    sqlite3_close(db);
    return 0;
}

char *getTableName(char id[99]) {
    selectTable(id);
    return sql_tmp_id;
}

double getTablePrice(char id[99]) {
    selectTable(id);
    double table_price;
    sscanf(sql_tmp_price, "%lf", &table_price);
    return table_price;
}

int selectTable(char id[99]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char sql[999];
    const char *data = "Callback function called";

    /* Open database */
    rc = sqlite3_open("LibreMarketC.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        // fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    sprintf(sql, "SELECT * FROM PRODUCT WHERE ID = '%s';", id);

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *) data, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        // fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);
    return 0;

}

struct Product *queryTable(char *id) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char sql[999];
    const char *data = "Callback function called";

    /* Open database */
    rc = sqlite3_open("LibreMarketC.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        // fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    sprintf(sql, "SELECT * FROM PRODUCT WHERE ID = '%s';", id);

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *) data, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        // fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);

    struct Product *tmp_product = malloc(sizeof(struct Product));
    strcpy(tmp_product->id, sql_tmp_id);
    strcpy(tmp_product->name, sql_tmp_name);
    sscanf(sql_tmp_price, "%lf", &tmp_product->price);
    return tmp_product;

}

int updateTableName(char *id, char *name) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char sql[999];
    const char *data = "Callback function called";

    /* Open database */
    rc = sqlite3_open("LibreMarketC.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        // fprintf(stderr, "Opened database successfully\n");
    }

    /* Create merged SQL statement */
    sprintf(sql, "UPDATE PRODUCT set NAME = '%s' where ID='%s'", name, id);

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *) data, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        // fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);
    return 0;
}

int updateTablePrice(char *id, double price) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char sql[999];
    const char *data = "Callback function called";

    /* Open database */
    rc = sqlite3_open("LibreMarketC.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        // fprintf(stderr, "Opened database successfully\n");
    }

    /* Create merged SQL statement */
    sprintf(sql, "UPDATE PRODUCT set PRICE = %lf where ID='%s'", price, id);

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *) data, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        // fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);
    return 0;
}

int deleteTable(char *id) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char sql[999];
    const char *data = "Callback function called";

    /* Open database */
    rc = sqlite3_open("LibreMarketC.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        // fprintf(stderr, "Opened database successfully\n");
    }

    /* Create merged SQL statement */
    sprintf(sql, "DELETE from PRODUCT where ID='%s'", id);

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *) data, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        // fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);
    return 0;
}
