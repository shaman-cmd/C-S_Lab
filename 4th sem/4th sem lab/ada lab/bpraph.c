#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int cnt;
struct Graph{
char* v;
int* E;
};
typedef struct Graph* G;
struct que{
int a[100];
int l;
int r;
};
struct que QUE;

int *mark;

void insert(struct que*q,int i){
if(q->r==99){printf("que is full");return;}
q->a[++q->r]=i;
}

int delete(struct que*q){
if(q->l>q->r){printf("que is empty");return -1;}
int z=q->a[q->l++];
if(q->l>q->r){q->r=-1;q->l=0;}
return z;
}


void bft(G g,int a,int n){
int j,c=a;

insert(&QUE,a);

mark[a]=1;

printf("%c ",g->v[a]);

while(QUE.r!=-1){
 c=QUE.a[QUE.l];
 for(j=0;j<n;j++){
 cnt++;
 if(*(g->E+(c+n*j))==1){

 if(mark[j]==0) {insert(&QUE,j);mark[j]=1;printf("%c ",g->v[j]);}
 }
 }
 delete(&QUE);
}
}


void BFT(G g,int n){
int i;

mark=(int*)calloc(n,sizeof(int));

for(i=0;i<n;i++){

if(mark[i]==0){

bft(g,i,n);
}
}
free(mark);
}

void main(){
QUE.l=0;
QUE.r=-1;
int i,j,n;
int a,b;
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
printf("\nthe breath first traversal:\n");
BFT(&g,n);
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
printf("\nthe breath first traversal:\n");
BFT(&g,n);
printf("\nvertices =%d cnt worst=%d\n",n,cnt);

free(g.E);
printf("\n\n");
}

}

