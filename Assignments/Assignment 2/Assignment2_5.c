// 5. Accept number from user and check whether number is even or odd.

#include<stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

BOOL ChkEven (int iNo){
    if(iNo % 2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    int iValue = 0;

    BOOL bRet = FALSE;

    printf("Enter number: "); 
    scanf("%d",&iValue);

    bRet = ChkEven(iValue);

    if(bRet == 1){
        printf("%d is even number\n", iValue);
    }
    else{
        printf("%d is odd number\n", iValue);
    }

    return 0;
}