// 1. Write a program which accept number from user and display its multiplication of factors.
// Input: 12
// Output: 144
// (1*2*3*4*6)

// Input: 13
// Output: 1 (1)

// Input: 10
// Output: 10 (1*2*5)

#include<stdio.h>

int MultFact(int iNo){      // TC: O(n)
    int iMul = 1;
    for(int i = 1; i <= iNo/2; i++){
        if(iNo % i == 0){
            iMul *= i;
        }
    }
    return iMul;
}

int main(){

    int iValue = 0;

    int iRet = 0;

    printf("Enter number: "); 
    scanf("%d",&iValue);

    iRet = MultFact(iValue);

    printf("Multiplication of factorsis: %d", iRet);

    return 0;
}