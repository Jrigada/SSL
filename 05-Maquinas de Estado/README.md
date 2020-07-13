* Usuario GitHub: jrigada
* Legajo: 170804/1
* Nombre y Apellido: Juan Rigada
* Trabajo: Maquinas de Estado - Palabras en Lineas
* Entorno utilizado: MinGW + Visual Studio Code

# Arbol de Expresion - Inicializacion de contadores
<img src="contadores.png">

# Arbol de Expresion - Sentencia Condicional 
<img src="if.png">

## Formalizacion de la maquina de estado
 * M = (Q, Σ, q0, F, T) // 
  
   * Q = {Dentro de una palabra, Fuera de una palabra};
   * Σ = Codigo ASCII;
   * q0 = Fuera de una palabra; 
   * F = {Dentro de una palabra, Fuera de una palabra};
   * T = {Dentro de una palabra => Fuera de una palabra,
        Dentro de una palabra => Dentro de una palabra, 
        Fuera de una palabra => Dentro de una palabra, 
        Fuera de una palabra => Fuera de una palabra}

# Implementacion #1 - Switch y Enum

Los cambios introducidos nos permitireron regularizar la version de Kernighan y Ritchie, de esta forma con Switch estamos tratando a todas las transiciones de igual manera y esto permite hoy en dia una automatizacion con algun intereprete como un compilador. <br>
Con la optimizacion adecuada por parte del compilador creo que no habria diferencias de performance entre ambas implementaciones.

# Implementacion #2 - Sentencias <code>goto</code>
goto se sigue usando hoy en dia, su naturaleza se considera menos dañina que lo publicado en 1968. Se siguen utilizando en muchos programas realizados en C que son actualmente mantenidos, se encuentran muy presentes en el kernel de Linux tambien por ejemplo. Se puede utilizar de una forma adecuada teniendo en cuenta sus desventajas y trabajando de acuerdo a ellas, muchas veces su aplicacion puede resultar en un codigo mas facil de leer y mantener. Son especialmente util como una forma de salir de una funcion de una forma mas ordenada y legible asi como tambien para salir de muchos condicionales anidados. 
 
Ademas de C, goto es utilizado actualmente en lenguajes como Golang y C++. 