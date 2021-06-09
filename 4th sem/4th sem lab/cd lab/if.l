%{
#include<stdio.h>
#include"y.tab.h"
%}
uop ("++"|"--")
%%
"if" return IF;
[0-9]+ return NUM;
[a-zA-Z][a-zA-Z0-9]* {return ID;}
{uop} {return UOP;}
">"|"=="|"<"|"<="|"<"|">="|"!=" { return RE;}
"+"|"-"|"*"|"/"|"%" {return yytext[0];}
"{"|"}"|"("|")"|";"|"=" {return yytext[0];}

. {}
%%
int yywrap(){
return 1;
}
