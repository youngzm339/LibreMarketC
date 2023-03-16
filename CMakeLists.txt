cmake_minimum_required(VERSION 3.15)
PROJECT(LibreMarketC C)
add_executable(LibreMarketC
        main.c menu.h menu.c sqlite/sqlite3.h sqlite/sqlite3.c sqlite_api.c sqlite_api.h cart.h cart.c report.h report.c product.h product.c)


