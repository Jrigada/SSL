# Examen 0
## Juan Rigada

### Parte 1
1. La tarea más significativa que desempeña es la de hacer sistemas de informacion. Diseñar, proyectar y analizarlo para garantizar su correcto funcionamiento. 
2. La información es un conjunto de datoss procesados.  
3. Las asignaturas dentro del área de programación son matemática Discreta, Algoritmos y Estructuras de datos, Sintaxis y semántica de los lenguajes, Paradigmas de programación y gestión de Datos. 
4. Las asignaturas del área de sistemas de información son Sistemas y Organizaciones, análisis de Sistemas, Diseño de Sistemas, administración de Recursos y proyecto final.
5. El paradigma aplicado en el primer año de la carrera es el paradigma de programación procedural. 
6. La abstracción es el proceso de análisis del mundo real con el propósito de interpretar los aspectos esenciales de un problema y expresarlo en términos precisos. Separar un problema permite analizarlo mejor. 

### Parte 2
1. Un conjunto es una colección de objetos agrupados según una propiedad determinada. Una secuencia agrupa elementos según una propiedad determinada enumerados en un orden especifico. 
2. Una secuencia es una agrupación de elementos que tiene un orden determinado siguiendo un criterio. 
3. Una función matemática es una relación entre un conjunto de variables de entrada y un conjunto de variables de salida que cumple con unicidad y existencia.
4. Un grafo es un conjunto de duplas relacionadas.
5. Una partición es una colección de subconjuntos del original en donde cada uno de ellos es no vacío, son disjuntos dos a dos y en donde la unión de todos ellos forma el conjunto original. 
6. Siendo X = {a, b} => P(X) = {{a}, {b}, {a, b}}    
7. Un lenguaje formal es aquel producido por un alfabeto y sus reglas de formación determinadas. 
8. Un autómata finito es un tipo de máquina de estado finito que cumple con el objetivo de reconocer lenguajes regulares. 

### Parte 3
1. Un algoritmo es una secuencia determinista y finita de pasos con un objetivo concreto. 
2. La programación estructurada se basa en un paradigma de programación que facilita la creación de programas con código legible, ordenado y reutilizable haciendo uso principalmente de módulos o bloques de código. Utiliza funciones principalmente y su codigo se lee en forma de secuencia utilizando iteraciones y condicionales como sus estructuras de control.
3. Las tres estructuras de control en la programación estructurada son la secuencial, condicional e iterativa. 
4. Un parámetro es una representación de un valor dentro de una función o procedimiento, no es el valor en sí. El valor de este parámetro es lo que se le pasa a la función cuando se la necesita ejecutar y a este se le llama argumento. 
5. Un argumento puede ser pasado a una función o procedimiento por valor o por referencia. Cuando se pasa por valor se pasa una copia del contenido del lugar de memoria que ocupa este, no se pasa la dirección de memoria donde está ubicado. Contrario a esto sería pasar un valor por referencia en donde directamente se le pasa la ubicación en memoria lo que permite que se modifique desde el origen el valor pasado. 
6. Los parámetros se dividen en parámetros de Salida, de Entrada y de Entrada/Salida. Los de salida son aquellos que reciben los valores resultantes de la función para realizar su retorno al programa principal en cambio los parámetros de entrada se encargan de almacenar los valores pasados del programa principal para realizar la función que se quiera realizar. <br>
Los parámetros de Entrada/Salida entran en juego cuando el valor es pasado a una función como valor de referencia y se debe almacenar en un parámetro y realizarle un cambio en memoria para luego retornarlo.  
7. El tipo de dato abstracto es un conjunto de valores y operaciones en donde el usuario no conoce como estan representados los valores ni como es su implementacion de operaciones. 
8. Ambas son estructuras formadas por secuencias de elementos con el objetivo de almacenar cosas, la diferencia es en la forma de operar cada una. En una pila se agregan elementos o se sacan con Push y Pop respectivamente y en una cola se encola y desencola. Al expulsar elementos de la secuencia en una pila obtendre el mas reciente incorporado en cambio en una cola obtendre el primero que se incorporo. 
9. Un archivo es un conjunto de datos que se encuentran almacenados en disco, nos brinda mayor persistencia y menor costo aunque es de una velocidad de lectura y escritura menor que otras opciones. 
10.
```
double promedio(int values[], int l){
    double acum = 0;
    for(int i=0; i<=l-1; i++){
        acum = acum + values[i];
    }
    return acum/l;
}
int main() {
    int a[] = {2,5,6,9};
    int n=4;
    double prom = promedio(a,n);

    std::cout<<prom;
    return 0;
}

