%{
#include "y.tab.h"
extern int yyval;
%}

%%
"*" return t_mul;
"+" return t_sum;
"(" return t_leftP;
")" return t_rightP;
[0-9]+ {  yylval=atoi(yytext); 
          return t_constNum; 
       }  
"\n" return terminated;
[a-zA-] return t_id;
%%
int yywrap(void)
{
return 1;
}



