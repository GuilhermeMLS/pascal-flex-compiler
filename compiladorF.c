
/* -------------------------------------------------------------------
 *            Aquivo: compilador.c
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Fun��es auxiliares ao compilador
 *
 * ------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "compilador.h"
#include "symbolTable/symbolTable.h"
#include "stringStack/stringStack.h"
#include "genericStack/genericStack.h"

#define LABEL_MAX_SIZE 10

/* -------------------------------------------------------------------
 *  vari�veis globais
 * ------------------------------------------------------------------- */

FILE* fp=NULL;
void geraCodigo (char* rot, char* comando) {

  if (fp == NULL) {
    fp = fopen ("MEPA", "w");
  }

  if ( rot == NULL ) {
    fprintf(fp, "     %s\n", comando); fflush(fp);
  } else {
    fprintf(fp, "%s: %s \n", rot, comando); fflush(fp);
  }
}

int imprimeErro ( char* erro ) {
  fprintf (stderr, "Erro na linha %d - %s\n", nl, erro);
  exit(-1);
}

int getNumberOfDigits(int number) {
    int result = 1;
    if (number < 0) {
        number = (number == INT_MIN)
            ? INT_MAX
            : - number;
    }
    while (number > 9) {
        number /= 10;
        result++;
    }
    return result;
}

int getTypeBasedOnToken(char* typeToken) {
    if (strcmp(typeToken, "integer") == 0) {
        return integerType;
    }
    if (strcmp(typeToken, "char") == 0) {
        return characterType;
    }
    if (strcmp(typeToken, "real") == 0) {
        return floatingPointType;
    }
    return 0;
}

char* getOperatorInstruction(char *operator) {
    if (strcmp(operator, "+") == 0) {
        return "SOMA";
    }
    if (strcmp(operator, "*") == 0) {
        return "MULT";
    }
    if (strcmp(operator, "/") == 0) {
        return "DIVI";
    }
    if (strcmp(operator, "-") == 0) {
        return "SUBT";
    }
    return NULL;
}

void generateARMZCode(symbolType* symbol) {
    int lexicalLevelNumberOfDigits = getNumberOfDigits(symbol->lexicalAddress->lexicalLevel);
    int offsetNumberOfDigits = getNumberOfDigits(symbol->lexicalAddress->offset);
    char armzString[6 + lexicalLevelNumberOfDigits + offsetNumberOfDigits];
    if (
        symbol->category == formalParameter
        && symbol->passingMechanism == passByReference
    ) {
        sprintf(
            armzString,
            "ARMI %d,%d",
            symbol->lexicalAddress->lexicalLevel,
            symbol->lexicalAddress->offset
        );
    } else {
        sprintf(
            armzString,
            "ARMZ %d,%d",
            symbol->lexicalAddress->lexicalLevel,
            symbol->lexicalAddress->offset
        );
    }
    geraCodigo(NULL, armzString);
}


void generateCRVLCode(symbolType* symbol) {
    int lexicalLevelNumberOfDigits = getNumberOfDigits(symbol->lexicalAddress->lexicalLevel);
    int offsetNumberOfDigits = getNumberOfDigits(symbol->lexicalAddress->offset);
    char crvlString[6 + lexicalLevelNumberOfDigits + offsetNumberOfDigits];
    sprintf(
        crvlString,
        "CRVL %d,%d",
        symbol->lexicalAddress->lexicalLevel,
        symbol->lexicalAddress->offset
    );
    geraCodigo(NULL, crvlString);
}

void generateCRCTCode(char* constantToken) {
    int numberOfDigits = getNumberOfDigits(atoi(constantToken));
    char CRCTString[5 + numberOfDigits];
    sprintf(CRCTString, "CRCT %s", constantToken);
    geraCodigo(NULL, CRCTString);
}

int generateLabel(stringStackType* stack, char** label, int* numberOfLabels) {
    *label = malloc(sizeof(char[LABEL_MAX_SIZE]));
    sprintf(*label, "R%02d", *numberOfLabels);
    *numberOfLabels = *numberOfLabels + 1;
    pushToStringStack(stack, *label);

    return 0;
}