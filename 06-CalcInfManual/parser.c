#include "parser.h"
#include <stdbool.h>

extern token currentToken;

//creo el array de tokens
Array a; 

CharArray b;

int posicionArray = 0;

bool valid = true;

int calculo = 0;

int var1 = 0;

int term = 0;

int parentesisAbierto = 0;

token currentOperator;

int main(void){

//inicializo el array de tokens
initArray(&a, 5);

initCharArray(&b, 5);

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
            insertCharArray(&b,ch);
            insertArray(&a,tempToken);
        }
    }
//leo el array para chequear si es correcto
    // int i;
    // for (i=0;i<a.size;i++)
    //     printf("%d\n", a.array[i]);
    
    fclose(filePointer);


    objetivo();


    freeArray(&a);
    freeCharArray(&b);

    return 0;
}

void match(token b) {
    if (b == currentToken) {
        posicionArray++;
        currentToken = a.array[posicionArray];
    } else {
        valid = false;
        printf("%s\n","Error");
    }
}

int charToInt(char a) {
    return a - '0';
}

void objetivo(void) {
    currentToken = a.array[posicionArray];
    programa();
    match(t_eof);
    if (parentesisAbierto != 0) {
            valid = false;
        }
    if (!valid) {
        printf("%s\n","Expresion invalida");
    } else {
        printf("%s\n","Expresion valida");
        printf("%d\n",calculo);
    }
}

void programa(void) {
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

        case t_eof:
            match(t_id);
            break;

        default:
            valid = false;
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
        valid = false;
        printf("%s\n","fallo 2");
        break;
    }
}

void expresionleftpar(void){
    switch (currentToken) 
    {
    case t_constNum:


        var1 = charToInt(b.array[posicionArray]);
        printf("%d\n",var1);

        match(t_constNum);

        while(currentToken == t_constNum) {
            int i = 10;
            if(charToInt(b.array[posicionArray])==0) {
                var1 *= i;
            } else {
                var1 = var1*i + charToInt(b.array[posicionArray]);
            }
            
            match(t_constNum);
            i = i*10;
            printf("%d\n",var1);
        }

        if (currentOperator == t_mul) {
            term = (term * var1);
        }

        switch (currentToken)
        {
        case t_eof:
            if (currentOperator == t_mul) {
                calculo += term;
            } else {
                calculo += var1;
            }
            printf("%s\n","Terminamos");
            break;
        
        default:
            operador();
            break;
        }
        break;
    
    case t_leftpar:
        match(t_leftpar);
        parentesisAbierto ++;
        expresionleftpar();
        break;
    
    default:
        valid = false;
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
        if (currentOperator != t_mul) {
            term += var1;
        }
        currentOperator = t_mul;
        match(t_mul);
        expresionleftpar();
        break;
    
    case t_sum:
        if (currentOperator == t_mul) {
            calculo += term;
            term=0;
        } else {
        calculo = calculo + var1;
        }
        currentOperator = t_sum;
        match(t_sum);
        expresionleftpar();
        break;

    
    case t_rightpar: 
        parentesisAbierto --;
        match(t_rightpar);
        operador();
        break;

    case t_eof:
        break;

    default:
        valid = false;
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