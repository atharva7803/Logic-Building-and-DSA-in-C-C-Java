#include<stdio.h>
#include<stdbool.h>


bool CheckDivisible(int iNo){
    if(iNo % 4 == 0)  
        return true;
    else
        return false;
}

int main(){

    int iValue = 0;
    bool bResult = false;

    printf("Enter the number : \n");
    scanf("%d",&iValue);

    bResult = CheckDivisible(iValue);

    if(bResult == true){
        printf("%d is divisible by 4\n", iValue);
    }   
    else{
        printf("%d is not divisible by 4\n", iValue);
    }

    return 0;
}