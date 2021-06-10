/*
 * time.c
 *
 *  Created on: Nov 23, 2020
 *      Author: nagesh
 */
#include <stdio.h>
struct TIME
{
  int hr, min, sec;
};
typedef struct  TIME Time;


   void read(Time *T){
       printf("enter the time t1 hours:minutes:seconds:\n");
       scanf("%d%d%d",&T->hr,&T->min, &T->sec);
   }
   void disp(Time *T){
       printf("%d:%d:%d\n",T->hr,T->min, T->sec);
   }
   void update(Time *T){
       T->sec++;
       if(T->sec>=60){
            T->min = T->min + T->sec/60;
           T->sec=T->sec%60;

           if(T->min>=60){
               T->hr += T->min/60;
               T->min=T->min%60;

               if(T->hr>=24){
                    T->hr=T->min=T->sec=0;

               }
         }
     }


   }

   void add(Time *t1, Time *t2, Time*t3){
         t3->hr= t1->hr+t2->hr;
  t3->min = t1->min+t2->min;
  t3->sec= t1->sec+t2->sec;
   if(t3->sec>=60){
            t3->min = t3->min + t3->sec/60;
           t3->sec=t3->sec%60;}
           if(t3->min>=60){
               t3->hr += t3->min/60;
               t3->min=t3->min%60;}
               if(t3->hr>=24){
                    t3->hr=t3->hr%24;
               }


   }
   void main()
{
   int choice;
   Time T1, T2, T3, T4;
   while(1){
      printf("enter choice:\n1:Read\n2:update\n3:Add\n4:exit\n");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1: printf("enter T1\n");
	       read(&T1);
	       printf("enter T2\n");
	       read(&T2);
	       printf("\nT1 = ");
	       disp(&T1);
	       printf("\nT 2=");
	       disp(&T2);
	       break;
	       case 2: read(&T3) ;
		update(&T3);
		disp(&T3);break;
		  case 3: add(&T1,&T2,&T4); disp(&T4); break;
          default:printf("invalid choice\n");break;

      }
     if(choice==4){
     break;}
   }
}


