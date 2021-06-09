#include<stdio.h>
#include<stdlib.h>
int cnt;
int bin(int n){
if(n<=1) return 1;
cnt++;
return  1+bin(n/2);
}
void main(){
int i;
FILE *p1,*p2;
system("rm 'bindec.txt'");
system("rm 'bindec_cnt.txt'");
p1=fopen("bindec.txt","w");
p2=fopen("bindec_cnt.txt","w");
for(i=1;i<=1024;i*=2){
cnt=0;
fprintf(p1,"%d\t%d\n",i,bin(i));
fprintf(p2,"%d\t%d\n",i,cnt);
}
fclose(p1);
fclose(p2);
system("gnuplot> load 'plot.txt'");
}

