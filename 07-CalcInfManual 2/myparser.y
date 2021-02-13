%{ 
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h> 
  int isValid=0;
  int symbols[52];
  int symbolVal(char symbol);
  void updateSymbolVal(char symbol, int val);
  void yyerror();
%} 
  
%token t_constNum 
  
%token t_mul
  
%token t_sum
  
%token t_leftP

%token t_rightP

%token t_id

%token t_eof

%token t_asig
  
/* Rule Section */
%% 

INICIO: asignacion ';' {;}
      | expresion t_eof {printf("El resultado es %d\n", $1);}
      | INICIO asignacion ';' {;}
      | INICIO expresion t_eof {printf("El resultado es %d\n", $2);}
      ;


asignacion: t_id t_asig expresion {updateSymbolVal($1,$3);}
            ;

expresion: termino {$$ = $1;}
         |  expresion t_sum expresion {$$ = $1 + $3;}
         |  expresion t_mul expresion {$$ = $1 * $3;}
         ;

termino  : termino t_mul factor {$$ = $1 * $3;}
         | factor
         ;

factor:  t_leftP expresion t_rightP {$$ = $2;}
      |  fundamental;
         ;

fundamental:   t_constNum {$$ = $1;}
         |     t_id     {$$ = symbolVal($1);}
         ;
        

  
%% 
  
//driver code 
void main() { 

   int i;
   for (i=0;i<52;i++) {
      symbols[i]=0;
   } 

   printf("Ingrese una expresion\n"); 
  
   yyparse(); 
   if(isValid==0) {
   printf("%s\n","Expresion valida");
   } 

} 
  
void yyerror() { 
   printf("%s\n","Expresion invalida");

   isValid =1; 
} 

int computeSymbolIndex(char token) {
   int idx = -1;
   if (islower(token)) {
      idx = token - 'a' + 26;
   } else if (isupper(token)) {
      idx = token - 'A';
   }
   return idx;
}

int symbolVal(char symbol)
{
   int bucket = computeSymbolIndex(symbol);
   return symbols[bucket];
}

void updateSymbolVal(char symbol, int val) {
   int bucket = computeSymbolIndex(symbol);
   symbols[bucket] = val;
}