%{
#include "scanner.h"
%}

%%
"*" return t_mul;
"+" return t_sum;
"(" return t_leftP;
")" return t_rightP;
[1-9] return t_constNum;
"\n" return terminated;
[a-zA-] return t_id;
.	return null;
%%
int yywrap(void)
{
return 1;
}



