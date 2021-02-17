#include <stdbool.h>
#include "scanner.h"
#include "tablaDeSimbolos.h"

// typedef struct {
//   token *array;
//   size_t used;
//   size_t size;
// } Array;


// void initArray(Array *a,size_t tamanioInicial) {
//     a->array = malloc(tamanioInicial * sizeof(token));
//     a->used = 0;
//     a->size = tamanioInicial;
// }



// void insertArray(Array *a, token element) {
//   if (a->used == a->size) {
//     a->size *= 2;
//     a->array = realloc(a->array, a->size * sizeof(token));
//   }
//   a->array[a->used++] = element;
// }



// void freeArray(Array *a) {
//   free(a->array);
//   a->array = NULL;
//   a->used = a->size = 0;
// }


void match(token);
int charToInt(char);
void objetivo(void);
void programa(void);
void listaDeSentencias(void);
void sentencia(void);
int suma(void);
int multiplicacion(void);
int datoElemental(void);