CC = gcc
CFLAGS = -g

all: 
	lex myscanner.lex 
	yacc -d myparser.y 
	gcc lex.yy.c y.tab.c -o calc

clean:
	-rm calculadora