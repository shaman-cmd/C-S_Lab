#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int bin_cnt;


void bubblesort(int arr[], int n) 
{
  int swapped=0;
  int tmp, i,j;
 

  for(i=0;i<n-1;i++){
  for(j=0;j<n-i-1;j++){
  
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

int binarys(int A[],int n,int key){
int l,r,mid;
l=0;
r=n-1;
bin_cnt=0;

while(l<=r){
bin_cnt++;
mid=(l+r)/2;
if(A[mid]==key)
return mid;
else if(key<A[mid])
r=mid-1;
else
l=mid+1;
}



}
int main(){
int i=0,n,*p,pos;
FILE *f1,*f2;

system("rm binary_b.txt");
system("rm binary_b_cnt.txt");
system("rm binary_avg.txt");
system("rm binary_avg_cnt.txt");
system("rm binary_w.txt");
system("rm binary_w_cnt.txt");
srand(time(NULL));

for(n=100;n<=1000;n+=100){
p=(int*)malloc(n*sizeof(int));

for(i=0;i<n;i++){
p[i]=rand()%10000;
}
bubblesort(p,n);
f1=fopen("binary_b.txt","a");
pos=binarys(p,n,p[(n-1)/2]);
fprintf(f1,"the array is \n");
for(i=0;i<n;i++){
fprintf(f1,"%d ",p[i]);
}
fprintf(f1,"key = %d\n\n",p[(n-1)/2]);
fclose(f1);
f2=fopen("binary_b_cnt.txt","a");
fprintf(f2,"%d\t%d\n",n,bin_cnt);
fclose(f2);



f1=fopen("binary_w.txt","a");
pos=binarys(p,n,-1);
fprintf(f1,"the array is \n");
for(i=0;i<n;i++){
fprintf(f1,"%d ",p[i]);
}
fprintf(f1,"key = %d\n\n",-1);

fclose(f1);
f2=fopen("binary_w_cnt.txt","a");
fprintf(f2,"%d\t%d\n",n,bin_cnt);
fclose(f2);


f1=fopen("binary_avg.txt","a");
pos=binarys(p,n,p[n/4]);
fprintf(f1,"the array is \n");
for(i=0;i<n;i++){
fprintf(f1,"%d ",p[i]);
}
fprintf(f1,"key = %d\n\n",p[n/4]);
fclose(f1);
f2=fopen("binary_avg_cnt.txt","a");
fprintf(f2,"%d\t%d\n",n,bin_cnt);
fclose(f2);

free(p);
}




system("gnuplot>load 'bplot.txt'");
        
 

}

     












