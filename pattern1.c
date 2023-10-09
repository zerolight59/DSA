
#include <stdio.h>

int main()
{
    int i,j,k;
    int size =5;
    for(i=0;i<size;i++){
        
        for(j=0;j<i;j++){
            printf(" ");
        }
        for(k=0;k<(size-i)*2-1;k++){
            printf("*");
        }
        printf("\n");
        
    }
    
    for(i=2;i<=size;i++){
        
        for(j=size;j>i;j--){
            printf(" ");
        }
        for(k=0;k<i*2-1;k++){
            printf("*");
        }
        printf("\n");
        
    }
    
    return 0;
}
