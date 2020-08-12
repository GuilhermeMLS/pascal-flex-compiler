
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "symbolTable/symbolTable.h"

#define SYMBOL_TABLE_CAPACITY 100

int num_vars;
symbolTableType* compilerSymbolTable;
int currentLexicalLevel = 0;
int offset = -1;

%}

%token INTEIRO PROGRAM ABRE_PARENTESES FECHA_PARENTESES 
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO NUMERO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO ABRE_COLCHETES
%token FECHA_COLCHETES ABRE_CHAVES FECHA_CHAVES LABEL TYPE
%token ARRAY PROCEDURE FUNCTION GOTO WHILE DO DIV AND NOT OR
%token MENOR MAIOR DIFERENTE MAIOR_OU_IGUAL MENOR_OU_IGUAL
%token IGUAL MENOS MAIS VEZES

%%

programa: { geraCodigo (NULL, "INPP"); }
	PROGRAM IDENT ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA bloco PONTO {
             geraCodigo (NULL, "PARA");
             printSymbolTable(compilerSymbolTable);
	};

bloco       : 
              parte_declara_vars
              { 
              }

              comando_composto 
              ;




parte_declara_vars:  var 
;


var         : { } VAR declara_vars
            |
;

declara_vars: declara_vars declara_var 
            | declara_var 
;

declara_var : { }  lista_id_var DOIS_PONTOS
	tipo {
		/* AMEM */
		int numberOfDigits = getNumberOfDigits(num_vars);
		char amemString[5 + numberOfDigits];
              	sprintf(amemString, "AMEM %d", num_vars);
              	geraCodigo (NULL, amemString);


		// Here we should update the last num_vars symbols with the correct type
		int type = getTypeBasedOnToken(token);
		updateLastSymbolsTypes(compilerSymbolTable, num_vars, type);

		num_vars = 0;
	} PONTO_E_VIRGULA ;

tipo: IDENT;

lista_id_var: lista_id_var VIRGULA IDENT {
		/* Insert the last variable of the list into the Symbol Table */
		num_vars++;
		offset++;

		int type = 0; // temporary, will be updated later
		int lexicalLevel = currentLexicalLevel;
		int category = simpleVariable;

		symbolType* newVariable = createSymbol(token, type, lexicalLevel, offset, category, 0, 0, 0);
		pushToSymbolTable(compilerSymbolTable, newVariable);
	} | IDENT {
            	/* insere vars na tabela de símbolos */
		num_vars++;
		offset++;

                int type = 0; // temporary, will be updated later
		int lexicalLevel = currentLexicalLevel;
		int category = simpleVariable;

		symbolType* newVariable = createSymbol(token, type, lexicalLevel, offset, category, 0, 0, 0);
		pushToSymbolTable(compilerSymbolTable, newVariable);
	};

lista_idents: lista_idents VIRGULA IDENT  
            | IDENT
;


atribuicao: IDENT ATRIBUICAO expressao ;
expressao: expressao_simples relacao_expressao_simples_ou_vazio;
relacao_expressao_simples_ou_vazio: relacao_expressao_simples | ;
relacao_expressao_simples: relacao expressao_simples;

relacao: IGUAL | DIFERENTE | MENOR | MAIOR | MENOR_OU_IGUAL | MAIOR_OU_IGUAL;

expressao_simples: mais_ou_menos_ou_vazio termo lista_sinal_e_termo_ou_vazio;
lista_sinal_e_termo_ou_vazio: lista_sinal_e_termo | ;
lista_sinal_e_termo: lista_sinal_e_termo sinal_lista_sinal_e_termo termo | sinal_lista_sinal_e_termo termo ;
sinal_lista_sinal_e_termo: MAIS | MENOS | OR;
mais_ou_menos_ou_vazio: mais_ou_menos | ;
mais_ou_menos: MAIS | MENOS ;

termo: fator lista_sinal_e_fator_ou_vazio;
lista_sinal_e_fator_ou_vazio: lista_sinal_e_fator | ;
lista_sinal_e_fator: lista_sinal_e_fator sinal_lista_sinal_fator fator | sinal_lista_sinal_fator fator ;
sinal_lista_sinal_fator: VEZES | DIV | AND;

fator: NOT fator | variavel | NUMERO | ABRE_PARENTESES expressao FECHA_PARENTESES ;

variavel: IDENT ;




comando_composto: T_BEGIN comandos T_END ;

comandos: lista_de_atribuicoes;

lista_de_atribuicoes: lista_de_atribuicoes PONTO_E_VIRGULA atribuicao | atribuicao | ;


%%

main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */
   compilerSymbolTable = createSymbolTable(SYMBOL_TABLE_CAPACITY);
   yyin=fp;
   yyparse();

   return 0;
}

