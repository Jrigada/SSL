#include "parser.h"
#include <stdbool.h>

int main(void){
    token tokens[30];
    bool result;
    token a = t_null;
    int calculo = 0;
    int aux = 0;
    int operando1 = 0;
    bool parentesisAbierto = false;

    token ultimoOperador;

    int tokenIndex = 0;
    char str[100];
     
    printf("Ingresa una expresion: ");
    gets(str);
     
    size_t i = 0;
    
    while (str[i] != '\0') {      
        a = getNextToken(str[i]);
        tokens[tokenIndex] = a; 
        if (a == t_constNum) {
            aux = aux*10;
            calculo = (str[i]-'0') + aux;
            aux = calculo;
        } else if (a == t_sum) {
            ultimoOperador = t_sum;
            operando1 += calculo;
            aux = 0;
            calculo = 0;
        } else if (a == t_mul) {
            ultimoOperador = t_mul;
            operando1 = 1;
            operando1 *= calculo;
            aux = 0;
            calculo = 0;
        } else if (a == t_leftP) {
            parentesisAbierto = true;
        } else if (a == t_rightP && parentesisAbierto) {
            parentesisAbierto = false;
        } 
        i++;
    } 
         
    result = parsear(tokens,tokenIndex,parentesisAbierto);
    
    if (result) {
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