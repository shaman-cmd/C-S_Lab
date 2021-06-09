%{
 #include <stdio.h>
 #include<stdlib.h>
%}
%token A B NL


%%
start:S NL {printf("valid\n");exit(0);}
 ;
S:
 A S B
 |
 ;
%%
void yyerror(char *s) {
 printf("error invalid");
 exit(0);
}
int main(void) {
 yyparse();
 return 0;
}
