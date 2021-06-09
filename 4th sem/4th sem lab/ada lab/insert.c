#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt;
void insert(int a[],int n){
int b,i,j;
for(i=1;i<n;i++){
b=a[i];
for(j=i-1;j>=0;j--){cnt++;if(a[j]<=b){break;}
a[j+1]=a[j];}
a[j+1]=b;
}
}
void main(){
system("rm 'insert_b.txt'");
system("rm 'insert_b_cnt.txt'");
system("rm 'insert_w.txt'");
system("rm 'insert_w_cnt.txt'");
system("rm 'insert_avg.txt'");
system("rm 'insert_avg_cnt.txt'");
int n,i,*a;
FILE *p1,*p2;
srand(time(NULL));
for(n=10;n<=100;n+=10){
a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++) a[i]=rand()%10000;
cnt=0;
p1=fopen("insert_avg.txt","a");
p2=fopen("insert_avg_cnt.txt","a");
fprintf(p1,"the array is.. \n");
for(i=0;i<n;i++)
fprintf(p1,"%d ",a[i]);
fprintf(p1,"\n\n");
fclose(p1);
insert(a,n);
fprintf(p2,"%d\t%d\n",n,cnt);
fclose(p2);

cnt=0;
p1=fopen("insert_b.txt","a");
p2=fopen("insert_b_cnt.txt","a");
fprintf(p1,"the array is.. \n");
for(i=0;i<n;i++)
fprintf(p1,"%d ",a[i]);
fprintf(p1,"\n\n");
fclose(p1);
insert(a,n);
fprintf(p2,"%d\t%d\n",n,cnt);
fclose(p2);

for(i=0;i<n;i++) a[i]=n+1-i;
cnt=0;
p1=fopen("insert_w.txt","a");
p2=fopen("insert_w_cnt.txt","a");
fprintf(p1,"the array is.. \n");
for(i=0;i<n;i++)
fprintf(p1,"%d ",a[i]);
fprintf(p1,"\n\n");
fclose(p1);
insert(a,n);
fprintf(p2,"%d\t%d\n",n,cnt);
fclose(p2);

free(a);
}
system("gnuplot>load 'plot.txt'");
}
