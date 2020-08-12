$DEPURA=1

compilador: lex.yy.c y.tab.c compilador.o compilador.h symbolTable/symbolTable.o
	gcc lex.yy.c compilador.tab.c compilador.o symbolTable/symbolTable.o -o compilador -ll -ly -lc

lex.yy.c: compilador.l compilador.h
	flex compilador.l

y.tab.c: compilador.y compilador.h symbolTable/symbolTable.h
	bison compilador.y -d -v

compilador.o : compilador.h compiladorF.c
	gcc -c compiladorF.c -o compilador.o

symbolTable/symbolTable.o : symbolTable/symbolTable.h symbolTable/symbolTable.c
	gcc -c symbolTable/symbolTable.c -o symbolTable/symbolTable.o

clean : 
	rm -f compilador.tab.* lex.yy.c 
