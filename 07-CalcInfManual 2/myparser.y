%{ 
   /* Definition section */
  #include<stdio.h> 
  int isValid=0; 
%} 
  
%token t_constNum 
  
%token t_mul
  
%token t_sum
  
%token t_leftP

%token t_rightP

%token t_id

%token terminated
  
/* Rule Section */
%% 
  
input: INICIO{ 
  
         printf("%s%d\n","El resultado es: ",$$); 
  
         return 0; 
  
        }; 

 INICIO:t_constNum t_sum t_constNum {$$=$1+$3;} 
  
    |t_constNum t_mul t_constNum {$$=$1*$3;} 
  
    |t_leftP t_constNum t_rightP {$$=$2;} 
  
    |t_constNum {$$=$1;} 
  
 ; 

  
%% 
  
//driver code 
void main() 
{ 
   printf("Ingrese una expresion\n"); 
  
   yyparse(); 
   if(isValid==0) 
   printf("%s\n","Expresion valida") 
} 
  
void yyerror() 
{ 
   printf("%s\n","Expresion invalida") 
   isValid=1; 
} 