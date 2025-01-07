// 4. Write a program which accept number from user and return summation of all its non factors.
// Input: 12
// Output: 50

// Input: 10
// Output: 37

#include<stdio.h>

int SumNonFact(int iNo) {       // TC: O(n)
    int iSum = 0;
    for(int i = 1; i <= iNo ; i++){
        if(iNo % i != 0){
            iSum += i;
        }
    }
    return iSum;
}

int main(){

    int iValue = 0;
    int iRet = 0;

    printf("Enter number: "); 
    scanf("%d",&iValue);

    iRet = SumNonFact(iValue);

    printf("%d", iRet);

    return 0;
}