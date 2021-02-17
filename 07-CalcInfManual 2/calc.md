# Calculadora manual

Definicion informal
<ul>
    - Los números posibles son todos aquellos enteros positivos </br>
    - Los identificadores seran una de las letras del alfabeto tanto mayusculas como minusculas </br>
    - Las unicas operaciones comprendidas por la calculadora seran suma (+) y multiplicacion (*) </br>
    - Toda sentencia que se quiera evaluar debera ser precedida por el operador print (@) </br>
    - La asignacion se realizara con el operador asignacion (=) seguido de una expresion y terminara con el operador puntoycoma (;) </br>
    - Cualquier entrada al programa debera terminar con el operador eof (/)
    - Los parentesis estan permitidos </br>
</ul></br>


# Nivel Lexico

## Gramatica Lexica 

```
<token> -> uno de <t_id> <t_constNum> <t_asig> <t_sum> <t_mul> <t_eof> 
<t_leftpar> <t_rightpar> <t_pyc> <t_print>
<t_id> -> [a-zA-Z]
<t_constNum> -> [0-9]
<t_asig> -> =
<t_sum> -> +
<t_mul> -> *
<t_eof> -> /
<t_leftpar> -> (
<t_rightpar> -> )
<t_print> -> @
<t_pyc> -> ;
```


 | Lexema   | Token      |
 | -------- | ---------- |
 | [a-zA-Z] | t_id       |
 | [0-9]    | t_constNum |
 | =        | t_asig     |
 | (        | t_leftpar  |
 | )        | t_rightpar |
 | +        | t_sum      |
 | *        | t_mul      |
 | @        | t_print    |
 | ;        | t_pyc      |
 | /        | t_eof      |
 <br/>

 ## Analisis Lexico
 El analisis lexico sera realizado por el modulo scanner en este caso **scanner.c** y **scanner.h** tomando los caracteres de un archivo .txt como metodo de entrada (**example.txt**). El metodo que expone el scanner sera la funcion **getNextToken()** que luego la utilizara el parser para obtener los tokens (uno por cada ejecucion de la funcion). 


 



# Gramatica Sintactica
```
<Objetivo> ::= <programa> t_eof
<programa> ::= <listaDeSentencias>
<listaDeSentencias> ::= <sentencia> {<sentencia>}
<sentencia> ::= <asignacion> | <operacion>
<asignacion> ::= t_id t_asig <suma> t_pyc
<operacion> ::= t_print <suma>
<suma> ::= <multiplicacion> {t_sum <multiplicacion>}
<multiplicacion> ::= <datoElemental> {t_mul <datoElemental>}
<datoElemental> ::= t_constNum {t_constNum} | t_id | t_leftpar <suma> t_rightpar
```

El analisis sintactico se encargara de analizar la secuencia que obtuvimos de tokens en el analisis lexico para identificar aquellas producciones validas dentro de nuestro lenguaje. 

Al ingresar una produccion lo que hacemos en el parser es "organizarla" en una estructura de arbol que representa la estructura de la entrada. Por ejemplo:

 ### <center>"2+2*2" sera representado por el siguiente arbol </center>
</br>
<center> <img src="example_tree.png"> </center>



MORE INFO

# Analisis Semantico

En esta etapa lo que nos importa es poder ir computando el valor que nos arrojan las distintas ramas del arbol sintactico que vayamos generando a medida que recorremos la produccion ingresada.

</br>

# Tecnica de analisis utilizada
La tecnica utilizada para realizar el parseo es en Analisis Descendente Recursivo en donde a traves de rutinas recursivas se va armando una estructura de arbol para la secuencia de entrada. 

Siempre que tengamos un elemento no terminal se utilizara para su analisis una funcion que puede ser recursiva y se denomina **PAS** O procedimiento de analisis sintactico. Estos PAS se realizaran hasta que lleguemos a elementos no terminales donde para asegurarnos que son validos utilizaremos una funcion **match()** que compara el token esperado con el que tenemos realmente. _Jorge D. Muchnik, 2010, vol 2_ 



En el caso de esta calculadora especifica se puede ver claramente esta estructura descendente recursiva en los siguientes PAS

<center> <img src="parse_diagrama.png"> </center>

</br>
El diagrama representa tres diferentes elementos sintacticos que pueden aparecer. La diferencia entre los distintos niveles nos permite lograr la evaluacion correcta con respecto al orden de evaluacion, lo que nos servira para luego en el analisis semantico computar el valor resultante. 

_Otfried Cheong School of Computing, Data Structures Course (CS206A)_


# Manejo de identificadores
Para los identificadores se utilizo un array de 52 posiciones una por cada letra minuscula y mayuscula del abecedario. Este array se inicializa al comienzo del programa colocando cero en todas sus posiciones. Al realizar una asignacion se realizan los siguientes pasos
</br></br>
<ul>
    1. Se computa el indice del identificador elegido en el array mediante la funcion computeSymbolIndex() </br></br>
    2.  Teniendo el indice se modifica el valor de esa posicion con el valor de a asignar</br></br>
    3.  A la hora de utilizar el valor asociado a un ID se utiliza la funcion symbolVal() que recibe dicho ID y nos devuelve el valor de la posicion asociada a el. 
</ul>