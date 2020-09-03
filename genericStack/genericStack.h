#ifndef GENERIC_STACK
#define GENERIC_STACK

#define GENERIC_STACK_MAX_SIZE 255

#include "../symbolTable/symbolTable.h"
#include "../compilador.h"
#include "../symbolTable/symbolTable.h"

typedef struct genericStack {
    void *array[GENERIC_STACK_MAX_SIZE];
    int top;
} genericStackType;

int createGenericStack(genericStackType*);
int pushToGenericStack (genericStackType*, void*);
void printGenericStack(genericStackType*);
void* popFromGenericStack(genericStackType*);
void* popAll(genericStackType*);
//int generateLabel(genericStackType *, char **, int *);
int pushType(genericStackType*, typeType);
int checkTypes(genericStackType*, operationType);


#endif