#include<stdio.h>

typedef struct{
  int data[100];
  int top;
}stack;
void inti(stack*s){
  s->top=-1;
}
int isfull(stack*s){
  return s->top==100-1;
}
int isempty(stack*s){
  return s->top == -1;
}
void push(stack *s,int val){
  if(isfull(s)){
    printf("overflow");
    return;
  }
  s->data[++(s->top)]=val;
}
int pop(stack *s){
  if(isempty(s)){
    printf("underflow");
    return -1;
  }
  return s->data[(s->top)--];
}
int peek(stack *s){
  if(isempty(s)){
    printf("underflow");
    return -1;
  }
  return s->data[s->top];
}
void display(stack *s){
    if(isempty(s)){
         printf("underflow");
      return;
      }
   for(int i=s->top; i>=0;i--){
       printf("%d ",s->data[i]);
     } 
}
int main(){
  stack s;
  inti(&s);
  push(&s,10);
  push(&s,20);
  push(&s,30);
  push(&s,40);

  display(&s);

  printf("poped:%d",pop(&s));
printf("\nafter pop:");
  display(&s);
  return 0;
}