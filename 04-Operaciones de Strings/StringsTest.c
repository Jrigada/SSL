    #include <stdio.h>
    #include <assert.h>
    #include "string.h"
    #include <stdbool.h>

int main(){

    assert(0==strcmp("4",getLength("hola")));
    assert(0==strcmp(false,isEmpty("hola")));
    assert(0==strcmp("ababab",power("ab",3)));
    assert(0==strcmp("1",contieneCaracter("hola","o")));

}

