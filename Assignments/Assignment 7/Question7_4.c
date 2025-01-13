// 4. Write a program to find odd factorial of given number.

// Input: 5
// Output: 15 (5*3*1)

// Input: -5
// Output: 15(5*3*1)

// Input: 10
// Output: 945 (9*7*5*3*1)

int OddFactorial(int iNo) {      // TC: O(n)
    int iFact = 1;

    if (iNo < 0) {
        iNo = -iNo;
    }
    if (iNo % 2 == 0) {
        iNo--; 
    }

    for (int i = iNo; i > 0; i -= 2) {
        iFact *= i;
    }
    return iFact;
}

int main() {
    int iValue = 0, iRet = 0;

    printf("Enter number: "); 
    scanf("%d", &iValue);

    iRet = OddFactorial(iValue);

    printf("Odd Factorial of number is: %d\n", iRet);

    return 0;
}
