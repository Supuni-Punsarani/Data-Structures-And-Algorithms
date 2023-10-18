#include<stdio.h>
#include<stdlib.h>

#define MAXSTACK 20

typedef int stackEntry;

typedef struct{

    int top;
    stackEntry entry[MAXSTACK];

}stack;

void createStack(stack *s){

     s->top=-1;

}

typedef enum{TRUE,FALSE} Boolean;

Boolean isStackEmpty(const stack *s){

    return s->top==-1;

}

Boolean isStackFull(const stack*s){

    return (s->top==MAXSTACK-1);

}

void push(stackEntry item,stack*s ){

    if(!isStackFull(s)){
        s->entry[++s->top]=item;
    }
    else{
        printf("stack is full.\n");
        exit(1);
    }
}

void pop(stackEntry *item,stack *s){

     if(!isStackEmpty(s)){
        *item=s->entry[s->top--];
     }
     else{
        printf("stack is empty.\n");
        exit(1);
     }
}

int main(){

      stack myStack;
      createStack(&myStack);
      printf("Is stack empty? %s\n", isStackEmpty(&myStack) ? "Yes" : "No");
      push(5, &myStack);
      push(10, &myStack);
      printf("Is stack full? %s\n", isStackFull(&myStack) ? "Yes" : "No");
      stackEntry poppedItem;
      pop(&poppedItem, &myStack);
      printf("Popped item: %d\n", poppedItem);
      return 0;


}

