#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    
    struct node *next;
};

typedef struct node queue;

queue* f =NULL;
queue *r =NULL;

void enqueue(int e){
    queue *t=(queue *)malloc(sizeof(queue));
    t->data=e;
    t->next=NULL;
    
    if(f == NULL){
        f = t;
        r = t;
    }
    
    else{
        r->next=t;
        r=t;
    }
}

void dequeue(){
    if(f == NULL){
        printf("queue is empty");
    }
    else{
        printf("\n%d",f->data);
        f=f->next;
        if(f == NULL){
            r=NULL;
        }
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    
    dequeue();
    dequeue();    
    dequeue();

    return 0;
}
