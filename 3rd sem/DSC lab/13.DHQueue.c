/*
 * 13.DHQueue.c
 *
 *  Created on: Dec 26, 2020
 *      Author: nagesh
 */
#include<stdio.h>
#include<stdlib.h>
#define size 10
struct Queue
{
   int items[size];
   int f, r;
};

typedef struct Queue QUE;
void InsertRear( QUE *);
void DeleteFront(QUE *);
void InsertFront( QUE *);
void DeleteRear(QUE *);
void Disp(QUE *);


void main()
{
  int ch;
  QUE Q;
  Q.f= 0; Q.r = -1;

  for(;;)
  {
    printf("enter choice:\n1:InsertFront\n2:DeleteRear\n3:Insertfront\n4:DeleteRear\n5:Display\n");
    scanf("%d", &ch);
    switch(ch)
    {
       case 1: InsertRear(&Q);
             Disp(&Q);
             break;
       case 2:  DeleteFront(&Q);
               Disp(&Q);
               break;
	case 3: InsertFront(&Q);
	      Disp(&Q);
	      break;
       case 4:  DeleteRear(&Q);
              Disp(&Q);
               break;
       case 5:   Disp(&Q);
                 break;
       default:  exit(0);
    }
    }
  }
void InsertRear(QUE *Q)
{
  int item;
  if(Q->r==size-1)
  {
    printf("queue is  Full,insertion not possible\n");
    return;
  }
  printf("enter item:");
  scanf("%d", &item);

  Q->items[++Q->r] = item;
 }
 void DeleteFront(QUE *Q)
 {
   if(Q->f>Q->r)
   {
      printf("Queue is  Empty\n");
      return;
   }
   printf("deleted item :%d\n",Q->items[Q->f++]);
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

void InsertFront(QUE *Q)
{
  int item;
  if(Q->f==0 && Q->r!=-1)
  {
    printf("front insertion is not possible,no space at front\n");
    return;
  }
  printf("enter item:");
  scanf("%d", &item);
  if(Q->f==0 && Q->r==-1)
  {

  Q->items[++Q->r] = item;
  return;
 }
  Q->items[--Q->f] = item;
 }

 void DeleteRear(QUE *Q)
 {
   if(Q->f>Q->r)
   {
      printf("queue is  Empty\n");
      return;
   }
   printf("deleted:%d\n",Q->items[Q->r--]);
   if(Q->f>Q->r)
   {
     Q->f=0; Q->r=-1;
   }
 }
