%{
#include<stdio.h>
#include<stdlib.h>
%}
%token ID
%left '(' ')'
%left '+' '-'
%left '*' '/'
%%
start:S {printf("valid expresson result:%d\n",$1);exit(0);}
;
S:S'+'S{$$=$1+$3;}
  
 |S'-'S {$$=$1-$3;}
  
 |S'*'S {$$=$1*$3;}
  
 |S'/'S {$$=$1/$3;}
  
 |'('S')' {$$=$2;}
  
 |ID {$$=$1;}
;
%%
void yyerror(char *s){
printf("invalid expression\n");
exit(0);
}
void main(){
printf("enter the expression\n");
yyparse();
}
