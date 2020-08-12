
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
        return integer;
    }
    if (strcmp(typeToken, "char") == 0) {
        return character;
    }
    if (strcmp(typeToken, "real") == 0) {
        return floatingPoint;
    }
    return 0;
}