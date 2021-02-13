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

int varParentesis = 0;

int term = 0;

int termParentesis = 0;

int parentesisAbierto = 0;

int auxParentesis = 0;

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
            expresionLeftPar();
            break;

        case t_sum:
            match(t_id);
            match(t_sum);
            expresionLeftPar();
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
        expresionLeftPar();
        break;

    case t_leftpar:
        expresionLeftPar();
        break;
    default:
        valid = false;
        printf("%s\n","fallo 2");
        break;
    }
}

void expresionLeftPar(void){
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
        expresionRightPar();
        break;
    
    default:
        valid = false;
        printf("%s\n","fallo 3");
        break;
    }
}

void expresionRightPar(void){

    switch (currentToken) 
    {
    case t_constNum:
        varParentesis = charToInt(b.array[posicionArray]);
        printf("%d\n",varParentesis);

        match(t_constNum);

        while(currentToken == t_constNum) {
            int i = 10;
            if(charToInt(b.array[posicionArray])==0) {
                varParentesis *= i;
            } else {
                varParentesis = varParentesis*i + charToInt(b.array[posicionArray]);
            }
            
            match(t_constNum);
            i = i*10;
            printf("%d\n",varParentesis);
        }

        if (currentOperator == t_mul) {
            termParentesis = (termParentesis * varParentesis);
        }

        switch (currentToken)
        {
        case t_eof:
            if (currentOperator == t_mul) {
                auxParentesis += termParentesis;
            } else {
                auxParentesis += varParentesis;
            }
            break;
        
        default:
            operadorInsidePar();
            break;
        }
        break;
    
    case t_leftpar:
        match(t_leftpar);
        parentesisAbierto ++;
        expresionRightPar();
        break;
    
    default:
        valid = false;
        printf("%s\n","fallo 5");
        break;
    }
}
void operador(void){
    switch (currentToken)
    {
    case t_mul:
        if (currentOperator != t_mul) {
            term += var1;
        }
        currentOperator = t_mul;
        match(t_mul);
        expresionLeftPar();
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
        expresionLeftPar();
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

void operadorInsidePar(void){
    switch (currentToken)
    {
    case t_mul:
        if (currentOperator != t_mul) {
            termParentesis += varParentesis;
        }
        currentOperator = t_mul;
        match(t_mul);
        expresionRightPar();
        break;
    
    case t_sum:
        if (currentOperator == t_mul) {
            auxParentesis += termParentesis;
            termParentesis=0;
        } else {
        auxParentesis = auxParentesis + varParentesis;
        }
        currentOperator = t_sum;
        match(t_sum);
        expresionRightPar();
        break;

    
    case t_rightpar: 
        parentesisAbierto --;
        match(t_rightpar);
        if (currentOperator == t_mul) {
            auxParentesis += termParentesis;
            term=0;
        } else {
        auxParentesis = auxParentesis + varParentesis;
        }
        switch (currentToken)
        {
        case t_mul:
            term = auxParentesis;
            match(t_mul);
            currentOperator = t_mul;
            expresionLeftPar();
            break;

        case t_sum: 
            calculo += auxParentesis;
            match(t_sum);
            currentOperator= t_sum;
            expresionLeftPar();
        
        default:
            break;
        }
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