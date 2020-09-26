#include "parser.h"
#include <stdbool.h>

int main(void){
    token tokens[30];
    bool result;

    int tokenIndex = 0;
    char str[100];
    char *ptr;
     
    printf("Ingresa una expresion: ");
    gets(str);

     
    size_t i = 0;
    
    while (str[i] != '\0') {       /* Stop looping when we reach the null-character. */
        tokens[tokenIndex] = scan(str[i]);  /* Print each character of the string. */
        i++;
    } 
         
    result = parsear(tokens,tokenIndex);
    
    if (result == true) {
        printf("%s\n","Expresion valida");
    } else {
        printf("%s\n","Expresion invalida");
    }

    return 0;
}

bool parsear(token *tokens, int token_len) {
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
    }
    return valid_exp;
}

bool esParValido(token a, token b) {
    if ((a == t_mul && b == t_sum)||(a == t_sum && b == t_mul)) {
        return false;
    } else {
        return true;
        }
}