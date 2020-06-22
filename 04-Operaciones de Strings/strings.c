#include <stdio.h>
#include "string.h"
#include <stdbool.h>

int main()
{
    return 0;
}

int getLength()
{
    char string[20];
    int i = 0;

    printf("\nCONTADOR DE CARACTERES\n");
    printf("\nIngrese una cadena de caracteres\n");

    while ((string[i] = getchar()) != '\n')
        i++;
    getchar();

    return i;
}

bool isEmpty()
{
    char string[20];
    int i = 0;

    printf("\nisEmpty\n");
    printf("\nIngrese una cadena de caracteres\n");

    while ((string[i] = getchar()) != '\n')
        i++;
    getchar();

    if (i != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// char* power (){
//     char a[20];
//     int b = 3;
//     if (b==0) return NULL;
//     char *result = ?


// }

int posicionCaracter (){
    char a[20];
    char b;
    int i = 0;

    while ((a[i] = getchar()) != '\n')
        if (a[i] == b) return i;
        else i++;
    getchar();

}