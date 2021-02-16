#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef enum {t_id,t_sum,t_mul,t_constNum,t_eof,t_null,t_leftP,t_rightP,terminated,null} token;

#define ERROR -1
