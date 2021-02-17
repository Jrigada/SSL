#include "parser.h"
#include <stdbool.h>

//array de valores reales
CharArray b;

int main(void){

    //inicializar tabla de simbolos
    initTablaDeSimbolos();

    //inicializo el array de tokens
    // initArray(&a, 5);

    initCharArray(&b, 5);

    // //punteros y variable para leer el txt
    // FILE *filePointer; 
    // char ch;

    // //variable temporal para llenar el array
    // token tempToken;

    // filePointer = fopen("example.txt", "r");

    // if (filePointer == NULL)
    // {
    //     printf("File is not available \n");
    // }
    // else
    // {
    //     //4
    //     while ((ch = fgetc(filePointer)) != EOF)
    //     {
    //         //scanner me analiza los caracteres del txt y me los carga en el array
    //         tempToken = getNextToken(ch);
    //         // programa();
    //         insertCharArray(&b,ch);
    //         insertArray(&a,tempToken);
    //     }
    // }
    
    // fclose(filePointer);


    objetivo();


    return 0;
}

void match(token tokenEsperado) {
    if (tokenEsperado == getNextToken()) {
    } else {
        printf("%s\n","Error en la validacion del token");
    }
    
    tokenMatched = false;
}

int charToInt(char a) {
    return a - '0';
}

void objetivo(void) {
    programa();
    match(t_eof);
}

void programa() {
    listaDeSentencias();
}

//Muchnik Vol2
// void ListaSentencias (void) {
// /* <listaSentencias> -> <sentencia> {<sentencia>} */
// Sentencia(); /* la primera de la lista de sentencias */
// while (1) { /* un ciclo indefinido */
// switch (ProximoToken()) {
// case ID: case LEER: case ESCRIBIR: /* detectó token correcto */
// Sentencia(); /* procesa la secuencia opcional */
// break;
// default:
// return;
// } /* fin switch */
// }
// }

void listaDeSentencias() {
    sentencia();
    while(1) {
        switch (getNextToken())
        {

        case t_print:
            sentencia();
            break;

        case t_id:
            sentencia();
            break;
        
        default:
            return;
        }
    }
}

void sentencia(){

    char identificadoAsignar;
    int calculoSentencia;

    switch (getNextToken())
    {
        //asignar un valor
        case t_id:
            identificadoAsignar = b.array[0]; //tomo el id de la variable a asignar y la guardo en una variable
            match(t_id);
            match(t_asig);
            calculoSentencia = suma();
            match(t_pyc);
            updateSymbolVal(identificadoAsignar,calculoSentencia); //actualizo la tabla de simbolos con el valor asignado
            break;

        //calcular valor, agrego el token print para poder diferenciar desde un primer momento si es una asignacion o una operacion que devuelve un resultado
        case t_print: 
            match(t_print);
            calculoSentencia  = suma();
            printf("El resultado es %d\n",calculoSentencia);
            break;

        default:
            // valid = false;
            // printf("%s\n","fallo 1");
            break;
        }
       
}


//TODO: NO separa en terminos
// int expresion() {

//     calculo = datoElemental();

//     switch (currentToken) 
//     {
//         case t_sum:
//             int total;
//             match(t_sum);
//             total = calculo + datoElemental();
//             return total;
//             break;

//         case t_mul:
//             int total;
//             match(t_mul);
//             total = calculo + datoElemental();

//         default: 
//             return calculo;
//     }
// }


int suma(){
    int calculoSuma;

    calculoSuma = multiplicacion();

    switch (getNextToken()) 
    {
        case t_sum:
            match(t_sum);
            return calculoSuma + suma();;
            break;

        default:
            
            return calculoSuma;
            break;
    } 

}

int multiplicacion(){   

    int calculoMultiplicacion;

    calculoMultiplicacion = datoElemental();

    switch (getNextToken()) //ESTE SWITCH ME COME UN TOKEN Y SE ME CORRE TODO
    {
    case t_mul:
        
        match(t_mul);
        return calculoMultiplicacion * multiplicacion();
        break;

    default:
        
        return calculoMultiplicacion;
        break;
    }
}

int datoElemental() {
    int calculoDatoElemental = 0;
    
    switch (getNextToken())
    {
    case t_constNum:
        
        match(t_constNum);
        calculoDatoElemental = atoi(b.array);

        // //funcion para numeros de mas de una cifra
        // while(getNextToken() == t_constNum) {
        //     int i = 10;
        //     if(charToInt(b.array[posicionArray])==0) {
        //         calculoDatoElemental *= i;
        //     } else {
        //         calculoDatoElemental = calculoDatoElemental*i + charToInt(b.array[posicionArray]);
        //     }
            
        //     match(t_constNum);
        //     i = i*10;
        // }

        return calculoDatoElemental;
        break;

    case t_id:
        
        calculoDatoElemental = symbolVal(b.array[0]);
        match(t_id);
        return calculoDatoElemental;
        break;

    case t_leftpar:
        
        match(t_leftpar);
        // parentesisAbierto++;
        calculoDatoElemental = suma();
        match(t_rightpar);
        return calculoDatoElemental;
        // parentesisAbierto--;
        break;
    
    default:
        
        return calculoDatoElemental;
        break;
    }
}
