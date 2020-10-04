#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef enum {t_id,t_sum,t_mul,t_constNum,t_eof,t_null,t_leftP,t_rightP} token;

#define ERROR -1

token getNextToken(int);

token getNextToken(c) {

// while ((c = getchar()) == ' ' || c == '\n');
    
    if (isalpha(c)) { 
        return t_id;    
    } else if (isdigit(c)) {
        return t_constNum;
    } else if (c =='+') {
        return t_sum;
    } else if (c =='*') {
        return t_mul;
    } else if (c == '(') {
        return t_leftP;
    } else if (c == ')') {
        return t_rightP;
    } else {
        printf("%s\n","UNRECOGNIZED TOKEN");
        }
    
    return 0;
}
