#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node stack;
stack *top = NULL;

void push(int e){
    stack *t=NULL;
        t=(stack *)malloc(sizeof(stack));
        t->data=e;
        t->next=top;
        top=t;
}

void pop(){
    if(top==NULL){
        printf("empty list");
    }
    else{
        printf("\nelment deleted is : %d",top->data);
        top=top->next;
    }
}


void peek(){
    if(top==NULL){
        printf("empty list");
    }
    else{
        printf("\ntop element is : %d",top->data);
    }
}
int main(){
    push(10);
    push(20);
    push(30);
    
    peek();
    pop();
    peek();
    pop();
    peek();
    return 0;
}