/*
 * 8.StaticStackOp.c
 *
 *  Created on: Dec 16, 2020
 *      Author: nagesh
 */

#include<stdio.h>
#include<stdlib.h>
# define MAX_SIZE 20

struct STACK{
    int array[MAX_SIZE];
    int top;
};

typedef struct STACK* STK;

void push(int,STK);
void display(STK);
int pop(STK);
STK S;
void main(){
    int ch,a;

    S=(STK)malloc(sizeof(struct STACK));
    S->top = -1;
    for(;;){
        printf("\n1:Push\n2:Display elements of the stack\n3:Pop \n4:exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("enter the number to be pushed");
            scanf("%d",&a);
            push(a,S); display(S);break;
            case 2: display(S);break;
            case 3: a=pop(S);printf("%d is popped from stack",a); display(S); break;
            case 4: exit(0);
            default: printf("Invalid option");break;
        }
    }
}

int pop(STK s)
 {
    char c;
   if(s->top ==-1)
   printf("stack empty\n");
  else
   c = s->array[s->top];
    s->top--;
 return c;
}

void display(STK s) {
int i;
    printf("the stack is: ");
    for( i=s->top;i>=0;i--)
        printf("%d ", s->array[i]);


}

void push(int c, STK s)
{
  if(s->top ==19)
   printf("stack full\n");
  else{
	  s->top++;
	   s->array[s->top] = c;
  }
}
