#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#include "scanner.h"

int main(void) {

    scan();

    return 0;
}


token scan() {
    char c;

    scanf("%c",&c);
    
    while(c != EOF) {
    if (isalpha(c)) {
        return t_id;
        printf("%s\n","IDENTIFICADOR");
    } else if (isdigit(c)) {
        return t_constNum;
        printf("%s\n","CONSTANTE NUMERICA");
    } else if (c =='+') {
        return t_sum;
        printf("%s\n","OPERADOR SUMA");
    } else if (c =='*') {
        return t_mul;
        printf("%s\n","OPERADOR MULTIPLICACION");
    } else {
        printf("%s\n","UNRECOGNIZED TOKEN");
        }
    }
    
    return 0;
}
        