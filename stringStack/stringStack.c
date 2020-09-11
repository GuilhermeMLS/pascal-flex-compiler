#include "stringStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1B[31m"
#define RESET "\x1B[0m"

stringStackType* createStringStack(int capacity) {
    stringStackType* stringStack = (stringStackType*) malloc(sizeof(stringStackType));
    stringStack->top = -1;
    stringStack->capacity = capacity;
    stringStack->array = (char*) malloc(sizeof(char*) * capacity);
    return stringStack;
}

int stringStackIsEmpty(stringStackType* stringStack) {
    return stringStack->top == -1;
}

int stringStackTableIsFull(stringStackType* stringStackTable) {
    return stringStackTable->top == stringStackTable->capacity - 1;
}

int stringStackIsFull(stringStackType* stringStack) {
    return stringStack->top == stringStack->capacity - 1;
}

void pushToStringStack(stringStackType* stringStack, char* string) {
    if (stringStackIsFull(stringStack)) {
        return;
    }
    stringStack->array[++stringStack->top] = *string;
    printf(RED "[String Stack Message] \"%s\" pushed to String Stack.\n" RESET, string);
}

char* popFromStringStack(stringStackType* stringStack) {
    if (stringStackIsEmpty(stringStack)) {
        return NULL;
    }
    char* string = &(stringStack->array[stringStack->top--]);
    printf(RED "\"%s\" popped from String Stack.\n", string);
    return string;
}

char* peekStringStack(stringStackType* stringStack) {
    if (stringStackIsEmpty(stringStack)) {
        return NULL;
    }
    return &(stringStack->array[stringStack->top]);
}

char* searchIntoStringStack(stringStackType* stringStack, char* searchingString) {
    if (stringStackIsEmpty(stringStack)) {
        return NULL;
    }
    for (int i = stringStack->top; i >= 0; i--) {
        char* string = &(stringStack->array[i]);
        if (stringsAreEqual(searchingString, string)) {
            return string;
        }
    }
    return NULL;
}

int stringsAreEqual(char *string1, char *string2) {
    if (strcmp(string1, string2) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void removeFromStringStack(stringStackType* stringStack, int numberOfEntriesToRemove) {
    if (stringStackIsEmpty(stringStack)) {
        return;
    }
    if (stringStack->top - numberOfEntriesToRemove >= 0) {
        stringStack->top = stringStack->top - numberOfEntriesToRemove;
    } else {
        stringStack->top = -1;
    }
}

void printStringStack(stringStackType* stringStack) {
    printf("[String Stack]\n");
    for (int i = stringStack->top; i >= 0; i--) {
        char* string = &(stringStack->array[i]);
        printf("%s\n", string);
        printf("------\n");
    }
}