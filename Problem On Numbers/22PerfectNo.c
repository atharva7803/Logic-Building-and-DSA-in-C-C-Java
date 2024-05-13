#include<stdio.h>
#include<stdbool.h>

// Problem Statement: Accept number as no , search all its factors. Perform addition of all the factors. If addtion is same as no then Display as no is perfect no otherwise display as no in not perfect no

// Perfect no: addition of its factors is equal to the number itself

// Eg: 6 = factors addition: 1 + 2 + 3 = 6

bool CheckPerfect(int iNo) {
    int iCnt = 0;
    int iSum = 0;


    // Filter
    if(iNo < 0){
        printf("Please enter positive numbers only\n");
        return false;
    }

    for(int iCnt = 1; iCnt <= iNo/2 ; iCnt++){      
        if(iNo % iCnt == 0) {
            iSum = iSum + iCnt;
        }    
    }
    if(iSum == iNo){
        return true;              
    }
    else{
        return false;
    }
}


int main() {
    int iValue = 0;
    bool bRes = false;

    printf("Enter the number to find if its a Prfect no: ");
    scanf("%d", &iValue);  
    
    bRes = CheckPerfect(iValue);

    if(bRes == true){
        printf("%d is perfect no\n", iValue);
    }
    else{
        printf("%d is not a perfect no\n", iValue);
    }

    return 0;
}