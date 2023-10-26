#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define size 50

char ar[size];
int top=-1;
char * infix;
char *postfix;

void push(char e){
    if(top+1!=size){
        ar[++top]=e;
    }
}
char pop(){
    return ar[top--];
}

int pre(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}
int isop(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

char *intopost(){
    postfix =  (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0,j=0;
    while (infix[i]!='\0')
    {
        if(!isop(infix[i])){
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else{
            if (pre(infix[i])>pre(ar[top]))
            {
                push(infix[i]);
                i++;
            }
            else{
                postfix[j]=pop();
                j++;
            }
        }

    }
        while (top!=-1)
        {
            postfix[j]=pop();
            j++;
        }
    postfix[j]='\0';
    return postfix;
 }

char perform(char a,char b,char c){
    if (c=='+')
    {
        return b+a;
    }
    else if (c=='-')
    {
        return b-a;
    }
    else if (c=='*')
    {
        return b*a;
    }
    else{
        return b/a;
    }
}

void evl(){
    char op1,op2;
    char  temp;
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (!isop(postfix[i]))
        {
            push(postfix[i]);
        }
        else
        {
            op1=pop();
            op2=pop();
            temp=perform(op1,op2,postfix[i]);
            push(temp);
        }
    }
    
    printf("total =%d",ar[top]);
}



int main(){
    infix = "2+3*3";
    printf("postfix is %s\n", intopost(infix));
    evl();
    return 0;
}