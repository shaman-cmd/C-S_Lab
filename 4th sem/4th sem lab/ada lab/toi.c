#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt;
void toi(int n,char*src,char*dest,char*temp,FILE *p1){



if(n==0) return ;
cnt++;
toi(n-1,src,temp,dest,p1);
fprintf(p1,"move %d from %s to %s\n",n,src,dest);
toi(n-1,temp,dest,src,p1);
}

void main(){
FILE *p1,*p2;
int i;
system("rm 'toi_w.txt'");
system("rm 'toi_w_cnt.txt'");
p1=fopen("toi_w.txt","a");
p2=fopen("toi_w_cnt.txt","a");
for(i=0;i<=20;i++){

cnt=0;
fprintf(p1,"for number of discs =%d\n",i);
toi(i,"src","dest","temp",p1);
fprintf(p2,"%d\t%d\n",i,cnt);
fprintf(p1,"\n\n");


}
fclose(p1);
fclose(p2);
system("gnuplot>load 'toi_plot.txt'");
}







