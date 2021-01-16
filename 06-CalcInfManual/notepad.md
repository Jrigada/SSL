Gramatica lexica Calculadora
<token> -> uno de <identificador> <constante> <adicion> <multiplicacion> <asignacion> <leftpar> <rightpar> <palabraReservada>
<identificador> ->    <letra> {<letra>}
<letra> -> una de a-z A-Z
<constante> -> <digito> {<digito>}
<digito> -> uno de 0-9
<adicion> -> +
<multiplicacion> -> *
<asignacion> -> =
<leftpar> -> (
<rightpar> -> ) 
<palabraReservada> -> una de terminar //puede haber mas

Gramatica sintactica Calculadora
<objetivo> -> <programa> /
<programa> -> <listaSentencias>
<listaSentencias> -> <sentencia> {; <sentencia>}
<sentencia> -> ID ASIGNACION CONSTANTE;| <expresión> OPERADOR <expresión>;
<expresion> -> ID | CONSTANTE |
PARENIZQUIERDO <expresión> PARENDERECHO
<operador> -> uno de adicion o uno de multiplicacion
