    #include <stdio.h>
    #include <assert.h>
    #include "string.h"
    #include <stdbool.h>

int main(){

}

int getLength()
{
    char a0[20]="test";
    int i = 0;

    while ((a0[i] = getchar()) != '\n')
        i++;
    getchar();

    assert(i=4);

    return i;
}

bool isEmpty()
{
    char a1[20]="test";
    int i = 0;
    bool result;

    while ((a1[i] = getchar()) != '\n')
        i++;
    getchar();

    if (i != 0)
    {
        result = false;
    }
    else
    {
        result =true;
    }

    assert(result = true);
}

// char* power (char* a,int b){
//     char a[20];
//     int b = 3;
//     if (b==0) return NULL;
//     char *result = ?


// }

// int posicionCaracter (){
//     char a2[20] = "test";
//     char b2 = "e";
//     int i = 0;

//     while ((a2[i] = getchar()) != '\n')
//         if (a2[i] == b2) return i;
//         else i++;
//     getchar();

//     assert (i=1);

// }
    