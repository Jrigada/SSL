#Examen 0
##Juan Rigada

###Parte 1
1. La tarea más significativa que desempeña un Ingeniero en sistemas de la información es la de diseñar, proyectar y analizar un sistema determinado para garantizar su correcto funcionamiento. 
2. La información es un conjunto de datos o representaciones formales de un hecho o concepto, aptos para su comunicación. 
3. Las asignaturas dentro del área de programación son matemática Discreta, Algoritmos y Estructuras de datos, Sintaxis y semántica de los lenguajes, Paradigmas de programación y gestión de Datos. 
4. Las asignaturas del área de sistemas de información son Sistemas y Organizaciones, análisis de Sistemas, Diseño de Sistemas y administración de Recursos. 
5. El paradigma aplicado en el primer año de la carrera es el paradigma de programación estructurada. 
6. La abstracción es el proceso de análisis del mundo real con el propósito de interpretar los aspectos esenciales de un problema y expresarlo en términos precisos. 

###Parte 2
1. Un conjunto es una colección de objetos agrupados según una propiedad determinada. Una secuencia agrupa elementos según una propiedad determinada enumerados en un orden especifico. 
2. Una secuencia es una agrupación de elementos que tiene un orden determinado siguiendo un criterio predeterminado. 
3. Una función matemática es una relación entre un conjunto de variables de entrada y un conjunto de variables de salida en donde a cada una de las variables de entrada le corresponde una variable de salida.
4. Un grafo es un conjunto de vértices unidos por aristas utilizado para crear representaciones de la información relevante de un problema de la realidad. 
5. Una partición es una colección de subconjuntos del original en donde cada uno de ellos es no vacío, son disjuntos dos a dos y en donde la unión de todos ellos forma el conjunto original. 
6. Siendo X = {a, b} => P(X) = {{a}, {b}, {a, b}}    
7. Un lenguaje formal es aquel producido por un alfabeto y sus reglas de formación determinadas. 
8. Un autómata finito es un tipo de máquina de estado finito que cumple con el objetivo de reconocer lenguajes regulares. 

###Parte 3
1. Un algoritmo es una serie finita de pasos con el objetivo de resolver un problema determinado. 
2. La programación estructurada se basa en un paradigma de programación que facilita la creación de programas con código legible, ordenado y reutilizable haciendo uso principalmente de módulos o bloques de código. (rev)
3. Las tres estructuras de control en la programación estructurada son la secuencial, condicional e iterativa. 
4. Un parámetro es una representación de un valor dentro de una función o procedimiento, no es el valor en sí. El valor de este parámetro es lo que se le pasa a la función cuando se la necesita ejecutar y a este se le llama argumento. 
5. Un argumento puede ser pasado a una función o procedimiento por valor o por referencia. Cuando se pasa por valor se pasa una copia del contenido del lugar de memoria que ocupa este, no se pasa la dirección de memoria donde está ubicado. Contrario a esto sería pasar un valor por referencia en donde directamente se le pasa la ubicación en memoria lo que permite que se modifique desde el origen el valor pasado. 
6. Los parámetros se dividen en parámetros de Salida, de Entrada y de Entrada/Salida. Los de salida son aquellos que reciben los valores resultantes de la función para realizar su retorno al programa principal en cambio los parámetros de entrada se encargan de almacenar los valores pasados del programa principal para realizar la función que se quiera realizar. <br>
Los parámetros de Entrada/Salida entran en juego cuando el valor es pasado a una función como valor de referencia y se debe almacenar en un parámetro y realizarle un cambio en memoria para luego retornarlo.  
7. El tipo de dato abstracto es un modelo de datos en donde el usuario conoce que funcion realiza y que valores puede otorgarle pero no como transforma las entradas en las salidas. 
8. Las pilas y las colas son estructuras de datos dinámicas. La diferencia entre ellas radica en la cantidad de punteros necesarios para su operación, en el caso de las pilas necesitamos uno en cambio en las colas se necesitan dos. también difieren en la forma en la que se desplazan los datos dentro de ellas, en las colas responde a un momento FIFO o First In First Out mientras que en las pilas es LIFO o Last In First Out. 
9. Un archivo es un conjunto de datos que se encuentran almacenados en disco.
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

