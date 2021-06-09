#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int cnt;
void swap(int* a, int* b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int partition(int a[],int low,int high){
int j=high,i=low-1,pivot=a[high];
while(1){
do{i++;cnt++;}while(a[i]<pivot);
do{j--;cnt++;}while(pivot<a[j]);

if(i>=j) break;
else
swap(&a[i],&a[j]);

}

swap(&a[i],&a[high]);
return i;
}
void quicksort(int a[],int low,int high){

int pi;

if(low<high){

pi=partition(a,low,high);
quicksort(a,low,pi-1);
quicksort(a,pi+1,high);
}
}

void main(){
int n,i,*a;
FILE *p1,*p2;
srand(time(NULL));
system("rm 'quick_b.txt'");
system("rm 'quick_b_cnt.txt'");
system("rm 'quick_avg.txt'");
system("rm 'quick_avg_cnt.txt'");
system("rm 'quick_w.txt'");
system("rm 'quick_w_cnt.txt'");
for(n=2;n<=1024;n*=2){
a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++){
a[i]=rand()%10000;
}
cnt=0;
p1=fopen("quick_avg.txt","a");
p2=fopen("quick_avg_cnt.txt","a");
fprintf(p1,"the first array is \n");
for(i=0;i<n;i++){
fprintf(p1,"%d ",a[i]);
}
fprintf(p1,"\n\n");
fclose(p1);
quicksort(a,0,n-1);
fprintf(p2,"%d\t%d\n",n,cnt);
fclose(p2);



cnt=0;
p1=fopen("quick_w.txt","a");
p2=fopen("quick_w_cnt.txt","a");
fprintf(p1,"the first array is \n");
for(i=0;i<n;i++){
fprintf(p1,"%d ",a[i]);
}
fprintf(p1,"\n\n");
fclose(p1);
quicksort(a,0,n-1);
fprintf(p2,"%d\t%d\n",n,cnt);
fclose(p2);




cnt=0;
for(i=0;i<n;i++){
a[i]=1;
}
p1=fopen("quick_b.txt","a");
p2=fopen("quick_b_cnt.txt","a");
fprintf(p1,"the first array is \n");
for(i=0;i<n;i++){
fprintf(p1,"%d ",a[i]);
}
fprintf(p1,"\n\n");
fclose(p1);
quicksort(a,0,n-1);
fprintf(p2,"%d\t%d\n",n,cnt);
fclose(p2);
}
system("gnuplot>load 'plot.txt'");
}

