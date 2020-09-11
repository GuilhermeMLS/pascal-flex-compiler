#include <stdio.h>
#include <stdlib.h>
#include "labelsStack.h"

int createLabelsStack(LabelsStackType *pilha) {
    if (pilha == NULL) {
        return -1;
    } else {
        pilha->top = 0;
        return 0;
    }
}

int pushToLabelsStack(LabelsStackType *pilha, void *new_element) {
    if (pilha == NULL) {
        printf("NO PILHA!!!");
    } else if (pilha->top > STACK_MAX_SIZE) {
        printf("O TAMANHO DA PILHA FOI EXCEDIDO");
    } else {
        pilha->array[pilha->top] = new_element;
        pilha->top++;
    }

    return 0;
}

void * popFromLabelsStack(LabelsStackType *pilha){
    if (pilha == NULL) {
        printf("NO PILHA!!!");
    } else if (pilha->top > 0) {
        pilha->top--;
        return pilha->array[pilha->top];
    }

    return NULL;
}
