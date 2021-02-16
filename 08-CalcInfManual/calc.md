# Gramatica Lexica
| Categoria Lexica | Lexema |
|------------------|--------|
|Operadores        |+,*      |
|Identificadores        |letras o numeros      |
|Caracteres Especiales          |(),{}        |
|Constantes Numericas                  |Naturales en base diez        |
|Fin de entrada                 |    /n    |
|Asignacion                 |    =    |

# Gramatica Sintactica

programa --> inicio \<listaSentencias> fin </br>

\<listaSentencias> --> \<sentencia> </br>

\<sentencia> --> \<asignacion> | \<operacion>

\<asignacion> --> \<identificador> = \<constantesNumericas> 

\<operacion> --> \<constantesNumericas> \<operador> \<constanteNumerica>
