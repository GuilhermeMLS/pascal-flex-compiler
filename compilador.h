/* -------------------------------------------------------------------
 *            Arquivo: compilaodr.h
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [15/03/2012, 08h:22m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, prot�tipos e vai�veis globais do compilador
 *
 * ------------------------------------------------------------------- */

#define TAM_TOKEN 16

typedef enum simbolos { 
  simb_program, 
  simb_var, 
  simb_begin, 
  simb_end, 
  simb_identificador, 
  simb_numero,
  simb_ponto, 
  simb_virgula, 
  simb_ponto_e_virgula, 
  simb_dois_pontos,
  simb_atribuicao, 
  simb_abre_parenteses, 
  simb_fecha_parenteses,
  simb_abre_colchetes,
  simb_fecha_colchetes,
  simb_abre_chaves,
  simb_fecha_chaves,
  simb_label,
  simb_array,
  simb_procedure,
  simb_function,
  simb_goto,
  simb_while,
  simb_do,
  simb_div,
  simb_and,
  simb_not,
  simb_type
} simbolos;



/* -------------------------------------------------------------------
 * vari�veis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nivel_lexico;
extern int desloc;
extern int nl;


simbolos simbolo, relacao;
char token[TAM_TOKEN];



