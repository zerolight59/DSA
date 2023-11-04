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
        printf("\ndequed element is %d",f->data);
        f=f->next;
        if(f == NULL){
            r=NULL;
        }
    }
}

int menu()
{	
	int ch;
	printf("\n1 - Enqueue\t2 - Dequeue\t3 - exit");
	printf("\nenter your choise :");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int ch,e;
	for(ch =menu();ch!=3;ch=menu())
	{
		switch(ch)
		{
			case 1:
                    printf("enter the value :");
                    scanf("%d",&e);
                    enqueue(e);
					break;
            case 2:dequeue();break;
			
		}
	}
}

int main() {
    process();
    return 0;
}
