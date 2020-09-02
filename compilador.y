
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "symbolTable/symbolTable.h"
#include "stringStack/stringStack.h"

#define SYMBOL_TABLE_CAPACITY 100
#define OPERATORS_STACK_CAPACITY 100

int num_vars;
symbolTableType* compilerSymbolTable;
int currentLexicalLevel = 0;
int offset = -1;
symbolType* currentSymbol;
stringStackType* operatorsStack;

// For some reason I'd to put this function prototype here.
// TODO: think of a better place to put it on
char* getOperatorInstruction(char *operator);

%}

%token INTEIRO PROGRAM ABRE_PARENTESES FECHA_PARENTESES 
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO NUMERO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO ABRE_COLCHETES
%token FECHA_COLCHETES ABRE_CHAVES FECHA_CHAVES LABEL TYPE
%token ARRAY PROCEDURE FUNCTION GOTO WHILE DO DIV AND NOT OR
%token MENOR MAIOR DIFERENTE MAIOR_OU_IGUAL MENOR_OU_IGUAL
%token IGUAL MENOS MAIS VEZES READ WRITE

%%

programa: { geraCodigo (NULL, "INPP");}
	PROGRAM IDENT ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA bloco PONTO {
		// DMEM
		int numberOfAllocatedVariables = compilerSymbolTable->top + 1;
		int numberOfDigits = getNumberOfDigits(numberOfAllocatedVariables );
		char dmemString[5 + numberOfDigits];
		sprintf(dmemString, "DMEN %d", numberOfAllocatedVariables );
		geraCodigo (NULL, dmemString);

		// PARA
		geraCodigo (NULL, "PARA");
		printSymbolTable(compilerSymbolTable);
	};

bloco: parte_declara_vars { } comando_composto ;

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


atribuicao: IDENT {
		currentSymbol = searchIntoSymbolTable(compilerSymbolTable, token);
	} atribui_variavel;

atribui_variavel: ATRIBUICAO expressao {
		int lexicalLevelNumberOfDigits = getNumberOfDigits(currentSymbol->lexicalAddress->lexicalLevel);
		int offsetNumberOfDigits = getNumberOfDigits(currentSymbol->lexicalAddress->offset);
		char armzString[6 + lexicalLevelNumberOfDigits + offsetNumberOfDigits];
		sprintf(
			armzString, "ARMZ %d,%d",
			currentSymbol->lexicalAddress->lexicalLevel,
			currentSymbol->lexicalAddress->offset
		);
		geraCodigo(NULL, armzString);
	};

lista_de_expressoes: lista_de_expressoes VIRGULA expressao | expressao;

expressao: expressao_simples relacao_expressao_simples_ou_vazio;
relacao_expressao_simples_ou_vazio: relacao_expressao_simples | ;
relacao_expressao_simples: relacao expressao_simples;

relacao: IGUAL | DIFERENTE | MENOR | MAIOR | MENOR_OU_IGUAL | MAIOR_OU_IGUAL;

expressao_simples: mais_ou_menos_ou_vazio termo lista_sinal_e_termo_ou_vazio;
lista_sinal_e_termo_ou_vazio: lista_sinal_e_termo | ;
lista_sinal_e_termo: lista_sinal_e_termo sinal_lista_sinal_e_termo termo {
		// desempilha a operacao
		char* operator = popFromStringStack(operatorsStack);
		char* instruction = getOperatorInstruction(operator);
		geraCodigo(NULL, instruction);
	} | sinal_lista_sinal_e_termo termo {
		// desempilha a operacao
		char* operator = popFromStringStack(operatorsStack);
		char* instruction = getOperatorInstruction(operator);
		geraCodigo(NULL, instruction);
	};
sinal_lista_sinal_e_termo: MAIS {
		// empilha a soma
		pushToStringStack(operatorsStack, token);
	} | MENOS | OR;
mais_ou_menos_ou_vazio: mais_ou_menos | ;
mais_ou_menos: MAIS | MENOS ;

termo: fator lista_sinal_e_fator_ou_vazio;
lista_sinal_e_fator_ou_vazio: lista_sinal_e_fator | ;
lista_sinal_e_fator: lista_sinal_e_fator sinal_lista_sinal_fator fator | sinal_lista_sinal_fator fator ;
sinal_lista_sinal_fator: VEZES | DIV | AND;

fator: NOT fator | variavel {
		symbolType* variable = searchIntoSymbolTable(compilerSymbolTable, token);
		int lexicalLevelNumberOfDigits = getNumberOfDigits(variable->lexicalAddress->lexicalLevel);
		int offsetNumberOfDigits = getNumberOfDigits(variable->lexicalAddress->offset);
		char crvlString[6 + lexicalLevelNumberOfDigits + offsetNumberOfDigits];
 		sprintf(
 			crvlString,
			"CRVL %d,%d",
			variable->lexicalAddress->lexicalLevel,
			variable->lexicalAddress->offset
		);
 		geraCodigo(NULL, crvlString);
	}
	| NUMERO {
 		int numberOfDigits = getNumberOfDigits(atoi(token));
 		char crctString[5 + numberOfDigits];
 		sprintf(crctString, "CRCT %s", token);
 		geraCodigo(NULL, crctString);
 	} | ABRE_PARENTESES expressao FECHA_PARENTESES ;

variavel: IDENT ;

chamada_de_procedimento: IDENT sessao_parametros_ou_vazio ;

sessao_parametros_ou_vazio: ABRE_PARENTESES lista_de_expressoes FECHA_PARENTESES | ;



comando_composto: T_BEGIN comandos_ou_vazio T_END ;

comandos_ou_vazio: comandos | ;

comandos: comandos PONTO_E_VIRGULA comando | comando ;

comando: comando_sem_rotulo;

comando_sem_rotulo:
	atribuicao
	| comando_composto
	| READ ABRE_PARENTESES lista_leitura FECHA_PARENTESES
	| WRITE ABRE_PARENTESES lista_impressao FECHA_PARENTESES
	| ;

// TODO gerar ARMZ para onde vai a leitura
lista_leitura: lista_leitura VIRGULA identificador {
		geraCodigo (NULL, "LEIT");
		symbolType* symbol = searchIntoSymbolTable(compilerSymbolTable, token);
		generateARMZCode(currentSymbol);
	} | identificador {
		geraCodigo (NULL, "LEIT");
		symbolType* symbol = searchIntoSymbolTable(compilerSymbolTable, token);
		generateARMZCode(symbol);
	};

// TODO terminar isso
lista_impressao: lista_impressao VIRGULA identificador {
		symbolType* symbol = searchIntoSymbolTable(compilerSymbolTable, token);
		generateCRVLCode(symbol);
		geraCodigo(NULL, "IMPR");
	} | identificador {
		symbolType* symbol = searchIntoSymbolTable(compilerSymbolTable, token);
		generateCRVLCode(symbol);
		geraCodigo(NULL, "IMPR");
	} | lista_impressao VIRGULA NUMERO {
		int numberOfDigits = getNumberOfDigits(atoi(token));
                char crctString[5 + numberOfDigits];
                sprintf(crctString, "CRCT %s", token);
                geraCodigo(NULL, crctString);
                geraCodigo(NULL, "IMPR");
	} | NUMERO {
		int numberOfDigits = getNumberOfDigits(atoi(token));
		char crctString[5 + numberOfDigits];
		sprintf(crctString, "CRCT %s", token);
		geraCodigo(NULL, crctString);
                geraCodigo(NULL, "IMPR");
	} ;

identificador: IDENT;

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
   operatorsStack = createStringStack(OPERATORS_STACK_CAPACITY);
   yyin=fp;
   yyparse();

   return 0;
}

