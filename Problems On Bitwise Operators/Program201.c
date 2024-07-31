#include<stdio.h>

int Count1(int iNo){
    int iDigit = 0;
    int iCnt = 0;
    while(iNo != 0){
        iDigit = iNo % 2;
        if(iDigit == 1){        // Other Approach: iSum += iDigit (it will add 1 and 0 and will give count of 1)
            iCnt++;
        }
        iNo = iNo / 2;

    }
    return iCnt;
}

int main(){
    int iValue = 0, iRet = 0;

    printf("Enter number: \n");
    scanf("%d", &iValue);

    iRet = Count1(iValue);

    printf("Count of 1 is: %d\n",iRet);

    return 0;
}








