%{
#include "scanner.h"
void yyerror(const char *s);
%}

%%
"*" return t_mul;
"+" {return t_sum;}
"(" return t_leftpar;
")" return t_rightpar;
[0-9]+ {yylval.numero=atoi(yytext); 
          return t_constNum; 
       }  
"/" return t_eof;
"=" return t_asig;
"@" {return t_print;}
[a-zA-] {yylval.caracter = yytext[0]; return t_id;}
";" return t_pyc;
[ \t\n] ;
. {yyerror("caracter invalido");}
%%
int yywrap(void)
{
return 1;
}



