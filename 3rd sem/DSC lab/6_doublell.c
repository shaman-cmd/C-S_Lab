/*
 * 6_doublell.c
 *
 *  Created on: Dec 9, 2020
 *      Author: nagesh
 */
#include<stdio.h>
#include<stdlib.h>
struct NODE
{
  int info;
  struct NODE *rlink;
  struct NODE *llink;
};
typedef struct NODE *node;
node InsertFront(node);
node InsertRear(node);
node DeleteFront(node);
node DeleteRear(node);
node InsertPos(node);
node DeletePos(node);
node InsertByOrder(node);
node DeleteKey(node);
void Search(node);
node CreateCopy(node);
node Reverse(node);
void Disp(node);
int NE=0;
void main()
{
   int ch;
   node first= NULL, L2=NULL;
   while(1)
   {  printf("\nenter choice:\n1:InsertFront\n2:Disply\n3:InsertRear\n4:DeleteFront\n5:DeleteRear\n6:InsertByposition\n7:DeleteByposition\n8:InsertByOrder\n9:DeleteByKey\n10:Search Key\n11:Create Copy\n12:Reverse\n");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1: first =InsertFront(first); Disp(first); break;
	case 2: Disp(first); break;
	case 3: first = InsertRear(first); Disp(first); break;
	case 4: first = DeleteFront(first); Disp(first); break;
	case 5: first = DeleteRear(first); Disp(first); break;
	case 6: first = InsertPos(first); Disp(first); break;
	case 7: first = DeletePos(first); Disp(first);break;
	case 8: first = InsertByOrder(first); Disp(first);break;
	case 9: first = DeleteKey(first);Disp(first);break;
	case 10: Search(first); break;
	case 11: L2=CreateCopy(first);printf("\ncopy of the list is:");Disp(L2); break;
	case 12: first = Reverse(first);printf("\nReversed list is:");Disp(first); break;
	default:exit(0);
     }
 }
 }

 node InsertFront(node F)
    {
       node NN;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NE++;
       if(F==NULL)
       {NN->llink = NN->rlink = NULL;
        return NN;
       }
       NN->llink = NULL;
       NN->rlink = F;
       F->llink = NN;
       return NN;
    }
node InsertRear(node F)
    {
       node NN,TN;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NN->rlink=NULL;
       NE++;

       if(F==NULL)
       {NN->llink = NULL;
        return NN;
       }

       TN=F;
       while(TN->rlink!=NULL)
       TN=TN->rlink;
       TN->rlink=NN;
       NN->llink = TN;
       return F;
    }


  void Disp(node F)
   {
       if(F==NULL)
       {
	 printf("\nempty\n");
	 return;
       }
       printf("\nList is:\n");
       while(F != NULL)
       {
	 printf("%d ",F->info);
	 F=F->rlink;
       }
  }
  node DeleteFront(node F)
  {  node ND;
     if(F==NULL)
       { printf("empty\n");
	     return  NULL;
       }
     NE--;
     if(F->rlink == NULL)
       {free(F);
        return NULL;
       }

       ND=F;
       printf("\ndeleted %d",ND->info);
       F=F->rlink;
       free(ND);
       F->llink = NULL;
       return F;
  }

 node DeleteRear(node F)
  {  node LN;
     if(F==NULL)
       {
	 printf("empty\n");
	 return  NULL;
       }
       NE--;

       if(F->rlink==NULL)
	{
	  printf("\ndeleted %d",F->info);
	  free(F);
	  return NULL;
	}
       LN=F;
      while(LN->rlink!=NULL)
        LN=LN->rlink;

     printf("\ndeleted %d\n", LN->info);
     LN->llink->rlink = NULL;

     free(LN);
     return F;
  }

node InsertPos(node F)
    {
       node NN,TN;
       int pos,cnt;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NN->rlink = NN->llink =NULL;

       printf("\nenter position from 1 to %d:" ,NE+1);
       scanf("%d",&pos);
       if(pos>=1 && pos<=NE+1)
       {
	    if(pos==1)   // insertfront()
	    {   NE++;
	        if(F==NULL)
               return NN;

               NN->llink = NULL;
               NN->rlink = F;
               F->llink = NN;
               return NN;
	     }
    	 TN=F;
    	 if(pos == NE+1)
    	 {   NE++;
    	     while(TN->rlink != NULL)
    	      TN=TN->rlink;

    	     NN->rlink = NULL;
    	     NN->llink = TN;
    	     TN->rlink = NN;
    	     return F;
    	 }
    	 cnt=1;NE++;
    	 while(cnt<pos)  // cnt<pos-1
    	 {  TN=TN->rlink;
    	    cnt++;
    	 }
    	 NN->rlink=TN;
    	 NN->llink = TN->llink;
    	 TN->llink = NN;
    	 NN->llink->rlink = NN;
           }
       else
       printf("Invalid position Retry:\n");
       return F;
    }

 node DeletePos(node F)
  {  node TN;
     int pos,cnt;
     if(F==NULL)
       {
	 printf("empty\n");
	 return  NULL;
       }
	printf("\nenter position:");
       scanf("%d",&pos);
       if(pos>=1 && pos<=NE)
       {
    	 if(pos==1)
    	 { NE--;
           if(F->rlink == NULL)
           {printf("\ndeleted %d",F->info);
            free(F);
            return NULL;
           }
           node ND=F;
           printf("\ndeleted %d",ND->info);
           F=F->rlink;
           free(ND);
           F->llink = NULL;
           return F;
    	 }
	 TN=F;
	 cnt=1;
	 while(cnt<pos)
	 {  TN=TN->rlink;
	    cnt++;
	 }
	 TN->llink->rlink = TN->rlink;
	 if(pos!=NE)
	 TN->rlink->llink = TN->llink;
 	 printf("\ndeleted:%d ",TN->info);
	 free(TN);
	 NE--;
       }

       else
    	printf("\nInvalid position Retry:");
    return F;
  }

  node InsertByOrder(node F)
    {  node NN,T;
       int info;
       NN = (node)malloc(sizeof(struct NODE));
       printf("enter info field:");
       scanf("%d",&NN->info);
       NN->rlink = NN->llink =NULL;
       NE++;

       if(F==NULL)
     	return NN;
       if(NN->info <F->info)   //insertfront()
    	 {
    	  NN->rlink=F;
    	  F->llink=NN;
    	  return NN;
    	 }
    	T=F;
        while( T->rlink!= NULL && T->rlink->info < NN->info)
           T=T->rlink;

       NN->rlink  = T->rlink;
       NN->llink = T;
       T->rlink = NN;
        if(NN->rlink != NULL)
       NN->rlink->llink = NN;
       return F;
 }


 node DeleteKey(node F)
  {  node TN;
     int info;
     int pos,cnt;
     if(F==NULL)
       {
	 printf("empty\n");
	 return  NULL;
       }
	printf("\nenter key to be deleted:");
       scanf("%d",&info);

       if(F->info==info)
       {
	 TN=F;
	 F=F->rlink;
	 F->llink = NULL;
	 printf("\ndeleted %d", TN->info);
	 free(TN); NE--;
	 return F;
       }

       TN=F;
       while( TN!=NULL && TN->info != info)
        TN=TN->rlink;

       if(TN==NULL)
       {
	printf("\nseraching node doesn't exist");
	return F;
       }
       if(TN->rlink!=NULL)
       TN->rlink->llink = TN->llink;
       TN->llink->rlink = TN->rlink;
       printf("\ndeleted %d ", TN->info);
       free(TN);
       NE--;
       return F;
 }
 void Search(node F)
 {
   node NS;
   int info, pos;
   if(F==NULL)
   {  printf("empty list");
      return ;
   }

   printf("\nenter the key to be searched");
   scanf("%d",&info);
   NS=F;
   pos=1;
   while( NS!=NULL && NS->info != info)
   {
       NS=NS->rlink;
       pos++;
   }
     if(NS==NULL)
      printf("\nSearching node doesn't exist in the list");

     else
      printf("\nnode with info %d exists at position %d", NS->info, pos);
}

node CreateCopy(node F)
{
  node SL=NULL,NN,TN;
  if(F==NULL)
  return NULL;

  while(F!=NULL)
  {
    NN=(node)malloc(sizeof(struct NODE));
    NN->info=F->info; NN->rlink=NULL;
    if(SL==NULL)
    { SL=NN; TN= SL; SL->llink=NULL; }
     else
      {
        TN->rlink=NN;
        NN->llink = TN;
        TN = NN ;
      }
   F=F->rlink;
  }
  return SL;
}
node Reverse(node F)
{
   if(F==NULL)  return NULL;
   if(NE==1) return F;
   node T=F;
   node next = F->rlink;
  while(next!=NULL)
    {
      T->rlink = T->llink;
      T->llink = next;
      T=next;
      next = T->rlink;
    }
    T->rlink = T->llink;
    T->llink = next;

   return T;
}

