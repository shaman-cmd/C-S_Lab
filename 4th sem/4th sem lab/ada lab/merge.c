#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt;
int join(int a[], int le[], int ri[], 
        int l, int m, int r) 
{ 
    int i; 
    for (i = 0; i <= m - l; i++) 
        a[i] = le[i]; 
  
    for (int j = 0; j < r - m; j++) 
        a[i + j] = ri[j]; 
} 
int rearrange(int a[], int le[], int ri[], 
        int l, int m, int r) 
{ 
    for (int i = 0; i <= m - l; i++) 
        le[i] = a[i * 2]; 
  
    for (int i = 0; i < r - m; i++) 
        ri[i] = a[i * 2 + 1]; 
} 
  
int worstcaseinput(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l + (r - l) / 2; 
  
       
        int le[m - l + 1], ri[r - m];
        rearrange(arr, le, ri, l, m, r); 
  
        
        worstcaseinput(le, l, m); 
       worstcaseinput(ri, m + 1, r); 
  
       
        join(arr, le, ri, l, m, r); 
    } 
} 
void merge(int B[],int C[],int A[],int mid,int n){
int i,j,k;
for(i=0,j=0,k=0;i<mid&&j<n-mid;){
cnt++;
if(B[i]<C[j])
A[k++]=B[i++];
else
A[k++]=C[j++];
}
if(i==mid)
while(j<n-mid) A[k++]=C[j++];
else
while(i<mid) A[k++]=B[i++];
}
void mergesort(int A[],int n){
if(n>1){
int mid = n/2,i,j,B[mid],C[n-mid];
for(i=0,j=0;i<mid;)
B[j++]=A[i++];
for(j=0;i<n;)
C[j++]=A[i++];
mergesort(B,mid);
mergesort(C,n-mid);
merge(B,C,A,mid,n);
}
}

void main(){
system("rm 'merge_avg.txt'");
system("rm 'merge_avg_cnt.txt'");
system("rm 'merge_b.txt'");
system("rm 'merge_b_cnt.txt'");
system("rm 'merge_w.txt'");
system("rm 'merge_w_cnt.txt'");
srand(time(NULL));
int *a,i,n;
FILE *p1,*p2;
for(n=4;n<=1024;n*=2){
cnt=0;
a=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++) a[i]=rand()%1000;
p1=fopen("merge_avg.txt","a");
p2=fopen("merge_avg_cnt.txt","a");
fprintf(p1,"\nthe array is \n");
for(i=0;i<n;i++) fprintf(p1,"%d ",a[i]);
fclose(p1);
mergesort(a,n);
fprintf(p2,"%d\t%d\n",n,cnt);
fclose(p2);


cnt=0;
p1=fopen("merge_b.txt","a");
p2=fopen("merge_b_cnt.txt","a");
fprintf(p1,"\nthe array is \n");
for(i=0;i<n;i++) fprintf(p1,"%d ",a[i]);
fclose(p1);
mergesort(a,n);
fprintf(p2,"%d\t%d\n",n,cnt);
fclose(p2);


cnt=0;
worstcaseinput(a,0,n-1);
p1=fopen("merge_w.txt","a");
p2=fopen("merge_w_cnt.txt","a");
fprintf(p1,"\nthe array is \n");
for(i=0;i<n;i++) fprintf(p1,"%d ",a[i]);
fclose(p1);
mergesort(a,n);
fprintf(p2,"%d\t%d\n",n,cnt);
fclose(p2);

}
system("gnuplot>load 'plot.txt'");
}



