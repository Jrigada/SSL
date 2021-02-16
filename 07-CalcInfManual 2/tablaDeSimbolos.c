#include "tablaDeSimbolos.h"


int symbols[52];


void initTablaDeSimbolos() {
    
   for (int i=0;i<52;i++) {
      symbols[i]=0;
   } 

}

int computeSymbolIndex(char token) {
   int idx = -1;
   if (islower(token)) {
      idx = token - 'a' + 26;
   } else if (isupper(token)) {
      idx = token - 'A';
   }
   return idx;
}

int symbolVal(char symbol)
{
   int bucket = computeSymbolIndex(symbol);
   return symbols[bucket];
}

void updateSymbolVal(char symbol, int val) {
   int bucket = computeSymbolIndex(symbol);
   symbols[bucket] = val;
}

