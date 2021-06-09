#include<stdio.h>
#include<stdlib.h>
int cnt;
int visit_cnt,bk;
struct Graph{
char* v;
int* E;
};
int array[10];
int top=-1;
typedef struct Graph* G;
int* mark;
void dft(G g,int a,int n){
int i,pvv;
pvv =array[top];
mark[a]=1;
array[++top]=a;
visit_cnt++;


for(i=0;i<n;i++){
 
 if(*(g->E+(a+i*n))==1){
 if(mark[i]==1&&i!=pvv){bk++;}
 if(mark[i]==0) {dft(g,i,n);}
 }
 
 }
 top--;
 }
void DFT(G g,int n)
{
int i;

mark=(int*)calloc(n,sizeof(int));

for(i=0;i<n;i++){

if(mark[i]==0){

dft(g,i,n);
}
if(i==0&&visit_cnt==n){
printf("connected graph\n");
}
else if(i==0) {
printf("disconnected graph\n");
}

}
free(mark);
}
void main(){
int i,j,n;


struct Graph g;
g.v="abcdefghijklmnop";
while(1){
printf("enter the number of vertices\n");
scanf("%d",&n);
g.E=(int*)calloc(n*n,sizeof(int));
printf("enter the adjancency matrix\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",(g.E+(i+j*n)));
}
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%d ",*(g.E+(i+j*n)));
}
printf("\n");
}
visit_cnt=0;
bk=0;

DFT(&g,n);

printf("\nback edges=%d\n",bk/2);
if(bk==0){printf("acyclic graph\n");}
else {printf("cyclic graph\n");}

free(g.E);
}

}


