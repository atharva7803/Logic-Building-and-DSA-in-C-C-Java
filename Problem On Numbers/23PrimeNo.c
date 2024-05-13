#include<stdio.h>
#include<stdbool.h>

// Problem Statement: Check number is prime or not.

// Eg: 7 = factors : 1 and 7 
// Eg: 19 = factors : 1 and 19 

bool CheckPrime(int iNo) {
    int iCnt = 0;

    // Updator
    if(iNo < 0){
        iNo = -iNo;
    }

    for(int iCnt = 2; iCnt <= iNo/2 ; iCnt++){      
        if(iNo % iCnt == 0) {
            return false;
            break;
        }    
    }
    return true;
}


int main() {
    int iValue = 0;
    bool bRes = false;

    printf("Enter the number to find if its a Prime no: ");
    scanf("%d", &iValue);  
    
    bRes = CheckPrime(iValue);

    if(bRes == true){
        printf("%d is prime no\n", iValue);
    }
    else{
        printf("%d is not a prime no\n", iValue);
    }

    return 0;
}