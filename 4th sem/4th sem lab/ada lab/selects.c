#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int  cnt;
void selection(int a[],int n){
int i,j,temp,low;
for(i=0;i<n-1;i++){
low=i;
for(j=i+1;j<n;j++){
cnt++;
if(a[low]>a[j]){
low=j;
}
}
temp=a[i];
a[i]=a[low];
a[low]=temp;
}
}
void main(){
system("rm 'select.txt'");
system("rm 'select_cnt.txt'");
FILE *f1,*f2;
int *a,i,n;
srand(time(NULL));
f1=fopen("select.txt","a");
f2=fopen("select_cnt.txt","a");
for(n=0;n<=30;n++){
cnt=0;
a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++){
a[i]=rand()%1000;
}
fprintf(f1,"\nthe 1st array is\n");
for(i=0;i<10;i++){
fprintf(f1,"%d ",a[i]);
}
selection(a,n);
fprintf(f2,"%d\t%d\n",n,cnt);
}
fclose(f1);
fclose(f2);
system("gnuplot>load 'plot.txt'");
}


