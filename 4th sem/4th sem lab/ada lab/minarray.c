#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt;
int minele(int a[],int n){
if (n == 1) return a[0];
cnt++;
int b=minele(a,n-1);
if(a[n-1]>b) return b;
else return a[n-1];
}
int main(){
system("rm 'minele.txt'");
system("rm 'minele_cnt.txt'");
int n,i,*a,min;
FILE *f1,*f2;
srand(time(NULL));
for(n=1;n<=10;n++){
f1=fopen("minele.txt","a");
f2=fopen("minele_cnt.txt","a");
cnt=0;
a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++){
a[i]=rand()%1000;
}
min=minele(a,n);
fprintf(f1,"the array is\n");
for(i=0;i<n;i++){
fprintf(f1,"%d ",a[i]);
}
fprintf(f1,"\nn=%d\tmin=%d\n\n",n,min);
fprintf(f2,"%d\t%d\n",n,cnt);
free(a);
fclose(f1);
fclose(f2);
}
system("gnuplot>load 'plot.txt'");
}

