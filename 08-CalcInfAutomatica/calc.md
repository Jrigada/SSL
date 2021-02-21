# Calculadora Automatica

## Flex/Lex

Flex es un generador de Scanners que nos sirven para reconocer patrones lexicos que sean ingresados al programa. Nos permite definir reglas y acciones que seran ejecutadas cuando el patron de una regla sea "matcheado" con la entrada. 

La estructura de un archivo .lex es la siguiente

```
definiciones

%%

reglas

%%

codigo definido por el usuario
```

Las <b>Definiciones</b> nos sirven para incluir archivos, definir funciones o para realizar definiciones que nos simplifiquen luego las reglas por ejemplo para asignar un alias de NUMBER a los digitos [0-9].

Las <b>Reglas</b> son la parte mas importante de este archivo y se componen de patrones y de una serie de acciones asociadas a cada patron. Los patrones se escribiran utilizando expresiones regulares y las acciones seran en C. 

## Yacc/Bison

Bison es un generador de parser automatico en base a una gramatica independiente del contexto. 

La estructura de un archivo .y es la siguiente

```
%{

Prologo

%}

Declaraciones

%%

Reglas gramaticas

%%

Epilogo
```

En el <b>Prologo</b> podemos definir variables y tipos que luego usaremos en las acciones, tambien podemos agregar comandos para el preprocesados e incluir otros archivos de encabezado. 

En las <b>Declaraciones</b> se determinan los nombres de los elementos no terminales y terminales de la gramatica. 

Las <b>Reglas gramaticas</b> definen como contruir cada elemento no terminal mediante reglas usando una notacion similar a BNF que bison pueda comprender. 

El <b> Epilogo </b> nos sirve para cualquier codigo en C que queramos agregar especialmente las definiciones de funciones que hayamos declarado en el prologo. 



La gramatica BNF escrita en un principio del trabajo practico fue especialemente util y muy similar a lo que bison requiere para el escaner, se puede observar las similitudes a continuacion.

### BNF
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

### Reglas Bison
```
OBJETIVO:   PROGRAMA t_eof
            ;
PROGRAMA:   LISTADESENTENCIAS
            ;
LISTADESENTENCIAS:   SENTENCIA 
                  | SENTENCIA LISTADESENTENCIAS
                  ;
SENTENCIA:  ASIGNACION
         |  OPERACION {printf("El resultado es %d\n",$1); return 0;}
         ;
ASIGNACION: t_id t_asig SUMA t_pyc {updateSymbolVal($1,$3);}
          ;
OPERACION: t_print SUMA {$$ = $2;}
         ;
SUMA: MULTIPLICACION {$$=$1;} 
    | MULTIPLICACION t_sum MULTIPLICACION {$$=$1+$3;}
    ;
MULTIPLICACION:   DATOELEMENTAL {$$ = $1;}
               | DATOELEMENTAL t_mul DATOELEMENTAL {$$ = $1 * $3;}
               ;
DATOELEMENTAL: t_constNum {$$ = $1;}
            | t_id {$$ = symbolVal($1);}
            | t_leftpar SUMA t_rightpar {$$ = $2;}
            ;
```

</br>
</br>


# Portabilidad entre iteraciones

Para mantener la cohesion entre los encabezados de la iteracion manual se redefinio la funcion propia de lex ```yylex()``` para que se siga utilizando ```getNextToken()``` como en el scanner manual. Se utilizo redefiniendo el macro YY_DECL de la siguiente manera
```
#undef YY_DECL
#define YY_DECL int getNextToken()
```

Tambien se tuvo que redefinir yylex en el archivo .y para que bison sepa del cambio que se realizo en flex. Esto se hizo de la siguiente forma

```
  #define yylex getNextToken
```