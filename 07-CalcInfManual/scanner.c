#include "scanner.h"

CharArray b;

bool tokenMatched = false;

token currentToken = t_null;

token getNextToken() {

    if (!tokenMatched) {

    tokenMatched = true;

    freeCharArray(&b);

    int c;

    c= getchar();

    while (isspace(c)) {
        c = getchar();
    }

    if (isalpha(c)) {
        guardarValor(c);
        currentToken = t_id;
    } else if (isdigit(c)) {
        guardarValor(c);
        c = getchar();

        while (isdigit(c)) {
            guardarValor(c);
            c = getchar();
        }
        devolverValor(c);
        currentToken = t_constNum;
        
    } else if (c =='+') { 
        currentToken = t_sum;
    } else if (c =='*') {
        currentToken = t_mul;
    }  else if (c =='=') {
        currentToken = t_asig;
    }else if (c =='/') {
        currentToken = t_eof;
    } else if (c =='(') {
        currentToken = t_leftpar;
    } else if (c ==')') {
        currentToken = t_rightpar;
    } else if (c ==';') {
        currentToken = t_pyc;
    } else if (c =='@') {
        currentToken = t_print;
    }  else {
        printf("%s\n","UNRECOGNIZED TOKEN");
        }
    }

    // printf("%d",posicionArray);
    return currentToken;
}

void guardarValor(char c) {
    insertCharArray(&b,c);
}

void devolverValor(char c) {
    ungetc(c,stdin);
}