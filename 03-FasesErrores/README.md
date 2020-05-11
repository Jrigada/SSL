* Usuario GitHub: jrigada
* Legajo: 170804/1
* Nombre y Apellido: Juan Rigada
* Trabajo: FasesErrores
* Enunciado: Identificar las fases de traducción y errores.
* Entorno utilizado: MinGW + Visual Studio Code

# Fases

1. Comando: gcc -E hello2.c -o hello2.i
   1. Resultado: Se obtuvo un hello.i al solo preprocesar el codigo de hello2.c. En este hello.i el preprocesador tomo como punto de partida el #include y anexo en su lugar los encabezados de la biblioteca <stdio.h> que solicitamos. Ademas de esto nos quito los comentarios reemplazandolos con un espacio. 

2. Comando: gcc -E hello3.c -o hello3.i
   1. Resultado: Se obtuvo hello3.i que es identico a hello3.c con la excepcion de los comentarios creados por command line a la hora de preprocesarlo. Los resultados son iguales ya que no tuvo que incluir ningun codigo de ninguna biblioteca externa ni tampoco tenia comentario alguno para reemplazar por un espacio. 

3. Comando: gcc -S hello3.c -o hello3.s
   1. Resultado: No se pudo generar hello3.s por el siguiente error  "error: expected declaration or statement at end of input" posiblemente asociado con la falta de llaves al finalizar la funcion main. 

4. Comando: gcc -S hello4.c -o hello4.s
   1. Resultado: Se obtuvo esta vez hello4.s siendo este el codigo assembler asociado con nuestro archivo original hello4.c

5. Comando: gcc -c hello4.s -o hello4.o
   1. Resultado: Se obtuvo hello4.o. Este es el codigo binario producto de la traduccion a bajo nivel del codigo .s en assembler. 

6. Comando: gcc -o hello4.exe hello4.c
   1. Resultado: No se genero el ejecutable por un error en donde no se reconoce la referencia prontf.

7. Comando: gcc hello5.c -std=c18 -o hello5.exe
   1. Resultado: Ejecutable hello5.exe que al ejecutarno nos imprime por consola "La respuesta es 4200688"

8. Comando:  gcc hello6.c -std=c18 -o hello6.exe
   1. Resultado: Obtenemos hello6.exe que cuando se ejecuta nos da la respuesta correcta, esto se logro arreglando los argumentos en la definicion de la funcion printf y dentro de la funcion main al agregar como segundo argumento a la variable i que contenia al valor 42. 

9. Comando:  gcc hello7.c -std=c18 -o hello7.exe
   1.  Resultado: Esto tambien nos da hello7.exe que al ejecutarlo tambien nos da la respuesta correcta a pesar de no haber declarado la funcion printf y tampoco haber incluido la biblioteca estandar. Esto creo que es porque C al procesar para generar el exe realiza una declaracion implicita de la funcion printf que resulta funcionar para los dos argumentos que le pasamos.
