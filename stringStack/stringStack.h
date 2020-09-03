#ifndef STRING_STACK
#define STRING_STACK

typedef struct stringStack {
    int top;
    char* array;
    int capacity;
} stringStackType;

stringStackType* createStringStack(int capacity);
int stringStackIsEmpty(stringStackType* stringStack);
void pushToStringStack(stringStackType* stringStack, char* string);
char* popFromStringStack(stringStackType* stringStack);
int stringStackIsFull(stringStackType* stringStack);
int stringsAreEqual(char *string1, char *string2);
void printStringStack(stringStackType* stringStack);

#endif