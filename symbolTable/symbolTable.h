#define MAXIMUM_IDENTIFIER_SIZE 255

enum variableTypes {
    integer = 1,
    character = 2,
    floatingPoint = 3
};

enum variableCategories {
    simpleVariable = 1,
    formalParameter = 2
};

typedef struct lexicalAddress {
    int lexicalLevel;
    int offset;
} lexicalAddressType;

typedef struct symbol {
    char identifier[MAXIMUM_IDENTIFIER_SIZE];
    int type;
    lexicalAddressType *lexicalAddress;
    int category;
} symbolType;

typedef struct symbolTable {
    int top;
    unsigned capacity;
    symbolType* array;
} symbolTableType;

// Basic stack API
void pushToSymbolTable(symbolTableType* symbolTable, symbolType* symbol);
int symbolTableIsFull(symbolTableType* symbolTable);
int symbolTableIsEmpty(symbolTableType* symbolTable);
symbolType* popFromSymbolTable(symbolTableType* symbolTable);
symbolType* peekSymbolTable(symbolTableType* symbolTable); // Returns Symbol Table top without removing it
symbolTableType* createSymbolTable(unsigned capacity);

// Symbol Table API
symbolType* searchIntoSymbolTable(symbolTableType* symbolTable, char* identifier);
void removeFromSymbolTable(symbolTableType* symbolTable, int numberOfEntriesToRemove);
symbolType* createSymbol(
    char* identifier,
    int type,
    int lexicalLevel,
    int offset,
    int category
);

// Utils API
void printSymbolTable(symbolTableType* symbolTable);
void printSymbol(symbolType* symbol);
int identifiersAreEqual(char* identifier1, char* identifier2);
char* getSymbolTypeString(int type);
char* getSymbolCategoryString(int type);
