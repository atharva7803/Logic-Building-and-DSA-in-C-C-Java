
/* Check whether 4th bit is on or off

    iNo  11     0 0 0 0 1 0 1 1
    Mask (8)    0 0 0 0 1 0 0 0
                ----------------- &
                0 0 0 0 [1] 0 0 0             Result: ON

    
    iNo  20     0 0 0 1 0 1 0 0
    Mask        0 0 0 0 1 0 0 0
                ----------------- &
                0 0 0 0 [0] 0 0 0             Result: Off


*/

#include<stdio.h>
#include<stdbool.h>

bool CheckBit(int iNo){
    unsigned int iMask = 0;
    unsigned int iResult = 0;

    iResult = iNo & iMask;

    if(iResult == iMask){
        return true;
    } else{
        return false;
    }
}

int main(){
    unsigned int iValue = 0;
    bool bRet = false;

    printf("Enter number: \n");
    scanf("%u", &iValue);

    bRet = CheckBit(iValue);

    if(bRet == true){
        printf("4th bit is On\n");
    } else{
        printf("4th bit is Off\n");
    }   

    return 0;
}





