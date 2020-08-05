cmake_minimum_required(VERSION 3.14)
project(ProjetoBaseGuilherme_copy C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(symbolTable)

add_executable(ProjetoBaseGuilherme_copy
        symbolTable/symbolTable.c
        symbolTable/symbolTable.h
        compilador.h
        compiladorF.c
        genericStack/genericStack.h
        genericStack/genericStack.c)
