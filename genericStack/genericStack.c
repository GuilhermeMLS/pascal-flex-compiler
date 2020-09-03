#include <stdio.h>
#include <stdlib.h>
#include "genericStack.h"

int createGenericStack(genericStackType *stack) {
    if (stack == NULL) {
        return -1;
    }
    stack->top= 0;
    return 0;
}

int pushToGenericStack(genericStackType *stack, void *newElement) {
    if (stack == NULL) {
        printf("Generic Stack null");
    } else if (stack->top> GENERIC_STACK_MAX_SIZE) {
        printf("Generic Stack size exceeded");
    } else {
        stack->array[stack->top] = newElement;
        stack->top++;
    }
    return 0;
}

void* popFromGenericStack(genericStackType *stack) {
    if (stack == NULL) {
        printf("Generic Stack null");
    } else if (stack->top > 0) {
        stack->top--;
        return stack->array[stack->top];
    }
    return NULL;
}

void * popAll(genericStackType *stack)
{
    if (stack == NULL) {
        printf("Generic Stack null");
    } else if (stack->top > 0) {
        stack->top--;
        return stack->array[stack->top];
    }
    return NULL;
}

int pushType(genericStackType *stack, typeType type) {
    typeType *aux;
    aux = malloc(sizeof(typeType));
    if (aux == NULL) {
        printf("Generic Stack null");
    }
    *aux = type;
    pushToGenericStack(stack, aux);
    return 0;
}

void printGenericStack(genericStackType *stack) {
    int pointer = stack->top;
    while (stack != NULL) {
        printf("\n%p", stack->array[pointer]);
        pointer++;
    }
}

int checkTypes(genericStackType *stack, operationType operation) {
    typeType *leftNode, *rightNode;
    if (stack == NULL) {
        printf("Stack doesn't exist");
    } else {
        if (operation == negation) {
            leftNode = (typeType *) popFromGenericStack(stack);
        } else {
            rightNode = (typeType *) popFromGenericStack(stack);
            leftNode = (typeType *) popFromGenericStack(stack);
        }
        switch (operation) {
            case mathematicalExpression: {
                if (
                    ((*leftNode == *rightNode) && (*leftNode == integerType) && (*rightNode == integerType))
                    || ((*leftNode == voidType) && (*rightNode == integerType))
                ) {
                    pushType(stack, *rightNode);
                } else{
                    puts("\nSyntax error: types are different\n");
                    exit(-1);
                }
                break;
            } case comparison: {
                if (
                    ((*leftNode == *rightNode) && (*leftNode == integerType) && (*rightNode == integerType))
                    || ((*leftNode == voidType) && (*rightNode == integerType))
                    || ((*rightNode == voidType) && (*leftNode == integerType))
                ) {
                    pushType(stack, booleanType);
                } else {
                    puts("\nSyntax error: types are different\n");
                    exit(-1);
                }
                break;
            } case attribution: {
                if (
                    ((*leftNode == *rightNode) && (*leftNode == integerType) && (*rightNode == integerType))
                    || ((*leftNode == voidType) && (*rightNode == integerType))
                ) {
                    pushType(stack, *leftNode);
                } else {
                    puts("\nSyntax error: types are different\n");
                    exit(-1);
                }
                break;
            } case booleanOperation: {
                if ((*leftNode == *rightNode) && (*leftNode == booleanType)) {
                    pushType(stack, *leftNode);
                } else {
                    puts("\nSyntax error: types are different\n");
                    exit(-1);
                }
                break;
            } case negation: {
                if (*leftNode == booleanType) {
                    pushType(stack, *leftNode);
                } else {
                    puts("\nSYNTAX ERROR: Parametro passado não é Boolena\n");
                    exit(-1);
                }
                break;
            }
        }
    }
    return 0;
}

