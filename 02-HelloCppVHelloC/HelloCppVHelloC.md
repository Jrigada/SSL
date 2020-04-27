# Hello.cpp vs Hello.c

## Hello.cpp

```
#include <iostream>

int main() {
    std::cout << "Hello World!";
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
|C++|* Ambos incluyen una biblioteca <br> * Define el tipo de dato de la funcion main <br> * Las sentencias dentro de las funciones tambien <br> tienen una diferencia lexica |* Utiliza ```<iostream>``` como biblioteca de encabezados <br>  * Utiliza std::cout para agregar el texto al flujo de salida <br> |* Utiliza cout siendo esta un objeto global de la libreria y no una funcion|
|<br>|
|C|* No incluye el tipo de dato en la funcion main <br> * Las sentencias dentro de las funciones son diferentes en sus componentes,<br> printf no es lo mismo que std::cout * No retorna ningun valor al terminar la funcion| * Utiliza ```<stdio.h> ``` como biblioteca de encabezados <br> * Utiliza la funcion printf para realizar el output del texto <br> |* Utiliza dentro de Main una funcion, printf|


--------------------
