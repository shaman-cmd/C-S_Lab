%{
#include <stdlib.h>
#include "y.tab.h"
%}
%%
[Aa] return A; 
[Bb] return B;
[\n] return  NL;
. {printf("invalid input");exit(0);}
%%
int yywrap() {
 return 1; 
}
