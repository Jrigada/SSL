#include "array.h"

void initCharArray(CharArray *a,size_t tamanioInicial) {
    a->array = malloc(tamanioInicial * sizeof(int));
    a->used = 0;
    a->size = tamanioInicial;
}

void insertCharArray(CharArray *a, char element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(char));
  }
  a->array[a->used++] = element;
}

void freeCharArray(CharArray *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}
