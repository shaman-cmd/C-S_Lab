#include<stdio.h>
#include<stdlib.h>
#define size 10
struct Queue
{
   int items[size];
   int f, r;
   int cnt;
};

typedef struct Queue QUE;
void Insert( QUE *);
void Delete(QUE *);
void Disp(QUE *);


void main()
{
  int ch;
  QUE Q;
  Q.f= 0;
  Q.r = -1;
  Q.cnt=0;

  for(;;)
  {
    printf("enter operation required to perform on queue:\n1:Insert\n2:Delete\n3:Display\n");
    scanf("%d", &ch);
    switch(ch)
    {
       case 1: Insert(&Q);
                Disp(&Q);
                break;
       case 2:  Delete(&Q);
                Disp(&Q);
                break;
       case 3:   Disp(&Q);
               break;
       default:  exit(0);
    }
  }
}
void Insert(QUE *Q)
{
  int item;
  if(Q->cnt==size)
  {
    printf("Queue Full\n");
    return;
  }
  printf("enter item:");
  scanf("%d", &item);
  Q->r= (Q->r+1)%size ;
  Q->items[Q->r] = item;
  Q->cnt++;
 }
 void Delete(QUE *Q)
 {
   if(Q->cnt==0)
   {
      printf("Queue is  Empty\n");
      return;
   }
   printf("deleted item %d\n",Q->items[Q->f]);
   Q->f= (Q->f+1)%size;
   Q->cnt--;

 }

 void Disp(QUE *Q)
 {  int i,j;
     if(Q->cnt==0)
      {
      printf("Queue is  Empty\n");
      return;
      }
     j=Q->f;
    for(i=1; i<=Q->cnt; i++)
      {
      printf("%d  ", Q->items[j]);
      j=(j+1)%size;
      }

 }

