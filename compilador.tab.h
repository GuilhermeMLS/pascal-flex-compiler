/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEIRO = 258,
     PROGRAM = 259,
     ABRE_PARENTESES = 260,
     FECHA_PARENTESES = 261,
     VIRGULA = 262,
     PONTO_E_VIRGULA = 263,
     DOIS_PONTOS = 264,
     PONTO = 265,
     NUMERO = 266,
     T_BEGIN = 267,
     T_END = 268,
     VAR = 269,
     IDENT = 270,
     ATRIBUICAO = 271,
     ABRE_COLCHETES = 272,
     FECHA_COLCHETES = 273,
     ABRE_CHAVES = 274,
     FECHA_CHAVES = 275,
     LABEL = 276,
     TYPE = 277,
     ARRAY = 278,
     PROCEDURE = 279,
     FUNCTION = 280,
     GOTO = 281,
     WHILE = 282,
     DO = 283,
     DIV = 284,
     AND = 285,
     NOT = 286,
     OR = 287,
     MENOR = 288,
     MAIOR = 289,
     DIFERENTE = 290,
     MAIOR_OU_IGUAL = 291,
     MENOR_OU_IGUAL = 292,
     IGUAL = 293,
     MENOS = 294,
     MAIS = 295,
     VEZES = 296,
     READ = 297,
     WRITE = 298
   };
#endif
/* Tokens.  */
#define INTEIRO 258
#define PROGRAM 259
#define ABRE_PARENTESES 260
#define FECHA_PARENTESES 261
#define VIRGULA 262
#define PONTO_E_VIRGULA 263
#define DOIS_PONTOS 264
#define PONTO 265
#define NUMERO 266
#define T_BEGIN 267
#define T_END 268
#define VAR 269
#define IDENT 270
#define ATRIBUICAO 271
#define ABRE_COLCHETES 272
#define FECHA_COLCHETES 273
#define ABRE_CHAVES 274
#define FECHA_CHAVES 275
#define LABEL 276
#define TYPE 277
#define ARRAY 278
#define PROCEDURE 279
#define FUNCTION 280
#define GOTO 281
#define WHILE 282
#define DO 283
#define DIV 284
#define AND 285
#define NOT 286
#define OR 287
#define MENOR 288
#define MAIOR 289
#define DIFERENTE 290
#define MAIOR_OU_IGUAL 291
#define MENOR_OU_IGUAL 292
#define IGUAL 293
#define MENOS 294
#define MAIS 295
#define VEZES 296
#define READ 297
#define WRITE 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

