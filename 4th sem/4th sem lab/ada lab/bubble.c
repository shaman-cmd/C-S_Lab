#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt;
void bubblesort(int arr[], int n) 
{
  int swapped=0;
  int tmp, i,j;
 

  for(i=0;i<n-1;i++){
  for(j=0;j<n-i-1;j++){
  cnt++;
  if(arr[j]>arr[j+1]){
  tmp=arr[j];
  arr[j]=arr[j+1];
  arr[j+1]=tmp;
  swapped=1;
  }
  }
  if(swapped==0)break;
  }
  
}



void main(){
system("rm bubble_w.txt");
system("rm bubble_w_cnt.txt");
system("rm bubble_b.txt");
system("rm bubble_b_cnt.txt");
FILE *f1,*f2;
srand(time(NULL));
int n,i,*p;
for(n=10;n<=100;n+=10)
{
cnt=0;
p=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)
p[i]=rand()%1000;
f1=fopen("bubble_w.txt","a");
fprintf(f1,"average or worst case\n");
fprintf(f1,"the first iteration is \n");
for(i=0;i<n;i++)
fprintf(f1,"%d ",p[i]);
fprintf(f1,"\n\n");
fclose(f1);
bubblesort(p,n);
f2=fopen("bubble_w_cnt.txt","a");
fprintf(f2,"%d\t%d\n",n,cnt);
fclose(f2);

cnt=0;
f1=fopen("bubble_b.txt","a");
fprintf(f1,"the best cases \n");
fprintf(f1,"the first iteration is \n");
for(i=0;i<n;i++)
fprintf(f1,"%d ",p[i]);
fprintf(f1,"\n\n");
fclose(f1);
bubblesort(p,n);
f2=fopen("bubble_b_cnt.txt","a");
fprintf(f2,"%d\t%d\n",n,cnt);
fclose(f2);
free(p);
}
system("gnuplot>load 'plot.txt'");
}













