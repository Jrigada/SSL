#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef enum {t_id,t_sum,t_mul,t_constNum,t_eof,t_leftpar,t_rightpar,t_null,t_pyc,t_asig} token;

#define ERROR -1

token getNextToken(int);

token currentToken = t_null;

token getNextToken(c) {
    
    if (isalpha(c)) { 
        return t_id;
        currentToken = t_id;    
    } else if (isdigit(c)) {
        return t_constNum;
        currentToken = t_constNum;
    } else if (c =='+') {
        return t_sum;
        currentToken = t_sum;
    } else if (c =='*') {
        return t_mul;
        currentToken = t_mul;
    }  else if (c =='=') {
        return t_asig;
        currentToken = t_asig;
    }else if (c =='/') {
        return t_eof;
        currentToken = t_eof;
    } else if (c =='(') {
        return t_leftpar;
        currentToken = t_leftpar;
    } else if (c ==')') {
        return t_rightpar;
        currentToken = t_rightpar;
    } else if (c ==';') {
        return t_pyc;
        currentToken = t_pyc;
    }
     else {
        printf("%s\n","UNRECOGNIZED TOKEN");
        }
    
    return 0;
}
