#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

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
    printf(GRN "[Symbol Table Message] \"%s\" pushed to Symbol Table.\n" RESET, symbol->identifier);
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
        int category,
        int passingMechanism,
        int numberOfParameters,
        formalParameterType* formalParametersArray
) {
    symbolType* symbol = (symbolType*) malloc(sizeof(symbolType));
    strcpy(symbol->identifier, identifier);
    symbol->type = type;
    symbol->lexicalAddress = (lexicalAddressType*) malloc(sizeof(lexicalAddressType));
    symbol->lexicalAddress->lexicalLevel = lexicalLevel;
    symbol->lexicalAddress->offset = offset;
    symbol->category = category;

    if (category == formalParameter) {
        symbol->passingMechanism = passingMechanism;
    }

    if (category == procedure) {
        symbol->numberOfParameters = numberOfParameters;
        symbol->formalParametersArray = formalParametersArray;
    }

    return symbol;
}

void printSymbolTable(symbolTableType* symbolTable) {
    for (int i = symbolTable->top; i >= 0; i--) {
        symbolType* symbol = &(symbolTable->array[i]);
        printSymbol(symbol);
    }
    printf("---------\n");
}

void printSymbol(symbolType* symbol) {
    printf("---------\n");
    printf("Identifier: %s \n", symbol->identifier);
    if (symbol->category == formalParameter || symbol->category == simpleVariable) {
        printf("Type: %s \n", getSymbolTypeString(symbol->type));
    }
    printf("Lexical Address: [%d, %d] \n", symbol->lexicalAddress->lexicalLevel, symbol->lexicalAddress->offset);
    printf("Category: %s \n", getSymbolCategoryString(symbol->category));
    if (symbol->category == formalParameter) {
        printf("Passing Mechanism: %s \n", getPassingMechanismString(symbol->passingMechanism));
    }
    if (symbol->category == procedure) {
        printf("Number of parameters: %d \n", symbol->numberOfParameters);
        printf("Formal Parameters: ");
        printFormalParameters(symbol->formalParametersArray, symbol->numberOfParameters);
    }
}

void printFormalParameters(formalParameterType* formalParameters, int numberOfParameters) {
    printf("\n");
    for (int i = 0; i < numberOfParameters; i++) {
        formalParameterType parameter = formalParameters[i];
        printf(
                "    [Type = %s, Passing Mechanism = %s]\n",
                getSymbolTypeString(parameter.type),
                getPassingMechanismString(parameter.passingMechanism)
        );
    }
}

char* getPassingMechanismString(int passingMechanism) {
    if (passingMechanism == passByValue) {
        return "Pass by value";
    } else {
        return "Pass by reference";
    }
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
        case integerType:
            return "Integer";
        case characterType:
            return "Character";
        case floatingPointType:
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
        case procedure:
            return "Procedure";
        default:
            return "Unknown category";
    }
}

void updateSymbolType(symbolTableType* symbolTable, char* identifier, int newType) {
    if (symbolTableIsEmpty(symbolTable)) {
        return;
    }
    for (int i = symbolTable->top; i >= 0; i--) {
        symbolType* symbol = &(symbolTable->array[i]);
        if (identifiersAreEqual(symbol->identifier, identifier)) {
            symbol->type = newType;
        }
    }
}

void updateLastSymbolsTypes(symbolTableType* symbolTable, int numberOfLastSymbols, int newType) {
    if (symbolTableIsEmpty(symbolTable)) {
        return;
    }
    for (int i = symbolTable->top; i > (symbolTable->top - numberOfLastSymbols); i--) {
        symbolType* symbol = &(symbolTable->array[i]);
        symbol->type = newType;
    }
}