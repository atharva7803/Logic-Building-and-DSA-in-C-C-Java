// 3. Write a program to find even factorial of given number.

// Input: 5
// Output: 8 (4*2)

// Input: -5
// Output: 8 (4*2)

// Input: 10
// Output: 3840 (10*8*6*42)

#include<stdio.h>

int EvenFactorial(int iNo){      // TC: O(n)
    int iFact = 1;
    if(iNo < 0){
        iNo = -iNo;
    }
    if (iNo % 2 != 0) {
        iNo--; 
    }
    for (int i = iNo; i > 0; i -= 2) {
        iFact *= i;
    }
    return iFact;
} 

int main(){

    int IValue = 0, IRet = 0;

    printf("Enter number: "); 
    scanf("%d",&IValue);

    IRet = EvenFactorial(IValue);

    printf("Even Factorial of number is: %d", IRet);

    return 0;

}
