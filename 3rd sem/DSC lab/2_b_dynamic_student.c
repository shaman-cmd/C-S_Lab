/*
 * student.c
 *
 *  Created on: Nov 19, 2020
 *      Author: nagesh
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student
{
  int regno;
  char name[10];
  float marks[3];
float avgmarks;
};

void Read(struct Student *);
void Disp(struct Student*);
void avgmarks(struct Student*);
int size, NE=0;
 int main()
{
  struct Student *S;

  int choice;

  printf("enter size:");
  scanf("%d",&size);
  S = (struct Student *) malloc(size* sizeof(struct Student));
  for(;;)
  {
   printf("enter choice\n1:Read\n2:Display\n3:average of 2 marks\n4:exit\n");
  scanf("%d", &choice);
  switch(choice)
  {

    case 1: Read(S); Disp(S); break;
    case 2: Disp(S);  break;
    case 3: avgmarks(S); break;

    default:exit(0);

  }
  }

return 0;
}



void Read(struct Student *S)
{
  int i, N;
   printf("enter number of students information you want to read\n");
   scanf("%d", &N);
  for(i=0;i<N;i++)
  {
    printf("enter Regno , name, all 3 marks of  student %d\n:",i+1);
   scanf("%d%s%f%f%f", &(S+i)->regno, (S+i)->name, &(S+i)->marks[0],&(S+i)->marks[1],&(S+i)->marks[2]);
  }
  NE=N;
}



  void Disp(struct Student *S)

{     int i;
  printf("\nReg      Name    subject1  subject2  subject3\n");
  for(i=0;i<NE;i++)
  {
   printf("%d   %s   %f  %f  %f\n", (S+i)->regno, (S+i)->name,(S+i)->marks[0],(S+i)->marks[1],(S+i)->marks[2]);

  }
}

   void avgmarks(struct Student *S){
int i;
float b1=-1.0,b2=-1.0;
if(NE==0){
printf("array empty\n");
return;
}
printf( "\nregno   name     avgof best 2 marks\n");

for(i=0;i<NE;i++){
b1=-1.0;
b2=-1.0;
int j;
for(j=0;j<3;j++){
if((S+i)->marks[j]>=b1){
b2=b1;
b1=(S+i)->marks[j];
}
if((S+i)->marks[j]>=b2&&(S+i)->marks[j]!=b1){
b2=(S+i)->marks[j];
}
}
float avg=(b1+b2)/2.0;
printf("%d   %s   %f\n",(S+i)->regno, (S+i)->name,avg);
}
   }


