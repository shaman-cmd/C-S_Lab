#include <stdio.h>
#include<stdlib.h>
int main(){
int i,j,k,n,a[10][10],indeg[10],flag[10],count=0,cnt=0,stk[10],top=-1;
printf("Enter the no of vertices:\n");
scanf("%d",&n);
printf("Enter the adjacency matrix:\n");

for(i=0;i<n;i++){
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}

for(i=0;i<n;i++){
indeg[i]=0;
flag[i]=0;
}

for(i=0;i<n;i++){
for(j=0;j<n;j++){
cnt++;
if(a[j][i]==1)
indeg[i]++;
}
cnt++;
if(indeg[i]==0){stk[++top]=i;}
}

printf("\nThe topological order is:");

while(top!=-1){
k=stk[top--];
printf("%d ",k+1);
flag[k]=1;
count++;
for(i=0;i<n;i++){
cnt++;
if(a[k][i]==1){indeg[i]--;a[k][i]=0;cnt++;if(indeg[i]==0){stk[++top]=i;}}
}
}
if(count!=n){printf("\nno source to remove error!\n");exit(0);}

printf("\ncount=%d",cnt);

}
