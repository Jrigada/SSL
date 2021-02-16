#include "parser.h"
#include <stdbool.h>

int main(void){
    extern int yylex();
    extern int yylineno;
    extern char* yytext;
    token tokens[30];
    bool result;
    token a = t_null;
    int calculo = 0;
    int aux = 0;
    int operando1 = 0;
    bool parentesisAbierto = false;
    bool noError = true;

    token ultimoOperador;

    int tokenIndex = 0;
    char str[100];
     
    size_t i = 0;

    int ntoken, vtoken;

    ntoken = yylex();
    
    while (ntoken != terminated) {   
        tokens[tokenIndex] = ntoken; 
        if (ntoken == t_constNum) {
            aux = aux*10;
            calculo = atoi(yytext) + aux;
            aux = calculo;
        } else if (ntoken == t_sum) {
            ultimoOperador = t_sum;
            operando1 += calculo;
            aux = 0;
            calculo = 0;
        } else if (ntoken == t_mul) {
            ultimoOperador = t_mul;
            operando1 = 1;
            operando1 *= calculo;
            aux = 0;
            calculo = 0;
        } else if (ntoken == t_leftP) {
            parentesisAbierto = true;
        } else if (ntoken == t_rightP && parentesisAbierto) {
            parentesisAbierto = false;
        } else if (ntoken == null) {
            noError = false;
        }
        ntoken = yylex();
        i++;
        tokenIndex++;
    }
    result = parsear(tokens,tokenIndex,parentesisAbierto);
    
    if (result && noError) {
        printf("%s\n","Expresion valida");
        if (ultimoOperador == t_sum) {
            operando1 += calculo;
        } else if (ultimoOperador == t_mul) {
            operando1 *= calculo;
        } 
        printf("%s%d\n","El resultado es: ",operando1);
    } else {
        printf("%s\n","Expresion invalida");
    }

    return 0;
}

bool parsear(token *tokens, int token_len, bool parentesisAbierto) {
    int i;
    bool valid_exp;
    token token_anterior = t_null;

    for ( i=0 ; i<=token_len ; i++ ){
        if (token_anterior == t_null){
            if (tokens[i] == t_mul || tokens[i] == t_sum) {
                valid_exp = false; 
                break;
            } else {
                token_anterior = tokens[i];
                };
        } else if (!esParValido(token_anterior,tokens[i])) {
        valid_exp = false;
        break;
        } else { 
            valid_exp = true;
    }
    if (parentesisAbierto) {
        valid_exp = false;
        }
    return valid_exp;
    }
}

bool esParValido(token a, token b) {

    if ((a == t_mul && b == t_sum)||(a == t_sum && b == t_mul)) {
        return false;
    } else {
        return true;
        }
}