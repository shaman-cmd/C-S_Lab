#include<stdio.h>
#include<stdlib.h>
int fac(int n){
if(n==0)
return 1;
else
return n*fac(n-1);
}
void main(){
int i;
for(i=0;i<10;i++){



