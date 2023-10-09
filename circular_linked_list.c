#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    
    struct node *next;
};
typedef struct node cll;

cll *head=NULL;

void insert(int e){
    cll *t=head;
    if(head==NULL){
        head=(cll *)malloc(sizeof(cll));
        head->data=e;
        
        head->next=head;
    }
    else{
        while(t->next!=head){
            t=t->next;
        }
        t->next=(cll *)malloc(sizeof(cll));
        t->next->data=e;
        
        t->next->next=head;
    }
}

void disp(){
    printf("\n");
    cll *t=head;
    if(head==NULL){
        printf("list is empty");
    }
    else{
        while(t->next!=head){
            
            printf("%d ->",t->data);
            t=t->next;
        }
        
        printf("%d" ,t->data);
    }
}

void delete(int e){
    cll *t;

    if (head == NULL)
    {
        printf("list is empty");
    }

    else if (head ->data == e && head->next==head)
    {
        head=NULL;
    }

    else if (head->data ==e)
    {
        t=head;
        while (t->next !=head)
        {
            t=t->next;
        }
        t->next=head->next;
        head=head->next;
    }
    else{
        t=head;
        while (t->next !=head && t->next->data==e)
        {
            t=t->next;
        }
        if (t->next==head)
        {
            printf("\nelement not found");
        }
        else{
            t->next=t->next->next;
        }
    }
    
    
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    
    disp();

    delete(10);
    disp();
    
    return 0;
}