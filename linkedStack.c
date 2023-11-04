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
        printf("\nelment poped is : %d",top->data);
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
int menu()
{	
	int ch;
	printf("\n1 - push\t2 - pop\t3 - peek\t4 - exit");
	printf("\nenter your choise :");
	scanf("%d",&ch);
	return ch;
}
void process()
{
	int ch,e;
	for(ch =menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1:
                    printf("enter the value :");
                    scanf("%d",&e);
                    push(e);
					break;
            case 2:pop();break;
			case 3:peek();break;
		}
	}
}

int main() {
    process();
    return 0;
}
