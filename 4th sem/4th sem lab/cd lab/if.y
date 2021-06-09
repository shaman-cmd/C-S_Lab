%{
#include<stdio.h>
#include<stdlib.h>
int cnt=0;
extern FILE *yyin;
%}
%left '(' ')'
%left '+' '-'
%left '*' '/'
%left '{' '}'
%left '='
%left '%'
%left ';'
%token IF RE ID NUM UOP
%%
Start: S {printf("valid ifcondition statement \n and number of levels=%d\n",cnt);exit(0);}
;
S:if_exp'{'AE S AE'}'
|if_exp'{'AE'}'
;
if_exp:IF'('EX')' {cnt++;}
;
AE:ID'='E';'AE 
|AID';' AE
|
;
EX:E RE E
;
X:ID 
|NUM
;
E:E '-' E
|'('E')'
|E '+' E 
|E '*' E
|E '/' E
|E '%' E
|AID
;
AID:ID UOP
|UOP ID
|X
;
%%
void yyerror(char *s){
printf("invalid if expression\n");
exit(0);
}
void main(){
   yyin = fopen("input.txt", "r");
    if(!yyin) {
        printf("File not found!\n");
        return;
    }

yyparse();
}
