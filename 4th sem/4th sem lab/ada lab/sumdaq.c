#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;
 
 int sum(int* a,int low, int high){
 
     
     int mid;
      if(low>high) return 0;
      if(low==high) return a[low];
      mid=(low+high)/2;
      count++;
      return sum(a,low,mid)+sum(a,mid+1,high);
 }
 
 
 int main(){
     int *a,i,j,n,low=0,high;
     FILE *ptr1,*ptr2;
     system("rm sumofarray.txt");
     system("rm sumofarray_count.txt");
     srand(time(NULL));
     for(n=30;n<=400;n+=10){
         high=n-1;
         count=0;
         a=(int*)malloc(n*sizeof(int));
           for(i=0;i<n;i++)
            a[i]=rand()%100;
         
           ptr1=fopen("sumofarray.txt","a");
           ptr2=fopen("sumofarray_count.txt","a");
           fprintf(ptr1,"\nelements are:\n");
           
           for(i=0;i<n;i++)
             fprintf(ptr1,"%d ",a[i]);
           
           j=sum(a,low,high);
           fprintf(ptr1,"\nsum =%d\n",j);
           fclose(ptr1);
           fprintf(ptr2,"%d\t%d\n",n,count);
           fclose(ptr2);
         
   }
system("gnuplot>plot 'plot.txt'");
}
