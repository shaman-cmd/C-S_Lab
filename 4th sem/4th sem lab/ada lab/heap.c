#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt1,cnt2;
void heapbottomup(int a[],int n){
int i,j,k,h,v;
for(i=n/2;i>0;i--){
k=i;
v=a[k];
h=0;
while(h==0&&2*k<=n){
j=2*k;
cnt2=cnt2+2;
if(j<n){if(a[j]<a[j+1]) {j++;}}
if(v>=a[j]){ h=1;}
else {a[k]=a[j];k=j;}
}
a[k]=v;
}
}

void heapsort(int a[],int n){

int cnt=0,j,last=n,h,k,v;
heapbottomup(a,n);
while(cnt<n-1){
v=a[last];
a[last]=a[1];
last--;
k=1;
h=0;
while(h==0&&2*k<=last){
j=2*k;
cnt1=cnt1+2;
if(j<last){if(a[j]<a[j+1]) {j=j+1;}}
if(v>=a[j]) h=1;
else {a[k]=a[j];k=j;}
}
a[k]=v;
cnt++;
}
}
int main(){
int i,n,j,*a;
FILE *p1,*p2;
system("rm 'heap_avg.txt'");
system("rm 'heap_avg_cnt.txt'");
system("rm 'heap_w.txt'");
system("rm 'heap_w_cnt.txt'");
system("rm 'heap_b.txt'");
system("rm 'heap_b_cnt.txt'");
srand(time(NULL));

for(n=2;n<=1024;n=n*2){
a=(int*)malloc((n+2)*sizeof(int));
a[0]=-1;
cnt1=0;
cnt2=0;
p1=fopen("heap_avg.txt","a");
p2=fopen("heap_avg_cnt.txt","a");
for(i=1;i<(n+2);i++){a[i]=rand()%10000;}
fprintf(p1,"\n\nthe array is \n");
for(i=1;i<(n+2);i++) fprintf(p1,"%d ",a[i]);
heapsort(a,n+1);
if(cnt1>=cnt2){

fprintf(p2,"%d\t%d\n",n+1,cnt1);}
else{

fprintf(p2,"%d\t%d\n",n+1,cnt2);}
fclose(p2);
fclose(p1);


cnt1=0;
cnt2=0;
p1=fopen("heap_w.txt","a");
p2=fopen("heap_w_cnt.txt","a");
fprintf(p1,"\n\nthe array is \n");
for(i=1;i<(n+2);i++) fprintf(p1,"%d ",a[i]);
heapsort(a,n+1);
if(cnt1>=cnt2){

fprintf(p2,"%d\t%d\n",n+1,cnt1);}
else{

fprintf(p2,"%d\t%d\n",n+1,cnt2);}
fclose(p2);
fclose(p1);



cnt1=0;
cnt2=0;
p1=fopen("heap_b.txt","a");
p2=fopen("heap_b_cnt.txt","a");
for(i=1;i<(n+2);i++){a[i]=(n+2)-i;}
fprintf(p1,"\n\nthe array is \n");
for(i=1;i<(n+2);i++) fprintf(p1,"%d ",a[i]);
heapsort(a,n+1);
if(cnt1>=cnt2){

fprintf(p2,"%d\t%d\n",n+1,cnt1);}
else{

fprintf(p2,"%d\t%d\n",n+1,cnt2);}
fclose(p2);
fclose(p1);


free(a);

}
system("gnuplot>load 'plot.txt'");
}

