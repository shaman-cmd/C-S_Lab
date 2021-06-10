#include<stdio.h>
#include<stdlib.h>
#define size 10
struct Queue
{int f, r;
   int items[size];

};

typedef struct Queue QUE;
void Insert( QUE *);
void Delete(QUE *);
void Disp(QUE *);


void main()
{

  QUE Q;
  Q.f= 0; Q.r = -1;
  int ch;
  for(;;)
  {
    printf("enter the required operation:\n1:Insert\n2:Delete\n3:Display\n");
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
  int item, j;
  if(Q->r==size-1)
  {
    printf("Queue Full\n");
    return;
  }
  printf("enter item:");
  scanf("%d", &item);


  while(j>=0 && Q->items[j] > item)
  {

    Q->items[j+1] = Q->items[j];
    j--;
 }
 Q->items[++j] = item;
 Q->r++;
 }
 void Delete(QUE *Q)
 {
   if(Q->f>Q->r)
   {
      printf("queue is  Empty\n");
      return;
   }
   printf("deleted item %d\n",Q->items[Q->f++]);
   if(Q->f>Q->r)
   {
     Q->f=0; Q->r=-1;
   }
 }

 void Disp(QUE *Q)
 {  int i;
     if(Q->f>Q->r)
   {
      printf("queue is  Empty\n");
      return;
   }
    for(i=Q->f; i<=Q->r; i++)

      printf("%d  ", Q->items[i]);
 }
