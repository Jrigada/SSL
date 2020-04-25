# Hello.cpp vs Hello.c

## Hello.cpp

```
#include <iostream>

int main() {
    std::cout << "Hello World!";
    return 0;
}
```

## Hello.c

```
#include <stdio.h>

main() {
  printf("Hello World!\n");
}
```

----------------------

|Lenguaje|&nbsp;Lexico |&nbsp; Sintactico | &nbsp;Semantico|
|---------|-----|---------|-----|
|C++|* Define el tipo de dato de la funcion main <br> * Retorna cero para terminar la funcion main |* Utiliza ```<iostream>``` como biblioteca de encabezados <br>  * Utiliza std::cout para agregar el texto al flujo de salida <br> |<br>|
|<br>|
|C|* No incluye el tipo de dato en la funcion main <br>  * No retorna ningun valor al terminar la funcion| * Utiliza ```<stdio.h> ``` como biblioteca de encabezados <br> * Utiliza la funcion printf para realizar el output del texto <br> |<br>|


--------------------
