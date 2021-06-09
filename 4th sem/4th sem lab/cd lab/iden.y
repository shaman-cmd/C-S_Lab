%{
 #include <stdio.h>
 #include<stdlib.h>

%}
%token A B NL


%%
start:
 A S B NL {printf("valid\n");exit(0);}
 ;
S:
 A S
 |
 ;
%%
void yyerror(char *s) {
 printf("error invalid");
 exit(0);
}
int main(void) {
 printf("enter the string\n");
 yyparse();
 return 0;
} 
