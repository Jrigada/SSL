#include <stdbool.h>
#include "scanner.h"

typedef struct {
  token *array;
  size_t used;
  size_t size;
} Array;

bool parsear(token*,int);
bool esParValido(token,token);

void initArray(Array *a,size_t tamanioInicial) {
    a->array = malloc(tamanioInicial * sizeof(token));
    a->used = 0;
    a->size = tamanioInicial;
}

void insertArray(Array *a, token element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(token));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void match(token);
void objetivo(void);
void programa(void);
void listaDeSentencias(void);
void sentencia(void);
void expresionleftpar(void);
void expresion(void);
void operador(void);