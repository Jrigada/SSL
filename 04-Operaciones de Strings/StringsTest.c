/*
Juan Rigada
21-06-2020
*/

#include <stdio.h>
#include <assert.h>
#include "strings.h"
#include <stdbool.h>
#include <string.h>

int main()
{
    assert(0 == GetLength(""));
    assert(4 == GetLength("test"));
    assert(!IsEmpty("test"));
    assert(0 == strcmp("", Power("test", 0)));
    assert(0 == strcmp("",Power("", 1)));
    assert(0 == strcmp("testtest",Power("test", 2)));
    assert(2 == PosicionCaracter("test","e"));
    return 0;
}