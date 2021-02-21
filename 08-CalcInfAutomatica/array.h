#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef struct {
  char *array;
  size_t used;
  size_t size;
} CharArray;

void initCharArray(CharArray*,size_t);
void insertCharArray(CharArray*, char);
void freeCharArray(CharArray*);