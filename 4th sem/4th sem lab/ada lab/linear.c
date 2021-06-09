#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt;
int search(int arr[], int n, int x)
{
    int i;
    cnt=0;
    for (i = 0; i < n; i++){
    cnt++;
        if (arr[i] == x)
            return i;
            }
    return -1;
}
void main(){
int i,n,*a;
FILE *f1,*f2;
system("rm linear_avg.txt");
system("rm linear_w.txt");
system("rm linear_b.txt");
system("rm linear_b_cnt.txt");
system("rm linear_w_cnt.txt");
system("rm linear_avg_cnt.txt");
srand(time(NULL));
for(n=10;n<=100;n+=10){
a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)
a[i]=rand()%1000;
f1=fopen("linear_w.txt","a");
fprintf(f1,"iteration	is ");
for(i=0;i<n;i++)
{
fprintf(f1,"%d ",a[i]);
}
fprintf(f1,"\nkey = %d",-1);
fprintf(f1,"\n\n");
search(a,n,-1);
f2=fopen("linear_w_cnt.txt","a");
fprintf(f2,"%d\t",n);
fprintf(f2,"%d\t\n",cnt);
fclose(f1);
fclose(f2);


f1=fopen("linear_b.txt","a");
fprintf(f1,"iteration	is ");
for(i=0;i<n;i++)
{
fprintf(f1,"%d ",a[i]);
}
fprintf(f1,"\nkey = %d",a[0]);
fprintf(f1,"\n\n");
search(a,n,a[0]);
f2=fopen("linear_b_cnt.txt","a");
fprintf(f2,"%d\t",n);
fprintf(f2,"%d\t\n",cnt);
fclose(f1);
fclose(f2);


f1=fopen("linear_avg.txt","a");
fprintf(f1,"iteration	is ");
for(i=0;i<n;i++)
{
fprintf(f1,"%d ",a[i]);
}
fprintf(f1,"\nkey = %d",a[(n-1)/2]);
fprintf(f1,"\n\n");
search(a,n,a[(n-1)/2]);
f2=fopen("linear_avg_cnt.txt","a");
fprintf(f2,"%d\t",n);
fprintf(f2,"%d\n",cnt);
fclose(f1);
fclose(f2);
}
system("gnuplot>load 'lplot.txt'");
}
