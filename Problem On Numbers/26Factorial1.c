#include<stdio.h>
#include<stdbool.h>

// Problem Statement: Find Factorial

// Eg: 7 = 1 * 2 * 3 * 4 * 5 = 120

int Factorial(int iNo) {
    int iCnt = 0;
    int iFact = 1;
    for(iCnt = 1; iCnt <= iNo; iCnt++){
        iFact = iFact * iCnt;
    }
    return iFact;
}


int main() {
    int iValue = 0;
    int iRes = 0;

    printf("Enter the number to find its Facotrial: ");
    scanf("%d", &iValue);  
    
    iRes = Factorial(iValue);

    printf("Factorial is: %d\n", iRes);

    return 0;
}