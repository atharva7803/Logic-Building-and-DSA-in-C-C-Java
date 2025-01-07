// 5. Write a program which accept number from user and return difference between summation of all its factors and  non factors.
// Input: 12
// Output: -34 (16-50)

// Input: 10
// Output: -29 (8-37)

#include<stdio.h>

int FactDiff(int iNo) {     // TC: O(n)
    int iSumF = 0;
    int iSumN = 0;
    for(int i = 1; i <= iNo ; i++){
        if(iNo % i == 0){
            iSumF += i;
        }
        else{
            iSumN += i;
        }
    }
    return iSumF - iSumN;
}

int main(){

    int iValue = 0;
    int iRet = 0;

    printf("Enter number: "); 
    scanf("%d", &iValue);

    iRet = FactDiff(iValue);

    printf("%d", iRet);

    return 0;
}