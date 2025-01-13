// 5. Write a program which returns difference between Even factorial and odd factorial of given number.

// Input: 5
// Output: -7  (8-15)

// Input: -5
// Output: -7  (8-15)

// Input: 10
// Output: 2895 (3840-945)


#include <stdio.h>

int Factorial(int n) {      // TC: O(n)
    int fact = 1;
    if (n < 0) {
        n = -n;
    }
    while (n > 0) {
        fact *= n;
        n -= 2; 
    }
    return fact;
}

int FactorialDiff(int iNo) {
    int evenFact = Factorial(iNo);
    int oddFact = Factorial(iNo - 1);
    return evenFact - oddFact;
}

int main() {
    int iValue, iRet;

    printf("Enter number: ");
    scanf("%d", &iValue);

    iRet = FactorialDiff(iValue);

    printf("Factorial difference is %d\n", iRet);

    return 0;
}
