%{
#include<stdio.h>
#include<stdlib.h>
%}
%token DT ID DIG
%%
start:DT ID';' {printf("valid declaration statement\n");}
|DT ID'='X';' {printf("valid declaration with definiton statement\n");}
|ID'='X';'{printf("valid definition statement\n");}
;
X:ID
|DIG
;
%%
void yyerror(char*msg){
printf("invalid declaration or definition statement\n");
exit(0);
}
int main(){
printf("enter the statement\n");
yyparse();
return 0;
}
