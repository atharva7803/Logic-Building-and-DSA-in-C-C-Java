// 4. Write a program which accept range from user and return addition of all even numbers in between that range. (Range should contain positive numbers only)

// Input: 23 35
// Output:  108

// Input: 10 18
// Output: 70

// Input: -10 2
// Output: Invalid range

// Input:90 18
// Output: Invalid range

#include<stdio.h>

int RangeSumEven(int iStart, int iEnd){
    if(iStart > iEnd || iStart < 0 || iEnd < 0){
        return -1;
    }
    int iSum = 0;
    while(iStart <= iEnd){
        if(iStart % 2 == 0){
            iSum += iStart;
        }
        iStart++;
    }
    return iSum;
}

int main(){
    int iValue1 = 0, iValue2 = 0, iRet = 0;

    printf("Enter starting point: "); 
    scanf("%d", &iValue1);

    printf("Enter ending point: "); 
    scanf("%d", &iValue2);

    iRet = RangeSumEven(iValue1, iValue2);

    if (iRet == -1) {
        printf("Invalid Range!");
    } else {
        printf("Addition is %d", iRet);
    }

    return 0;
}