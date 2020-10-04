%{
#include "scanner.h"
%}

%%
"*" return t_mul;
"+" return t_sum;
"(" return t_leftP;
")" return t_rightP;
[1-9] return t_constNum;
[a-zA-] return t_id;
.	printf("error");
%%
int yywrap(void)
{
return 1;
}



