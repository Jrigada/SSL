#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

typedef enum {t_id,t_sum,t_mul,t_constNum,t_eof,t_null} token;

#define ERROR -1

token scan(int);

token scan(c) {

// while ((c = getchar()) == ' ' || c == '\n');
    
    if (isalpha(c)) { 
        return t_id;    
    } else if (isdigit(c)) {
        return t_constNum;
    } else if (c =='+') {
        return t_sum;
    } else if (c =='*') {
        return t_mul;
    } else {
        printf("%s\n","UNRECOGNIZED TOKEN");
        }
    
    return 0;
}
