CC = gcc
CFLAGS = -g

all: 
	flex -o scannerAutomatico.c generadorScanner.lex 
	yacc -d -o parserAutomatico.c generadorParser.y 
	gcc scannerAutomatico.c parserAutomatico.c array.c tablaDeSimbolos.c -o calc

clean:
	-rm calculadora