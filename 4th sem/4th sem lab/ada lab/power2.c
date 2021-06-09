#include<stdio.h>
#include<stdlib.h>
int cnt;
int pow2(int n){

if(n==0) return 1;
cnt++;
return pow2(n-1)+pow2(n-1) ;
}
void main(){
int i,pow;
FILE *f1,*f2;
system("rm 'pow2_cnt.txt'");
system("rm 'pow2.txt'");
f1=fopen("pow2.txt","a");
f2=fopen("pow2_cnt.txt","a");
for(i=0;i<=10;i++){
cnt=0;
pow=pow2(i);
fprintf(f1,"%d\t%d\n",i,pow);
fprintf(f2,"%d\t%d\n",i,cnt);
}
fclose(f1);
fclose(f2);
system("gnuplot>load 'plot.txt'");
}
