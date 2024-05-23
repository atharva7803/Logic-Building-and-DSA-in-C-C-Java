#include <stdio.h>

int DigitCount(int iNo) {
    int iDigit = 0;
    int iCount = 0;

    if(iNo < 0){
        iNo = -iNo;
    }

    while(iNo > 0){
        iDigit = iNo % 10;
        if(iDigit > 5){
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

    iRet = DigitCount(iValue);
    printf("Number digits greater then 5 are:  %d\n", iRet);

    return 0;
}
