%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"
%}
%%
"int"|"float"|"char"|"long" {return DT;}
[0-9]+ {return DIG;}
[A-Za-z][A-Za-z0-9]* {return ID;}
";"|"=" {return yytext[0];}
. {}
%%
int yywrap(){
return 1;
} 
