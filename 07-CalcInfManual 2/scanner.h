#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "array.h"
#include <stdbool.h>

typedef enum {t_id,t_sum,t_mul,t_constNum,t_eof,t_leftpar,t_rightpar,t_null,t_pyc,t_asig,t_print} token;

#define ERROR -1

extern CharArray b;

extern token currentToken;

extern bool tokenMatched;

token getNextToken(void);
void guardarValor(char c);
void devolverValor(char c);
