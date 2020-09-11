$DEPURA=1

compilador: lex.yy.c y.tab.c compilador.o compilador.h symbolTable/symbolTable.o stringStack/stringStack.o labelsStack/labelsStack.o genericStack/genericStack.o
	gcc lex.yy.c compilador.tab.c compilador.o symbolTable/symbolTable.o stringStack/stringStack.o genericStack/genericStack.o labelsStack/labelsStack.o -o compilador -ll -ly -lc

lex.yy.c: compilador.l compilador.h
	flex compilador.l

y.tab.c: compilador.y compilador.h symbolTable/symbolTable.h stringStack/stringStack.h labelsStack/labelsStack.h genericStack/genericStack.o
	bison compilador.y -d -v

compilador.o : compilador.h compiladorF.c
	gcc -c compiladorF.c -o compilador.o

symbolTable/symbolTable.o : symbolTable/symbolTable.h symbolTable/symbolTable.c
	gcc -c symbolTable/symbolTable.c -o symbolTable/symbolTable.o

stringStack/stringStack.o : stringStack/stringStack.h stringStack/stringStack.c
	gcc -c stringStack/stringStack.c -o stringStack/stringStack.o

labelsStack/labelsStack.o : labelsStack/labelsStack.h labelsStack/labelsStack.c
	gcc -c labelsStack/labelsStack.c -o labelsStack/labelsStack.o

genericStack/genericStack.o : genericStack/genericStack.h genericStack/genericStack.c
	gcc -c genericStack/genericStack.c -o genericStack/genericStack.o

clean : 
	rm -f compilador.tab.* lex.yy.c 
