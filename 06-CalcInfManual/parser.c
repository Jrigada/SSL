#include "parser.h"
#include <stdbool.h>

extern token currentToken;

//creo el array de tokens
Array a; 

int posicionArray = 0;

int main(void){

//inicializo el array de tokens
initArray(&a, 5);

//punteros y variable para leer el txt
    FILE *filePointer; 
    char ch;

//variable temporal para llenar el array
token tempToken;

    filePointer = fopen("example.txt", "r");

    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        //4
        while ((ch = fgetc(filePointer)) != EOF)
        {
            //scanner me analiza los caracteres del txt y me los carga en el array
            tempToken = getNextToken(ch);
            // programa();
            insertArray(&a,tempToken);
        }
    }
//leo el array para chequear si es correcto
    int i;
    for (i=0;i<a.size;i++)
        printf("%d\n", a.array[i]);
    
    fclose(filePointer);


    objetivo();


    freeArray(&a);

    return 0;
}

void match(token b) {
    if (b == currentToken) {
        posicionArray++;
        currentToken = a.array[posicionArray];
        printf("%s\n","La pegamos");
    } else {
        printf("%s\n","No la pegamos");
    }
}

void objetivo(void) {
    currentToken = a.array[posicionArray];
    programa();
    match(t_eof);
    printf("%s\n","Terminado");
}

void programa(void) {
    // match(t_id);
    listaDeSentencias();
}

void listaDeSentencias(void) {
    sentencia();
}

void sentencia(void){
    switch (currentToken)
    {
    case t_id:
        switch (a.array[posicionArray+1])
        {
        case t_asig:
            match(t_id);
            match(t_asig);
            match(t_constNum);
            printf("%s\n","matcheada la asignacion");
            break;
        
        case t_mul: 
            match(t_id);
            match(t_mul);
            expresionleftpar();
            break;

        case t_sum:
            match(t_id);
            match(t_sum);
            expresionleftpar();
            break;

        default:
            printf("%s\n","fallo 1");
            break;
        }
        break;
    case t_constNum:
        expresionleftpar();
        break;

    case t_leftpar:
        expresionleftpar();
        break;
    default:
        printf("%s\n","fallo 2");
        break;
    }
}

void expresionleftpar(void){
    switch (currentToken) 
    {
    case t_id:
        match(t_id);
        while (currentToken == t_id)
        {
            match(t_id);
        }
        operador();
        break;
    
    case t_constNum:
        match(t_constNum);
        switch (currentToken)
        {
        case t_eof:
            printf("%s\n","Terminamos");
            break;
        
        default:
            operador();
            break;
        }
        break;
    
    case t_leftpar:
        match(t_leftpar);
        expresionleftpar();
        break;
    
    default:
        printf("%s\n","fallo 3");
        break;
    }
}

// void expresion(void){
//     switch (currentToken) 
//     {
//     case t_id:
//         match(t_id);
//         while (currentToken == t_id)
//         {
//             match(t_id);
//         }
//         operador();
//         break;
    
//     case t_constNum:
//         match(t_constNum);
//         operador();
//         break;
    
//     case t_rightpar:
//         match(t_rightpar);
//         expresionleftpar();
//         break;
    
//     default:
//         printf("%s\n","fallo 3");
//         break;
//     }
// }

void operador(void){
    switch (currentToken)
    {
    case t_mul:
        match(t_mul);
        expresionleftpar();
        break;
    
    case t_sum:
        match(t_sum);
        expresionleftpar();
        break;
    
    default:
        printf("%s\n","fallo 4");
        break;
    }
}


//     token tokens[30];


//     int tokenIndex = 0;
//     char str[100];
     
//     printf("Ingresa una expresion: ");
//     gets(str);

     
//     size_t i = 0;
    
//     while (str[i] != '\0') {      
//         tokens[tokenIndex] = getNextToken(str[i]); 
//         i++;
//     } 
         
//     result = parsear(tokens,tokenIndex);
    
//     if (result == true) {
//         printf("%s\n","Expresion valida");
//     } else {
//         printf("%s\n","Expresion invalida");
//     }

//     return 0;
// }

// bool parsear(token *tokens, int token_len) {
//     int i;
//     bool valid_exp;
//     token token_anterior = t_null;

//     for ( i=0 ; i<=token_len ; i++ ){
//         if (token_anterior == t_null){
//             if (tokens[i] == t_mul || tokens[i] == t_sum) {
//                 valid_exp = false; 
//                 break;
//             } else {
//                 token_anterior = tokens[i];
//                 };
//         } else if (!esParValido(token_anterior,tokens[i])) {
//         valid_exp = false;
//         break;
//         } else {
//             valid_exp = true;
//         }
//     }
//     return valid_exp;
// }

// bool esParValido(token a, token b) {
//     if ((a == t_mul && b == t_sum)||(a == t_sum && b == t_mul)) {
//         return false;
//     } else {
//         return true;
//         }
// }