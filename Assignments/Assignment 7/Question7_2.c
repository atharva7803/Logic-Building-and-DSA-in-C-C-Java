// 2. Accept amount in US dollar and return its corresponding value in Indian currency. Consider 1$ as 70 rupees.
// Input: 10
// Output: 700

// Input: 3
// Output: 210

// Input: 1200
// Output: 84000

#include<stdio.h>

int DollarToINR(int iNo){      // TC: O(1)
    int iDollar;
    iDollar = iNo * 70;
    return iDollar;
}

// Logic

int main(){

    int iValue = 0, iRet = 0;

    printf("Enter number of USD: "); 
    scanf("%d",&iValue);

    iRet = DollarToINR(iValue);

    printf("Value in INR is: %d", iRet);

    return 0;
}