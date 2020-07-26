#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"

symbolTableType* createSymbolTable(unsigned capacity) {
    symbolTableType* symbolTable = (symbolTableType*) malloc(sizeof(symbolTableType));
    symbolTable->capacity = capacity;
    symbolTable->top = -1;
    symbolTable->array = (symbolType*) malloc(symbolTable->capacity * sizeof(symbolType));
    return symbolTable;
}

int symbolTableIsFull(symbolTableType* symbolTable) {
    return symbolTable->top == symbolTable->capacity - 1;
}

int symbolTableIsEmpty(symbolTableType* symbolTable) {
    return symbolTable->top == -1;
}

void pushToSymbolTable(symbolTableType* symbolTable, symbolType* symbol) {
    if (symbolTableIsFull(symbolTable)) {
        return;
    }
    symbolTable->array[++symbolTable->top] = *symbol;
    printf("\"%s\" pushed to Symbol Table.\n", symbol->identifier);
}

symbolType* popFromSymbolTable(symbolTableType* symbolTable) {
    if (symbolTableIsEmpty(symbolTable)) {
        return NULL;
    }
    symbolType* symbol = &(symbolTable->array[symbolTable->top--]);
    printf("\"%s\" popped from Symbol Table.\n", symbol->identifier);
    return symbol;
}

symbolType* peekSymbolTable(symbolTableType* symbolTable) {
    if (symbolTableIsEmpty(symbolTable)) {
        return NULL;
    }
    return &(symbolTable->array[symbolTable->top]);
}

symbolType* searchIntoSymbolTable(symbolTableType* symbolTable, char* identifier) {
    if (symbolTableIsEmpty(symbolTable)) {
        return NULL;
    }
    for (int i = symbolTable->top; i >= 0; i--) {
        symbolType* symbol = &(symbolTable->array[i]);
        if (identifiersAreEqual(symbol->identifier, identifier)) {
            return symbol;
        }
    }
    return NULL;
}

void removeFromSymbolTable(symbolTableType* symbolTable, int numberOfEntriesToRemove) {
    if (symbolTableIsEmpty(symbolTable)) {
        return;
    }
    if (symbolTable->top - numberOfEntriesToRemove >= 0) {
        symbolTable->top = symbolTable->top - numberOfEntriesToRemove;
    } else {
        symbolTable->top = -1;
    }
}

symbolType* createSymbol(
    char* identifier,
    int type,
    int lexicalLevel,
    int offset,
    int category
) {
    symbolType* symbol = (symbolType*) malloc(sizeof(symbolType));
    strcpy(symbol->identifier, identifier);
    symbol->type = type;
    symbol->lexicalAddress = (lexicalAddressType*) malloc(sizeof(lexicalAddressType));
    symbol->lexicalAddress->lexicalLevel = lexicalLevel;
    symbol->lexicalAddress->offset = offset;
    symbol->category = category;

    return symbol;
}

void printSymbolTable(symbolTableType* symbolTable) {
    for (int i = symbolTable->top; i >= 0; i--) {
        symbolType* symbol = &(symbolTable->array[i]);
        printf("---------\n");
        printf("Identifier: %s \n", symbol->identifier);
        printf("Type: %s \n", getSymbolTypeString(symbol->type));
        printf("Lexical Address: [%d, %d] \n", symbol->lexicalAddress->lexicalLevel, symbol->lexicalAddress->offset);
        printf("Category: %s \n", getSymbolCategoryString(symbol->category));
    }
    printf("---------\n");
}

void printSymbol(symbolType* symbol) {
    printf("---------\n");
    printf("Identifier: %s \n", symbol->identifier);
    printf("Type: %s \n", getSymbolTypeString(symbol->type));
    printf("Lexical Address: [%d, %d] \n", symbol->lexicalAddress->lexicalLevel, symbol->lexicalAddress->offset);
    printf("Category: %s \n", getSymbolCategoryString(symbol->category));
    printf("---------\n");
}

int identifiersAreEqual(char* identifier1, char* identifier2) {
    if (strcmp(identifier1, identifier2) == 0) {
        return 1;
    } else {
        return 0;
    }
}

char* getSymbolTypeString(int type) {
    switch(type) {
        case integer:
            return "Integer";
        case character:
            return "Character";
        case floatingPoint:
            return "Floating Point";
        default:
            return "Unknown type";
    }
}

char* getSymbolCategoryString(int category) {
    switch(category) {
        case simpleVariable:
            return "Simple Variable";
        case formalParameter:
            return "Formal Parameter";
        default:
            return "Unknown category";
    }
}