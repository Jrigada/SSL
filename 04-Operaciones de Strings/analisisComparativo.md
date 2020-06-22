# Analisis Comparativo

## C
**El tipo de dato String no forma parte del lenguaje de C** 
<p>La utilizacion de Strings como tipo de dato se realiza meramente con una cadena de caracteres es decir un arreglo de 
tipo de datos "Char". La cantidad de nodos que tendra el arreglo debera predeterminarse ya que su largo se determina al compilar siendo este de asignacion estatica.
<p>Los arreglos de caracteres siempre tienen en su ultima posicion al caracter nulo "\0" que permite que C determine donde 
termina ese String. El uso de estos arreglos en C se realiza por medio de un puntero</p>

<p>Asi se definiria una String:</p>
<code>char stringTest[5] = "hola";</code>
<p></p>

<p>Y en memoria esto se veria asi:</p>
<code> h|o|l|a|\0</code>
<p></p>
<p>En la biblioteca estandar de C lo que si podemos encontrar bajo el encabezado "string.h" es ciertas funciones que permitiran 
un mejor manejo de estos arreglos de caracteres, de otra forma seria mas tedioso operaciones sencillas como saber el largo de un String. </p>

<p>Los arreglos en C no son first class citizens, es decir que no pueden ser utilizados con todas las operaciones que otros tipos de datos si por ejemplo el tipo de dato Int. A la hora de utilizar una String como parametro a una funcion por ejemplo se utiliza el puntero hacia la primer posicion de este arreglo y no el arreglo en si. </p>
<p>El tipo de dato String es mutable, es decir puedo cambiar el contenido de cada posicion del arreglo de memoria creado anteriormente siempre y cuando al momento de definirlo no lo determine como una constante <code>const</code></p>
<p>
</p>

## Python
**El tipo de dato String forma parte del lenguaje**
<p>Las string en python forman parte del lenguaje por defecto, en memoria tambien se utilizan como una lista de caracteres. Estas empiezan y terminan tanto con un par de comillas como un par de comillas dobles.<p>
<p> No posee caracter final nulo como en C</p>
<p>Asi se definiria una String en python:</p>
<code> stringTest = "hola" </code>
<p></p>
<p>Asi se almacenaria en memoria:</p>
<code> h|o|l|a </code>
<p></p>
<p>La variable creada en la definicion de la string consiste en el puntero a la posicion de memoria que contiene las posiciones contiguas de memoria que la forman</p>
<p>Las Strings en python son inmutables, esto quiere decir que para modificarla de cualquier forma con un metodo por ejemplo, python nos retorna una nueva cadena de caracteres con la modificacion que se requiera.</p>
<p>Las strings en python si son un first class citizen a diferencia del lenguaje C. Estas si soportan todas las operaciones que el resto de los tipos de datos soportan como es el caso de asignacion o de ser retornada por una funcion.</p>
