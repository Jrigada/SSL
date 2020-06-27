#include <stdio.h>
#include "string.h"
#include <stdbool.h>
#include <string.h>

unsigned GetLength(char* s)
{
    int i = 0;
    for (i = 0; s[i] != '\0'; ++i)
        ;
    return i;
}

bool IsEmpty(char* s)
{
    int i = 0;

    for (i = 0; s[i] != '\0'; ++i)

        if (i = 0)
        {
            return true;
        }
        else
        {
            return false;
        }
}

char* Power(char* s, unsigned n)
{

    return n == 0 ? "" : n == 1 ? s : strcat(s, Power(s, (n - 1)));
}

int PosicionCaracter(char* s, char* c)
{
    int i = 0;

    for (i = 0; s[i] != '\0'; i++)
         if (strcmp(s[i],c)==0) return i;
}
