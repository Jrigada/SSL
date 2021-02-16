%{
#include "y.tab.h"
extern int yyval;
void yyerror(const char *s);
%}

%%
"*" return t_mul;
"+" return t_sum;
"(" return t_leftP;
")" return t_rightP;
[0-9]+ {  yylval=atoi(yytext); 
          return t_constNum; 
       }  
"/" return t_eof;
"=" return t_asig;
[a-zA-] {yylval = yytext[0]; return t_id;}
";" {return yytext[0];}
[ \t\n] ;
. {yyerror("caracter invalido");}
%%
int yywrap(void)
{
return 1;
}



