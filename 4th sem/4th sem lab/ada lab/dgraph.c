#include<stdio.h>
#include<stdlib.h>
int cnt;
struct Graph{
char* v;
int* E;
};
int array[4];
int top=-1;
typedef struct Graph* G;
int* mark;



void dft(G g,int a,int n){
int i;

mark[a]=1;

printf("%c ",g->v[a]);

for(i=0;i<n;i++){
 cnt++;
 if(*(g->E+(a+i*n))==1){
 
 if(mark[i]==0) {dft(g,i,n);}
 }
 
 }
 top--;
}
 
 
 
 
 
void DFT(G g,int n)
{
int i;

mark=(int*)calloc(n,sizeof(int));
printf("\n");
for(i=0;i<n;i++){

if(mark[i]==0)
dft(g,i,n);


}
free(mark);
}



void main(){
int i,j,n;



struct Graph g;
g.v="abcdef";
for(n=3;n<=5;n++){


g.E=(int*)calloc(n*n,sizeof(int));


cnt=0;
for(i=0;i<n-1;i++){   
*(g.E+(i+(i+1)*n))=1;
*(g.E+((i+1)+i*n))=1;
}
printf("for sparse garph\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++) {printf("%d ",*(g.E+(i+j*n)));}
printf("\n");
}
printf("\nthe depth first traversal:\n");
DFT(&g,n);
printf("\nvertices =%d cnt best=%d\n",n,cnt);



cnt=0;
for(i=0;i<4;i++){ 
for(j=0;j<4;j++){
if(i!=j){*(g.E+(j+i*n))=1;*(g.E+(i+j*n))=1;}
}
}
printf("for compelte garph\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++) {printf("%d ",*(g.E+(i+j*n)));}
printf("\n");
}
printf("\nthe depth first traversal:\n");
DFT(&g,n);
printf("\nvertices =%d cnt worst=%d\n",n,cnt);

free(g.E);
printf("\n\n");
}

}

