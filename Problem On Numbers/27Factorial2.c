// Input : 5
// Output : 1 * 2 * 3 * 4 * 5 = 120

#include<stdio.h>

long int Factorial(int iNo)
{
    int iCnt = 0;
    long int iFact = 1;
    //      1           2         3
    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        iFact = iFact * iCnt;   // 4
    }
    return iFact;
}

int main()
{
    int iValue = 0;
    long int iRet = 0;

    printf("Enter number : \n");
    scanf("%d",&iValue);

    iRet = Factorial(iValue);

    printf("Factorial is : %ld\n",iRet);

    return 0;
}