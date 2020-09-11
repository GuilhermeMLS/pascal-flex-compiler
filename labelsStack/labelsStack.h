#ifndef LABELS_STACK
#define LABELS_STACK

#include "../symbolTable/symbolTable.h"

#define STACK_MAX_SIZE 255
#define LABEL_MAX_SIZE 10

typedef struct LabelsStack {
    void *array[STACK_MAX_SIZE];
    int top;
} LabelsStackType;

int createLabelsStack(LabelsStackType *);
int pushToLabelsStack(LabelsStackType *, void *);
void *popFromLabelsStack(LabelsStackType *);
//void *popAllFromLabelsStack(LabelsStackType *);


#endif