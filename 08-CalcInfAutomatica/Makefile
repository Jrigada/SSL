

all: 
	flex -o scannerAutomatico.c generadorScanner.lex 
	bison -d -o parserAutomatico.c generadorParser.y
	gcc scannerAutomatico.c parserAutomatico.c array.c tablaDeSimbolos.c -o calc

clean:
	-rm calculadora