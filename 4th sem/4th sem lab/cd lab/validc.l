
%{

int valid = 1;
int hasmain = 0;

%}

digit [0-9]
number {digit}+
alpha [a-zA-Z]
newline \n
ws    " "|\n|\t
wss   {ws}*
operator "+"|"-"|"/"|"*"
id1 ({alpha})({alpha}|{digit}|\.)+
id2 ({alpha})({alpha}|{digit}|\_)+

include "include<"({digit}|{alpha})+".h>"
define "define "({id1})" "({digit})+
preprocessor "#"({define}|{include})({newline})

%%

({preprocessor})+({wss}) {printf("%s",yytext);} 

. {valid=0;}


%%

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Usage: %s filename.c\n", argv[0]);
		exit(0);
	}

	yyin = fopen(argv[1], "r");
	yylex();
	if (valid && hasmain) {
		printf("Valid C program!\n");
		
	} else {
		printf("Invalid C program\n");
		printf("hasmain =%d\nvalid=%d\n",hasmain,valid);
	}
	return 0;
}
