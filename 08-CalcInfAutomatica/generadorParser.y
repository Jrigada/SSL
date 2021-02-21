%{ 
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h> 
  #include "parser.h"
  int isValid=0;
  int symbols[52];
  void yyerror();
  #define yylex getNextToken
%} 

%union {
   char caracter;
   int numero;
}
  
%token <numero> t_constNum 
  
%token t_mul
  
%token t_sum
  
%token t_leftpar

%token t_rightpar

%token <caracter> t_id

%token t_eof

%token t_asig

%token t_null

%token t_print

%token t_pyc

%type <numero> ASIGNACION
%type <numero> SUMA
%type <numero> MULTIPLICACION
%type <numero> DATOELEMENTAL
%type <numero> OPERACION

%start OBJETIVO 
  
/* Rule Section */
%% 

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
            
%% 
  
void main() { 

   initTablaDeSimbolos();

   printf("Ingrese una expresion\n"); 
  
   objetivo();

} 

void objetivo() {
   
   if(yyparse()==0) {
      printf("%s\n","Entrada valida");
   } 

}
  
void yyerror() { 
   printf("%s\n","Entrada invalida");
} 

