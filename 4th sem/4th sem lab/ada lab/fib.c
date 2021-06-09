#include<stdio.h>
#include<stdlib.h>
int fib(int n){

if(n==0)
return 1;
else if(n==1)
return 1;
else{

return fib(n-1)+fib(n-2);
}
}

void main(){
int i;
FILE *p;
system("clear");
system("rm 'fib.txt'");
p=fopen("fib.txt","w");
for(i=0;i<=20;i++){

int n=fib(i);
fprintf(p,"%d\t%d\n",i,n);
}
fclose(p);
}
