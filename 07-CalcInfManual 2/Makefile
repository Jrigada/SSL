CC = gcc
CFLAGS = -g

calculadora: y.tab.c lex.yy.c
	$(CC) -g -o calculadora y.tab.c lex.yy.c -w

clean:
	-rm calculadora