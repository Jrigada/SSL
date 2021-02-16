#include "parser.h"
#include <stdbool.h>

extern token currentToken;

//creo el array de tokens
Array a; 

//array de valores reales
CharArray b;

int posicionArray = 0;

bool valid = true;

int calculo = 0;

int var1 = 0;

int varParentesis = 0;

int term = 0;

int termParentesis = 0;

int parentesisAbierto = 0;

int auxParentesis = 0;

token currentOperator;

token currentOperatorInsidePar;

int main(void){

    //inicializar tabla de simbolos
    initTablaDeSimbolos();

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
        printf("%s\n","Error en la validacion");
    }
}

int charToInt(char a) {
    return a - '0';
}

void objetivo(void) {
    currentToken = a.array[posicionArray];
    programa();
    match(t_eof);
    // if (parentesisAbierto != 0) {
    //         valid = false;
    //     }
    // if (!valid) {
    //     printf("%s\n"," invalida");
    // } else {
    //     printf("%s\n"," valida");
    //     printf("El resultado es %d\n",calculo);
    // }
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
        switch (currentToken)
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


    switch (currentToken)
    {
        //asignar un valor
        case t_id:
            identificadoAsignar = b.array[posicionArray]; //tomo el id de la variable a asignar y la guardo en una variable
            match(t_id);
            match(t_asig);
            calculo = suma();
            match(t_pyc);
            updateSymbolVal(identificadoAsignar,calculo); //actualizo la tabla de simbolos con el valor asignado
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


//TODO: NO separa en terminos, multiplicacion un nivel mas adentro que suma?
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

    int total = 0;

    switch (currentToken) 
    {
        case t_sum:
            match(t_sum);
            total = calculoSuma + suma();
            return total;
            break;

        default: 
            return calculoSuma;
            break;
    } 

}

int multiplicacion(){   

    int calculoMultiplicacion;

    int total = 0;

    calculoMultiplicacion = datoElemental();

    switch (currentToken)
    {
    case t_mul:
        match(t_mul);
        total = calculoMultiplicacion * multiplicacion();
        return total;
        break;

    default:
        return calculoMultiplicacion;
        break;
    }
}

int datoElemental() {
    int calculoDatoElemental = 0;

    switch (currentToken)
    {
    case t_constNum:
        calculoDatoElemental = charToInt(b.array[posicionArray]);
        match(t_constNum);

        //funcion para numeros de mas de una cifra
        while(currentToken == t_constNum) {
            int i = 10;
            if(charToInt(b.array[posicionArray])==0) {
                calculoDatoElemental *= i;
            } else {
                calculoDatoElemental = calculoDatoElemental*i + charToInt(b.array[posicionArray]);
            }
            
            match(t_constNum);
            i = i*10;
        }

        
        return calculoDatoElemental;
        break;

    case t_id:
        calculoDatoElemental = symbolVal(b.array[posicionArray]);
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
