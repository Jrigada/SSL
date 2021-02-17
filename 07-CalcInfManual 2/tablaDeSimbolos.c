#include "tablaDeSimbolos.h"

int symbols[52];

//inicializacion de tabla de simbolos
void initTablaDeSimbolos() {

   for (int i=0;i<52;i++) {
      symbols[i]=0;
   } 

}

//indice de un id
int computeSymbolIndex(char id) {
   int idx = -1;
   if (islower(id)) {
      idx = id - 'a' + 26;
   } else if (isupper(id)) {
      idx = id - 'A';
   }
   return idx;
}

//valor almacenado de un id
int symbolVal(char symbol)
{
   int bucket = computeSymbolIndex(symbol);
   return symbols[bucket];
}

//agregar valor a un id de la tabla de simbolos
void updateSymbolVal(char symbol, int val) {
   int bucket = computeSymbolIndex(symbol);
   symbols[bucket] = val;
}

