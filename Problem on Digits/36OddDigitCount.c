#include <stdio.h>

int OddDigitCount(int iNo) {
    int iDigit = 0;
    int iCount = 0;

    if(iNo < 0){
        iNo = -iNo;
    }

    while(iNo > 0){
        iDigit = iNo % 10;
        if(iDigit % 2 != 0){
            iCount++;
        }

        iNo = iNo / 10;
    }
    return iCount;
}

int main() {
    int iValue = 0;
    int iRet = 0;

    printf("Enter number: ");
    scanf("%d", &iValue);  

    iRet = OddDigitCount(iValue);
    printf("Number of odd digits are: %d\n", iRet);

    return 0;
}
